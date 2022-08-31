#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem_1; //Global variable typoy sem_t

int main( void )
{

  sem_init(&sem_1, 2, 0); // Dhlvsh shmaforoy

  int ppid, pid;  //Dhlvsh metablhtvn
  int cpid[5];

  ppid = getpid();
  printf("PID = %i\n", ppid );

  for ( int i = 0; i < 5; i++ ) //Dhmioyrgia uygatrikvn diergasivn kai apouhkeysh tvn pid toys
  {
      pid = fork();
      if( ppid != getpid() )
      {
        cpid[i] = getpid();
        printf("Child pid = %i\n", cpid[i] );
      }
      if ( pid == 0 )
      {
        break;
      }
  }
  printf("Child processes ready\n\n\n" );

  sleep(2); //Speep until all processes ready

  if(getpid() > ppid)
  {
    printf("PID running = %i\n\n", getpid());

    /*

    Parakatv exoyme elegxo diergasivn kai ayjvmivsei shmaforvn analoga me thn katastash


    */
    if(getpid() == cpid[0])
    {
      sem_wait(&sem_1);
      system("ls -l");  //Diergasia 5
      printf("\n\n" );

    }else
    {
      sem_post(&sem_1);
    }
    if(getpid() == cpid[1])
    {
      sem_wait(&sem_1);
      system("ps -l");   //Diergasia 4
      printf("\n\n" );

    }else
    {
      sem_post(&sem_1);
    }
    if(getpid() == cpid[2])
    {
      sem_wait(&sem_1);
      system("ifconfig");   //Diergasia 3
      printf("\n\n" );

    }else
    {
      sem_post(&sem_1);
    }
    if(getpid() == cpid[3])
    {
      sem_wait(&sem_1);
      system("echo Process 2");   //Diergasia 2
      printf("\n\n" );

    }else
    {
      sem_post(&sem_1);
    }
    if(getpid() == cpid[4])
    {
      sem_wait(&sem_1);
      system("pwd");  //Diergasia 1
      printf("\n\n" );

    }else
    {
      sem_post(&sem_1);
    }

  }



  return 0;


}
