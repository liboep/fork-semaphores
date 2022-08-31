#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid; //Dhlvsh metablhtvn 
    int x,y;
    
    x = 10;	//Arxikopoihsei metablhtvn x, y
    y = 10;
    
    pid = fork(); //Kataxvrhsei sthn pid thn timh fork() kai duplicate process apo dv kai katv
    
    if (pid != 0)	//Elegxos an h diergasia einai parent
    {
      	x++;	//Allagh metablhtvn
      	y--;	
    }
       
	printf("x = %i y = %i\n",x,y);	// Emfanish metablhtvn	
    
	/* 	
	x = 11 y = 9 	--> Gia thn parent01 diergasia
	x = 10 y = 10	--> Gia thn child01 diergasia
    */
    
    pid = fork();	// Diplasiasmos pali tvn diergasivn apo dv kai meta
	
	//Dhladh ena chlid gia thn parent01 kai ena gia thn child01
    
    if (pid != 0)	//Elegxos an h diergasia einai parent
    {
      	x++;	//Allagh metablhtvn
      	y--;
    }
       
   		printf("x = %i y = %i\n",x,y);	// Emfanish metablhtvn	


	
	/*
	x = 12 y = 8	--> Gia thn parent01 diergasia
	x = 11 y = 9	--> Gia thn child01 diergasia poy uevreitai parent toy childchlid01 |
	x = 11 y = 9	--> Gia thn child02 toy parent01                                    |
	x = 10 y = 10	--> Gia thn childchlid01 toy child01 <==============================|
	*/
    
    
    return (0);
}