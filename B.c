#include <stdio.h>
#include <stdlib.h>


int main( void )
{
    int pid;
	
    for ( int i = 0; i < 4; i++ )
	{	
		pid = fork();
		
		if ( pid == 0 )
        {
           	break;
        }
	}

	if (pid == 0)
	{ 
		printf("Child process ID : %d\n", getpid());
	}else
	{
		printf("Parent process ID : %d\n", getpid());
	}
	
	return 0;
}