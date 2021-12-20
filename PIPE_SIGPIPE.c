#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>


void _MyISR(int n)
{
	printf("In ISR: %d ..... %s\n",n,strsignal(n));
}

int main()
{
	int p[2],a=20;
	pipe(p);
	perror("pipe");
	signal(SIGPIPE,_MyISR);
	close(p[0]);  //Read end closed
	write(p[1],&a,4);
	perror("Write");
}
