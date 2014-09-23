/*
 * chat_client.c
 * Written by SW. YOON
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFSIZE 100
#define NAMESIZE 20

void * send_message(void *arg);
void * recv_message(void *arg);
void error_handling(char *message);

char name[NAMESIZE]="[Default]";
char message[BUFSIZE];

int main(int argc, char **argv)
{
  int sock;
  struct sockaddr_in serv_addr;
  pthread_t snd_thread, rcv_thread;
  void * thread_result;
  
  if(argc!=4){// ~ �ڱ��ڽ��� �̸�
	// ���� IP, ���� Port, ���� �̸�
    printf("Usage : %s <IP> <port> <name>\n", argv[0]);
    exit(1);
  }
  // ������ �Ķ���� ���� ����ؼ� ���� ������ ���� "ȫ�浿
  sprintf(name, "[%s]", argv[3]);

  // ���ͳݿ� TCP/IP �������Ѵ�.
  sock=socket(PF_INET, SOCK_STREAM, 0);
  if(sock==-1)
	  error_handling("socket() error");

  // ������ �����ϱ����� ����ü ����
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
  serv_addr.sin_port=htons(atoi(argv[2]));
  
  // ~ Client connect �� �ϸ�ȴ�.
  if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
    error_handling("connect() error");
  
  // ���������� 2���� thread�� ����µ�
  // �ϳ��� ��������, �ϳ��� �޴� �� (�ΰ��� socket �������� �˰��ִ´�.)
  // 4���� ������ socket��ȣ�� �Ѱ��ش�.
  // �Լ��� ���������� ����
  pthread_create(&snd_thread, NULL, send_message, (void*)sock); 
  pthread_create(&rcv_thread, NULL, recv_message, (void*)sock);

  // Thread�� ������ ���� �� ���� wait ��ٸ���. Main Thread( stop ) �ϰ� ��ٸ�
  // �ΰ��� thread�� �װԵɶ��� main thread�� �װԵȴ�
  pthread_join(snd_thread, &thread_result);
  pthread_join(rcv_thread, &thread_result);
 
  // �ȵɼ��� �ִ� ��Ȳ�� �ִٸ� ����� ������, ��������Ϳ����� �ʿ������?�̶�� ����.
  close(sock);  
  return 0;
}

void * send_message(void *arg) /* �޽��� ���� ������ ���� �Լ� */
{
   int sock = (int)arg;
   char name_message[NAMESIZE+BUFSIZE];
   while(1) {
	   // BUFFSIZE�� ��ä��ų� enter���� �Էµɶ����� ��ٸ���.
      fgets(message, BUFSIZE, stdin); // Ű���忡�� �Է��� �޴´�. standard input(file���� �ϴ� Ű����� �ϰڴ�.)
	  if(!strcmp(message,"q\n")) {  /* 'q' �Է� �� ���� */
         close(sock);// socket�� �״´�.
         exit(0);// return�� �ص��ǰ� exit(0)�ص��ȴ�. thread�� �״´�.
      }
      sprintf(name_message,"%s %s", name, message); // ���ڿ��� �ռ��Ѵ�.     
      write(sock, name_message, strlen(name_message));// ��� ����Ʈ�� �Է��ߴ��� ���������� strlen()�� �ؼ� ���ڿ��� ������ ���� �ذ��̴�.
   }
}

void * recv_message(void *arg) /* �޽��� ���� ������ ���� �Լ� */
{
  int sock = (int)arg;
  char name_message[NAMESIZE+BUFSIZE];
  int str_len;
  while(1){
    str_len = read(sock, name_message, NAMESIZE+BUFSIZE-1);//  send_message�� close(sock)�� �ϴ� ���� receive�ϴ� �Լ��� �ʿ��� sock�� ��������� -1�� �����ϰ� �״´�.
	if(str_len==-1) return 1;
    name_message[str_len]=0;
    fputs(name_message, stdout);//�����ȭ�鿡 ������ ������ ä�ù��ڿ��� ������ش�.
  }
}

void error_handling(char *message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}