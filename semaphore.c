// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex; 

void* thread(void* arg) 
{ 
  //wait
  int myid=(int*)arg;
  int bob;
  if(sem_getvalue(&mutex,&bob)!=0){
    printf("Issues.\n");
  }
  printf("Thread %d Starting -- sem %d\n",myid,bob);
  
  sem_wait(&mutex); 
  printf("Thread %d Entered -- sem %d\n",myid,bob); 
  //critical section 
  sleep(4); 
  
  //signal 
  printf("Thead %d Exiting...\n",myid); 
  sem_post(&mutex); 
} 


int main() 
{ 
  sem_init(&mutex, 0, 2); 
  pthread_t t1,t2,t3,t4,t5; 
  pthread_create(&t1,NULL,thread,1); 
  //  sleep(2); 
  pthread_create(&t2,NULL,thread,2);
  pthread_create(&t3,NULL,thread,3);
  pthread_create(&t4,NULL,thread,4);
  pthread_create(&t5,NULL,thread,5); 

  pthread_join(t1,NULL); 
  pthread_join(t2,NULL); 
  pthread_join(t3,NULL); 
  pthread_join(t4,NULL);
  pthread_join(t5,NULL);
  
  sem_destroy(&mutex); 
  return 0; 
} 
