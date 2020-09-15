#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../include/myopt.h"

int init_ser()
{
	int sock_fd = -1;
	//socket
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0)
	{
		puts("create socket error.");
		return sock_fd;
	} 
	puts("create socket success.");
	//bind
	int ret = -1;
	struct sockaddr_in myser;
	memset(&myser, 0, sizeof(myser));
	myser.sin_family = AF_INET;
	myser.sin_port = htons(8888);
	myser.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(sock_fd, (struct sockaddr *)&myser, sizeof(myser));
	if(ret != 0)
	{
		puts("bind error.");
		return -1;
	}
	puts("bind success.");
	//listen
	ret = listen(sock_fd, 5);
	if(ret != 0)
	{
		puts("listen error.");
		return -1;
	}
	puts("listen success.");
	return sock_fd;
}

int accept_client(int sockfd)
{
	int connfd = -1;
	struct sockaddr_in myclient;
	int len = sizeof(myclient);
	connfd = accept(sockfd,(struct sockaddr *)&myclient, &len);
	if(connfd < 0)
	{
		puts("accept error.");
		return connfd;
	}
	puts("accept success.");
	return connfd;
}

int do_work(int connfd)
{
	if(connfd < 0)
	{
		puts("peer socket is not exist.");
		return -1;
	}
	char buf[50];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		int ret = recv(connfd, buf, sizeof(buf), 0);
		if(ret > 0)
		{
			puts(buf);
			int cmd = getcmd(buf);
			switch(cmd)
			{
				case 0:
					//puts("do up file");
					do_up_file(connfd, buf);
					break;
				case 1:
					return 0;
					break;
				default:
					puts("不支持这种操作");
			}
		}
		else if(ret == 0)
		{
			puts("peer client is closed.");
			break;
		}
	}
}

int uinit_ser(int sockfd)
{
	if(sockfd > 0)
	{
		close(sockfd);
	}
	else
	{
		return -1;
	}
	return 0;
}
