#ifndef __MYNET_H__
#define __MYNET_H__
	int init_cli(unsigned short port, char *ip);
	int do_work(int sock);
	int uinit_cli(int sock);
#endif
