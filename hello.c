#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>

int main(int argc,char *argv[])
{
	char *s = "Hello World!!!\n";
	if (write(1,s,strlen(s))<0) //write(1,"Hello",5); 
	{
		perror("write");
		return errno;
	}
	return 0;
}
