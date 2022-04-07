#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	int n;
	printf("enter numbers of fork you want to create");
	scanf("%d",&n);
	for(int i=1;i<=n;i++) // loop will run n times (n=5)
	{
		sleep(3);
		if(fork() == 0)
		{
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
			printf(" %d my id is %d \n", i,getpid());
			
			exit(0);
		}
	}
	// for(int i=0;i<5;i++) // loop will run n times (n=5)
	// wait(NULL);
	
}
