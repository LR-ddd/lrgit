#include <stdio.h>
#include "../include/mynet.h"

int main()
{
	//init_cli()
	int sock = init_cli(8888,"127.0.0.1");
	if(sock < 0)
	{
		puts("init_cli error.");
		return -1;
	}
	//do_work()
	do_work(sock);
	//uinit_cli()
	uinit_cli(sock);
	return 0;
}
