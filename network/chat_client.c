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
  
  if(argc!=4){// ~ 자기자신의 이름
	// 서버 IP, 서버 Port, 나의 이름
    printf("Usage : %s <IP> <port> <name>\n", argv[0]);
    exit(1);
  }
  // 마지막 파라미터 값을 사용해서 내부 변수에 저장 "홍길동
  sprintf(name, "[%s]", argv[3]);

  // 인터넷에 TCP/IP 연결을한다.
  sock=socket(PF_INET, SOCK_STREAM, 0);
  if(sock==-1)
	  error_handling("socket() error");

  // 서버쪽 연결하기위해 구조체 저장
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
  serv_addr.sin_port=htons(atoi(argv[2]));
  
  // ~ Client connect 만 하면된다.
  if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
    error_handling("connect() error");
  
  // 고정적으로 2개의 thread를 만드는데
  // 하나는 보내는쪽, 하나는 받는 쪽 (두개다 socket 변수값을 알고있는다.)
  // 4번쨰 변수에 socket번호를 넘겨준다.
  // 함수는 독립적으로 실행
  pthread_create(&snd_thread, NULL, send_message, (void*)sock); 
  pthread_create(&rcv_thread, NULL, recv_message, (void*)sock);

  // Thread가 스스로 죽을 때 까지 wait 기다린다. Main Thread( stop ) 하고 기다림
  // 두개의 thread가 죽게될때에 main thread가 죽게된다
  pthread_join(snd_thread, &thread_result);
  pthread_join(rcv_thread, &thread_result);
 
  // 안될수도 있는 상황이 있다면 해줘야 되지만, 지금현재것에서는 필요없을듯?이라고 말함.
  close(sock);  
  return 0;
}

void * send_message(void *arg) /* 메시지 전송 쓰레드 실행 함수 */
{
   int sock = (int)arg;
   char name_message[NAMESIZE+BUFSIZE];
   while(1) {
	   // BUFFSIZE를 꽉채우거나 enter값이 입력될때까지 기다린다.
      fgets(message, BUFSIZE, stdin); // 키보드에서 입력을 받는다. standard input(file으로 하는 키보드로 하겠다.)
	  if(!strcmp(message,"q\n")) {  /* 'q' 입력 시 종료 */
         close(sock);// socket이 죽는다.
         exit(0);// return을 해도되고 exit(0)해도된다. thread가 죽는다.
      }
      sprintf(name_message,"%s %s", name, message); // 문자열을 합성한다.     
      write(sock, name_message, strlen(name_message));// 몇개의 바이트를 입력했는지 보내기위해 strlen()을 해서 문자열의 개수를 보내 준것이다.
   }
}

void * recv_message(void *arg) /* 메시지 수신 쓰레드 실행 함수 */
{
  int sock = (int)arg;
  char name_message[NAMESIZE+BUFSIZE];
  int str_len;
  while(1){
    str_len = read(sock, name_message, NAMESIZE+BUFSIZE-1);//  send_message의 close(sock)을 하는 순간 receive하던 함수의 쪽에서 sock이 사라짐으로 -1을 리턴하고 죽는다.
	if(str_len==-1) return 1;
    name_message[str_len]=0;
    fputs(name_message, stdout);//모니터화면에 서버가 보내준 채팅문자열을 출력해준다.
  }
}

void error_handling(char *message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}