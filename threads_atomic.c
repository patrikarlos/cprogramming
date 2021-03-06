/******************************************************************************
* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdatomic.h>
#define NUM_THREADS	5


_Atomic int counter = ATOMIC_VAR_INIT(0);


void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   int randTime=1+rand()%5;
   
   while(counter<100){
     printf("Hello World! It's me, thread #%ld!, my sleep is %d, counter = %d \n", tid,randTime, counter);
     counter++;
     sleep(randTime);
   }
   
   pthread_exit(NULL);
}



int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
