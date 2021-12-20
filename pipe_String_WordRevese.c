#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
void func(char *p)
{
	char ch;
	int i=0,j=0,x=0,y=0,k=0;
	for(i=0;p[i];i++)
	{
		if((p[i]!=32) && (p[i+1]==32 || p[i+1]==0 || p[i+1]==10))
		{
			for(x,y=i;x<y;x++,y--)
			{
				ch=p[x];
				p[x]=p[y];
				p[y]=ch;
			}
			x=i+1;
		}
		if(p[x]==32)
			x++;
	}
	for(i=0,j=strlen(p)-1;i<j;i++,j--)
	{
		ch=p[i];
		p[i]=p[j];
		p[j]=ch;
	}

}
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		char s[100];
		read(p[0],s,sizeof(s));
		printf("data recived==%s\n",s);
		func(s);

		close(p[0]);
		write(p[1],s,strlen(s)+1);
		
		
	}
	else
	{
		char str[100];
		printf("enter the data:");
		scanf("%[^\n]s",str);
		//close(p[0]);
		write(p[1],str,strlen(str)+1);
		wait(NULL);

		close(p[1]);
		read(p[0],str,sizeof(str));
		printf("update data==%s\n",str);
		
	}
}
