#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

void *do_image(void *);
void *do_chat(void *);
void *do_cam(void *);
int pushClient(int);
int popClient(int);
int pushClientImage(int);
int popClientImage(int);
int pushClientCam(int);
int popClientCam(int);
pthread_t thread;
pthread_mutex_t mutex;
pthread_mutex_t mutex_image;
pthread_mutex_t mutex_cam;

#define MAX_CLIENT 10
#define CHATDATA 1024

#define INVALID_SOCK -1

int list_c[MAX_CLIENT];
int list_c_i[MAX_CLIENT];
int list_c_c[MAX_CLIENT];

char greeting[]="Welcome to chatting room\n";
char CODE200[]="Sorry No More Connection\n";

main(int argc, char *argv[])
{
	int 
		c_socket, c_socket_i, c_socket_c, 
		s_socket, s_socket_i, s_socket_c;
	struct sockaddr_in 
			s_addr, s_addr_i, s_addr_c,
			c_addr, c_addr_i, c_addr_c;
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

	if(pthread_mutex_init(&mutex_image, NULL) != 0)
	{
		printf("Can not create mutex\n");
		return -1;
	}

	if(pthread_mutex_init(&mutex_cam, NULL) != 0)
	{
		printf("Can not create mutex\n");
		return -1;
	}
	
	// ~ 기존 socket
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

	// ~ Image socket
	s_socket_i = socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(atoi(argv[1])+1);
	

	if(bind(s_socket_i, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1)
	{
		printf("Can not Bind\n");
		return -1;
	}

	if(listen(s_socket_i, MAX_CLIENT) == -1)
	{
		printf("listen Fail\n");
		return -1;
	}

	// ~ Cam socket
	s_socket_c = socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(atoi(argv[1])+2);
	

	if(bind(s_socket_c, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1)
	{
		printf("Can not Bind\n");
		return -1;
	}

	if(listen(s_socket_c, MAX_CLIENT) == -1)
	{
		printf("listen Fail\n");
		return -1;
	}

	for(i = 0; i < MAX_CLIENT; i++){
		list_c[i] = INVALID_SOCK;
		list_c_i[i] = INVALID_SOCK;
		list_c_c[i] = INVALID_SOCK;
	}

	while(1)
	{
		// ~ Message 처리에 대한 socket을 저장시킨 뒤
		len = sizeof(c_addr);
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);
		res = pushClient(c_socket);
		if(res < 0)
		{
			write(c_socket, CODE200, strlen(CODE200));
			close(c_socket);
		}
		else
		{
			// ~ Image 처리를 위한 socket을 저장한다.
			len = sizeof(c_addr_i);
			c_socket_i = accept(s_socket_i, (struct sockaddr *)&c_addr_i, &len);
			res = pushClientImage(c_socket_i);
			if(res < 0){
				write(c_socket, CODE200, strlen(CODE200));
				close(c_socket_i);
				close(c_socket);
			}else{

				len = sizeof(c_addr_c);
				c_socket_c = accept(s_socket_c, (struct sockaddr *)&c_addr_i, &len);
				res = pushClientImage(c_socket_c);

				if(res < 0){
					write(c_socket, CODE200, strlen(CODE200));
					close(c_socket_i);
					close(c_socket_c);
					close(c_socket);
				}else{
					// ~ 모든 처리가 완벽히 이루어 졌다면
					write(c_socket, greeting, strlen(greeting));
					pthread_create(&thread, NULL, do_chat, (void *)c_socket);
					pthread_create(&thread, NULL, do_image, (void *)c_socket_i);
					pthread_create(&thread, NULL, do_cam, (void *)c_socket_c);
				}				
			}
		}
	}
}

void *do_image(void *arg){
	int c_socket = (int)arg;
	char chatData[CHATDATA];
	int i, n;

	while(1)
	{
		memset(chatData, 0, sizeof(chatData));
		if((n = read(c_socket, chatData, sizeof(chatData))) > 0)
		{
			printf("%d\n", n);
			for(i = 0; i < MAX_CLIENT; i++)
				if(list_c_i[i] != INVALID_SOCK && list_c_i[i] != c_socket)
					write(list_c_i[i], chatData, n);
		}
		else
		{
				popClient(c_socket);
				break;
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
		if((n = read(c_socket, chatData, sizeof(chatData))) != 0)
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

void *do_cam(void *arg)
{
	int c_socket = (int)arg;
	char chatData[CHATDATA];
	int i, n;

	while(1)
	{
		memset(chatData, 0, sizeof(chatData));
		if((n = read(c_socket, chatData, sizeof(chatData))) != 0)
		{
			for(i = 0; i < MAX_CLIENT; i++)
				if(list_c_c[i] != INVALID_SOCK && list_c_c[i] != c_socket)
					write(list_c_c[i], chatData, n);
		}
		else
		{
				popClient(c_socket);
				break;
		}
	}
}

int pushClient(int c_socket)
{
	int i;

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex);
		if(list_c[i] == INVALID_SOCK)
		{
			list_c[i] = c_socket;
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
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}

// ~ image thread
int pushClientImage(int c_socket)
{
	int i;

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex_image);
		if(list_c_i[i] == INVALID_SOCK)
		{
			list_c_i[i] = c_socket;
			pthread_mutex_unlock(&mutex_image);
			return i;
		}
		pthread_mutex_unlock(&mutex_image);
	}

	if(i == MAX_CLIENT)
		return -1;
}

int popClientImage(int s)
{
	int i;

	close(s);

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex_image);
		if(s == list_c_i[i])
		{
			list_c_i[i] = INVALID_SOCK;
			pthread_mutex_unlock(&mutex_image);
			break;
		}
		pthread_mutex_unlock(&mutex_image);
	}
	return 0;
}

// ~ cam thread
int pushClientCam(int c_socket)
{
	int i;

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex_cam);
		if(list_c_c[i] == INVALID_SOCK)
		{
			list_c_c[i] = c_socket;
			pthread_mutex_unlock(&mutex_cam);
			return i;
		}
		pthread_mutex_unlock(&mutex_cam);
	}

	if(i == MAX_CLIENT)
		return -1;
}

int popClientCam(int s)
{
	int i;

	close(s);

	for(i = 0; i < MAX_CLIENT; i++)
	{
		pthread_mutex_lock(&mutex_cam);
		if(s == list_c_c[i])
		{
			list_c_c[i] = INVALID_SOCK;
			pthread_mutex_unlock(&mutex_cam);
			break;
		}
		pthread_mutex_unlock(&mutex_cam);
	}
	return 0;
}