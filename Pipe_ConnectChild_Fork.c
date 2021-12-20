#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		printf("child\n");
		char s[20];
		close(p[1]);
		read(p[0],s,20);
		printf("recv %s\n",s);
	}
	else
	{
		char str[20];
		printf("enter the data:");
		scanf("%[^\n]s",str);
		close(p[0]);
		write(p[1],str,20);
		printf("parent\n");
		wait(NULL);
	}
}
