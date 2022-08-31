#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int pid, parpid, curpid;
	
	printf("Parent ID : %d\n\n", getpid());
	parpid=getpid();
	
    for ( int i = 0; i < 2; i++ )
	{	
		pid = fork();
		curpid = getpid();
		
		if ( curpid != parpid){ 
			printf("My process ID : %d\n", getpid());
   			printf("My parent's ID: %d\n\n", getppid());
		}
	}
	
	usleep( 100 );
	return 0;
}