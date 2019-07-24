#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int file1,file2;
	file1=open(argv[1],O_RDONLY,S_IRUSR);
	if(file1<0)
	{
		perror("open1");
		return errno;
	}
	file2=open(argv[2],O_WRONLY|O_CREAT,S_IRWXU);
	if(file2<0)
	{
		perror("open2");
		return errno;
	}
	struct stat info;
	if(stat(argv[1],&info)<0)
	{
		perror("stat");
		return errno;
	}
	char *sir;
	if(read(file1,sir,info.st_size)<0)
	{
		perror("read");
		return errno;
	}
	sir[info.st_size]='\0';	//inlocuieste EOF cu sfarsitul unui sir
	if(write(file2,sir,strlen(sir))<0)
	{
		perror("write");
		return errno;
	}
	return 0;
}
