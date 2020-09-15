#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
	//puts(buf);

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
	//puts(filename);
	//create file
	char pf[100] = {0};
	sprintf(pf,"./homework/%s",filename);
	//puts(pf);
	int fd = -1;
	fd = open(pf, O_CREAT | O_WRONLY, 0664);
	if(fd < 0)
	{
		puts("open file error.");
		return -1;
	}
	puts("open file success.");
	//recv file len
	char flen[20] = {0};
	int ret = recv(sock, flen, sizeof(flen), 0);
	if(ret > 0)
	{
		puts(flen);
		int fs = atoi(flen+4);
		//recv file context
		char *pfc = NULL;
       		pfc = (char *)malloc(fs);
        	if(pfc != 0)
        	{   
			int total = 0;
			while(total < fs)
			{
				ret = recv(sock, pfc, fs-total, 0);
				if(ret > 0)
				{
					write(fd,pfc,ret);
				}
				total += ret;
			}
        	}   

		//send result to client
		puts("up file ok");
	}
	//close fd
	close(fd);
	return 0;
}


