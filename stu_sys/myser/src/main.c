#include <stdio.h>
#include "../include/mynet.h"

int main()
{
	//init_ser
	int ser_fd = init_ser();
	if(ser_fd < 0)
	{
		puts("init_ser error.");
		return -1;
	}
	//accept_client
	int connfd = -1;
	connfd = accept_client(ser_fd);
	//do work
	do_work(connfd);
	close(connfd);
	//uinit_ser
	uinit_ser(ser_fd);
	return 0;
}
