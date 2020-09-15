#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int send_cmd(int sock, char *cmd)
{
	if(sock < 0)
	{
		return -1;
	}
	memset(cmd, 0, sizeof(cmd));
	gets(cmd);
	send(sock, cmd, strlen(cmd), 0);
	return 0;
}

int getcmd(char *cmd)
{
	if(NULL == cmd)
	{
		puts("NULL pointer error.");
		return -1;
	}
	char buf[10] = {0};
	char *p = cmd;
	int i = 0;
	while(*p)
	{
		if(*p == ' ')
		{
			buf[i] = 0;
			break;
		}
		else
		{
			buf[i] = *p;
			p++;
			i++;
		}
	}
	puts(buf);

	if(strcmp(buf,"up") == 0)
	{
		return 0;
	}
	else if(strcmp(buf,"quit") == 0)
	{
		return 1;
	}
}

int get_file_name(char *buf, char *filename)
{
	if(NULL == buf || NULL == filename)
	{
		puts("NULL pointer error.");
		return -1;
	}

	char *p = buf;
	while(*p)
	{
		if(*p == ' ')
		{
			p++;
			break;
		}
		p++;
	}
	strcpy(filename, p);
	return 0;
}

int get_file_len(char *filename, int *psize)
{
	puts(filename);
	#if 0
	//open file

	if(fd < 0)
	{
		puts("fd < 0");
		return -1;
	}
	if(NULL == psize)
	{
		puts("NULL pointer error.");
		return -1;
	}
	int ret = lseek(fd, SEEK_END, 0);
	close(fd);
	#endif
	struct stat myfs;
	stat(filename,&myfs);
	int ret = myfs.st_size;
	printf("ret = %d\n",ret);
	*psize = ret;
	return 0;
}

int do_up_file(int sock, char *buf)
{
	if(sock < 0)
	{
		puts("sock error.");
		return -1;
	}

	if(NULL == buf)
	{
		puts("NULL pointer error.");
		return -1;
	}
	//get file name
	char filename[100];
	memset(filename, 0, sizeof(filename));
	get_file_name(buf, filename);

	sleep(1);
	//get file len
	int fs = 0;
	get_file_len(filename,&fs);
	printf("fs:%d\n",fs);
	char flen[20] = {0};
	sprintf(flen,"len:%d",fs);
	puts(flen);
	//send file len
	send(sock,flen,strlen(flen),0);
	sleep(1);
	//open file
	int fd = -1;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		puts("open file error.");
		return -1;
	}
	puts("open file success.");
	char *pfc = NULL;
	pfc = (char *)malloc(fs);
	if(pfc != 0)
	{
		int ret = read(fd, pfc, fs);
		if(ret == fs)
		{
			send(sock, pfc, fs, 0);
		}
	}
	//close
	close(fd);
}
