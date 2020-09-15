#ifndef __MYNET_H__
#define __MYNET_H__
	/*
	 *函数名：init_ser
	 *函数功能：初始化网络服务器
	 *函数参数：void
	 *函数返回值：成功：返回创建的socket文件描述符
	 *	      失败：返回-1
	 */
	int init_ser();
	/*
	 *函数名：accept_client
	 *函数功能：接受客户端的连接请求
	 *函数参数：int sockfd：init_ser返回的文件描述符，即监听文件描述符
	 *函数返回值：成功：返回通信套接字
	 *	      失败：-1
	 */
	int accept_client(int sockfd);
	/*
	 *函数名：do_work
	 *函数功能：处理服务器和客户端的业务
	 *函数参数：int connfd:通信套接字，即accept_client的返回值
	 *函数返回值：成功：0	失败：-1
	 */
	int do_work(int connfd);
	/*
	 *函数名：uinit_ser
	 *函数功能：关闭服务器
	 *函数参数：int sockfd:init_ser的返回值
	 *函数返回值：成功：0，失败：-1
	 */
	int uinit_ser(int sockfd);
#endif
