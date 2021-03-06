#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

void *do_chat(void *);
void *do_paint(void *);
int pushClient(int,int);
int popClient(int);
pthread_t thread;
pthread_mutex_t mutex;

#define MAX_CLIENT 10
#define CHATDATA 1024



#define CLIENT_WHITEBOARD_PORT 9930

#define INVALID_SOCK -1

int list_c[MAX_CLIENT];
int list_client_whiteBoard[MAX_CLIENT];
char greeting[]="Welcome to chatting room\n";
char CODE200[]="Sorry No More Connect";



main(int argc, char *argv[])
{
	int c_socket, s_socket, c_whiteBoard_socket ;
	struct sockaddr_in s_addr, c_addr ;
	int len;

	int i, j, n;

	int res;

	if(argc < 2)
	{
		printf("usage: %s port_number\n", argv[0]);
		exit(-1);
	}

	if(pthread_mutex_init(&mutex, NULL) != 0)
	{
		printf("Can not create mutex\n");
		return -1;
	}

	s_socket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(atoi(argv[1]));

	if(bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1)
	{
		printf("Can not Bind\n");
		return -1;
	}

	if(listen(s_socket, MAX_CLIENT) == -1)
	{
		printf("listen Fail\n");
		return -1;
	}

	for(i = 0; i < MAX_CLIENT; i++){
		list_c[i] = INVALID_SOCK;
		list_client_whiteBoard[i] = INVALID_SOCK;
	}

	while(1)
	{
		len = sizeof(c_addr);
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);
		printf("c_socket accept success\n");
		c_whiteBoard_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);
		printf("c_whiteBoard_socket accept sucess\n");
		res = pushClient(c_socket,c_whiteBoard_socket);
		if(res < 0)
		{
			write(c_socket, CODE200, strlen(CODE200));
			close(c_socket);
		}
		else
		{
			write(c_socket, greeting, strlen(greeting));
			//write(c_whiteBoard_socket, greeting, strlen(greeting));
			pthread_create(&thread, NULL, do_chat, (void *)c_socket);
			pthread_create(&thread, NULL, do_paint, (void *)c_whiteBoard_socket);

		}
	}
}

void *do_chat(void *arg)
{
	int c_socket = (int)arg;
	char chatData[CHATDATA];
	int i, n;
	while(1)
	{
		memset(chatData, 0, sizeof(chatData));
		if((n = read(c_socket, chatData, sizeof(chatData))) > 0)
		{
			for(i = 0; i < MAX_CLIENT; i++)
				if(list_c[i] != INVALID_SOCK && list_c[i] != c_socket)
					write(list_c[i], chatData, n);
		}
		else
		{
				popClient(c_socket);
				break;
		}
	}
}
void *do_paint(void *arg)
{
	int c_socket = (int)arg;
	char chatData[CHATDATA];
	int i, n;
	while(1)
	{
		memset(chatData, 0, sizeof(chatData));
		if((n = read(c_socket, chatData, sizeof(chatData))) > 0)
		{
			//printf("recieved %dBytes\n",n);
			//	write(1, chatData, n);
			for(i = 0; i < MAX_CLIENT; i++)
				if(list_client_whiteBoard[i] != INVALID_SOCK && list_client_whiteBoard[i] != c_socket)
					write(list_client_whiteBoard[i], chatData, n);
		}
		else
		{
				popClient(c_socket);
				break;
		}
	}
}
int pushClient(int c_socket, int c_whiteBoard_socket)
{
	int i;

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex);
		if(list_c[i] == INVALID_SOCK)
		{
			list_c[i] = c_socket;
			list_client_whiteBoard[i] = c_whiteBoard_socket;
			pthread_mutex_unlock(&mutex);
			return i;
		}
		pthread_mutex_unlock(&mutex);
	}

	if(i == MAX_CLIENT)
		return -1;
}

int popClient(int s)
{
	int i;

	close(s);

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex);
		if(s == list_c[i])
		{
			list_c[i] = INVALID_SOCK;
			list_client_whiteBoard[i] = INVALID_SOCK;
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}