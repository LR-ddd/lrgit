#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../include/myopt.h"

int init_cli(unsigned short port, char *ip)
{
	if(port < 6000)
	{
		puts("port is so small.");
		return -1;
	}

	if(NULL == ip)
	{
		puts("ip is null pointer.");
		return -1;
	}

	int sock = -1;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		puts("socket error.");
		return -1;
	}
	puts("socket success.");

	struct sockaddr_in myser;
	memset(&myser, 0, sizeof(myser));
	myser.sin_family = AF_INET;
	myser.sin_port = htons(port);
	myser.sin_addr.s_addr = inet_addr(ip);

	int ret = connect(sock, (struct sockaddr *)&myser, sizeof(myser));
	if(ret != 0)
	{
		close(sock);
		sock = -1;
		puts("connect error.");
		return sock;
	}
	puts("connect success.");
	return sock;
}

int do_work(int sock)
{
	if(sock < 0)
	{
		puts("sock < 0");
		return -1;
	}
	char buf[250];
	while(1)
	{
		//get cmd send cmd
		send_cmd(sock,buf);
		int cmd = getcmd(buf);
		switch(cmd)
		{
			case 0:
				//puts("up file");
				do_up_file(sock,buf);
				break;
			case 1:
				return 0;
				break;
			default:
				puts("cannot support this option.");
		}
	}
	return 0;
}

int uinit_cli(int sock)
{
	if(sock < 0)
	{
		puts("sock < 0");
		return 0;
	}
	close(sock);
	return 0;
}
