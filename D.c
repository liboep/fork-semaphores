#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int nothing( int in_x );


int main () {

	int pid, counter;	//Orismos metablhtvn
	long int start, end;
	double  tperpr; 	//Time per process

	printf ( "PID: %d\n", getpid());

	counter=0;
	start= time(NULL);

	printf("Arxikh timh deyteroleptvn: %ld\n", start);

	while( counter < 100 ){

		pid = fork();

		if ( pid == 0 )
        {
           	return 0;
        }

		counter = nothing(counter);

	}

	while ((pid=waitpid(-1,NULL,0))!=-1) {	//wait mexri ta paidia termatisoyn
 		printf("Process %d terminated\n",pid);
	}
	printf ( "PID: %d\n", getpid());

	if( pid != 0){

		end = time(NULL);
		printf("Telikh timh deyteroleptvn: %ld\n", end);
		tperpr = ((double)end - (double)start)/100;
		printf("Mesos xronos ekteleseis kai termatismoy diergasias: %f s\n", tperpr);

	}

	return 0;
}

/* Gia 10000 diergasies o mesos xronos ekteleshs einai 0.0001s
	gia 5000 einai 0.0002s
	kai gia 100 h diafora ekkhnhshs me termatismoy einai <1s opote o xronos einai mh metrhsimos me thn time()*/


int nothing( int in_x ){

	int out_x;

	out_x = in_x + 1;

	return out_x;

}
