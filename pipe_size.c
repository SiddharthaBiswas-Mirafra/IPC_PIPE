#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>
int main()
{
	int p[2],cnt=0,fd;
	char ch='a';
	pipe(p);
	fcntl(p[1],F_SETFL,O_NONBLOCK);
	while(write(p[1],&ch,1)==1)
		cnt++;
	printf("%d\n",cnt);
}

