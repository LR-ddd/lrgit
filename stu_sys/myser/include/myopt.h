#ifndef __MYOPT_H__
#define __MYOPT_H__
	/*
	 *函数名：getcmd
	 *函数功能：解析客户端发来的命令
	 *函数参数：char *cmd：包含命令的字符串的首地址
	 *函数返回值：int：
	 *		0：上传up
	 *		1：退出quit
	 *		-1：没有这个操作
	 */
	int getcmd(char *cmd);
#endif
