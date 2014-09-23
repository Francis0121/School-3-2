/*
 * chat_server.c
 * Written by SW. YOON
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFSIZE 100

void * clnt_connection(void *arg);
void send_message(char * message, int len);
void error_handling(char *message);

int clnt_number=0; // 현재 client가 몇개있는지 들고 있는 것
int clnt_socks[10]; // 최대 10명의 클라이언트를 받아 들이겠다.
pthread_mutex_t mutx;   // 하나의 프로그램안에서 thread를 이용해서 공유(여기서는 clnt_connection 에서만 쓰지만) 한다고 할때 
                  // 외부의 전역 변수를 읽거나 쓴다고 하면 그럴 때 서로간의 접근을 확인해 주어야 한다.(clnt_connection)
                  // 내부의 지역 변수는 이름은 같지만 다른공간에서 사용된다.(clnt_connection)
                  // 운영체제 주머니 역할 ( 교통정리의 개념 ) - This is 공유 자원(Global Variable, printf, file)
                  // Semaphore, mutex

int main(int argc, char **argv) // (현실 Ex) 은행의 Ticket Machine
{
  int serv_sock;
  int clnt_sock;
  // Server(현실 Ex : Ticket Machine : 창구에 가기전까지 기다리는 상황[1차적 관리 대상, 초기배정을 위한] [Unique 함])
  // Client(창구직원과 서로 1:1 Matching 된 상황[배정이 끝난후 대화 창구] [각 Client 여러개])
  struct sockaddr_in serv_addr;   // Socket 가지고 있는것 Ip, Port Information 를 관리해주는 구조체 변수 (Server) 나 자신의 주소
  struct sockaddr_in clnt_addr; // (Client) 손님의 주소
  int clnt_addr_size; // 구조체 변수의 사이즈
  pthread_t thread; // Thread 변수
  
  if(argc!=2) { // Argument  2개가 필요
    printf("Usage : %s <port>\n", argv[0]);
    exit(1);
  }// 1 - program name, 2 - port number(Chatting server를 실행할시 prompt에 작성하는 port number)
  
  // ~ 공유 자원에 대해서, 초기화를 시켜준다.
  if(pthread_mutex_init(&mutx, NULL))// pthread_mutex_init : mutex 초기화 함수 
    error_handling("mutex init error");
  
  // ~ Server Socket 초기화 시작
  serv_sock=socket(PF_INET, SOCK_STREAM, 0);// 1: PF_INET 인터넷 형태의 socket을만들고 싶다. 
                                 // 2: SOCK_STREAM TCP/IP 를 다룰 수 있는 것을 만들겠다.
 
  // ~ Address 초기화
  memset(&serv_addr, 0, sizeof(serv_addr)); // 구조체 변수에 주소값을 할당 과정 시작
  serv_addr.sin_family=AF_INET; // 이것은 인터넷 주소이다.
  serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); // Server Internet 주소 할당x
  serv_addr.sin_port=htons(atoi(argv[1])); // 문자 9000 -> 숫자로 변환 2byte로 대입
  
  // ~ 초기화된 Socket을 연결
  if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
    error_handling("bind() error");
  
  if(listen(serv_sock, 5)==-1) // 손님을 5명까지만 받겠다. (은행의 창구 5개) (???????? 왜 10이아니고 5지 )
    error_handling("listen() error"); // 아 전담 직원과 연결하기 전에 요청할 수 있는 수를 5명 -> 따라서 10이 아니어도 됨
  // ~ Server socket 초기화 끝

  while(1){
    clnt_addr_size=sizeof(clnt_addr);
    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);// 전담 창구를 배정받는 순서 새로운 손님한명을 받는다.
                                                            // 2 : 전담 직원이 새로운 client Information (IP 주소, Port, Name etc)

	// 이 부분에서 최대의 크기가 인원이 10인데 여기서 10이상의 사람이 접속하게되면
	// 에러가 발생하도록 에러 핸들링을 해주어야 한다.
	pthread_mutex_lock(&mutx); // ~ Mutex  이용 자물쇠 잠금 임시 대기줄(한명만 들어가게된다) critical Section이라 부름 (OS..)
    clnt_socks[clnt_number++]=clnt_sock; // 신규 고객에 대한 접속자 수를 +1
    pthread_mutex_unlock(&mutx);

    pthread_create(&thread, NULL, clnt_connection, (void*)clnt_sock);   
    printf("새로운 연결, 클라이언트 IP : %s \n", inet_ntoa(clnt_addr.sin_addr)); 
  }
 
  return 0;
}

// 각각의 thread로 실행되기 때문에 지역변수는 각 thread별소 생성되며 공유되지 않는다.
void * clnt_connection(void *arg)// thread로 돌아가는중!
{
  int clnt_sock= (int)arg;// socket id 값, Socket 변수로 재해석 하도록함.  
  int str_len=0;
  char message[BUFSIZE];
  int i;

  // str_len 몇 byte를 읽었는지 실제 byte 수. , message byte에 읽은 데이터
  while( (str_len=read(clnt_sock, message, sizeof(message))) != 0) // socket에서 발생하는 message만 read 하겠다. 3 : buffer의 사이즈를 알려줌(최대 100byte)만 읽기 가능
    send_message(message, str_len); // 나머지 사람드렝게 BroadCast Send Message

  // ~ while 이 false가 될 때 == 0 인경우 상대방 클라이언트가 죽은경우
  // ~ 최종 정리 시작 - Mutex로 보호를 해줘야함 clnt_socks 가 global 변수 이기 때문에
  pthread_mutex_lock(&mutx);
  for(i=0; i<clnt_number; i++){   /* 클라이언트 연결 종료 시 */
    if(clnt_sock == clnt_socks[i]){
      for( ; i<clnt_number-1; i++)
        clnt_socks[i]=clnt_socks[i+1];
      break;
    }
  }
  clnt_number--;
  pthread_mutex_unlock(&mutx);

  close(clnt_sock);
  // ~ 최종 정리 끝
  return 0;
}

// ~ broadCast할때 호출되는것이며 모든 client 하나하나에 대해서 같은 메시지를 보내야 한다.
void send_message(char * message, int len)
{
  int i;
  pthread_mutex_lock(&mutx);  
  for(i=0; i<clnt_number; i++)
    write(clnt_socks[i], message, len); //하나하나에 대해서 write를 해주고   
                              //보호가 필요하다. broadCast가 끝날때까지 참아라
  pthread_mutex_unlock(&mutx);
}

void error_handling(char *message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}