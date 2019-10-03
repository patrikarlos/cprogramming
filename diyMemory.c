#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/time.h> /* select() */

/* Example of memory allocation */
/*
 executable <start_chunk> <repetitions> > tempFile;
 grep "Allocated" tempFile | awk '{print $1," ",$4," ",$NF}' > tmp2
 gnuplot
 plot tmp2 using 1:3 with lines 
*/


int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y){
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

struct Node{
  int *dataPtr;
  int size;
  struct Node* next;
};

struct memNode{
  int size;
  int id;
  struct memNode* next;
  void *location;
};




int main(int arc, char **argv){

  struct timeval starttime,stoptime,stopAlltime,stdresult,fresult;
  

  int chunk=1000;
  int repeats=100000;

  printf("I will allocate Memory, in a linked list.!\n");


  struct Node *base=NULL;
  struct Node *newnode=NULL;
  struct Node *current=NULL;


  unsigned long int allocationSize=chunk;
  unsigned long int allocation=0;
  
  gettimeofday(&starttime,NULL);
  for (int k=0;k<repeats;k++){
    newnode=(struct Node*)calloc(1,sizeof(struct Node));
    newnode->dataPtr=(int *)calloc(allocationSize,sizeof(int));
    newnode->next=NULL;

    if (newnode->dataPtr==NULL) {
	printf("\n\t\tCalloc failed again, thats it I quit.\n");
	break;
    }
    if(base==NULL){
      base=newnode;
      current=base;
    } else {
      current->next=newnode;
      current=newnode;
    }
    allocation+=allocationSize*sizeof(int);

  }

  gettimeofday(&stoptime,NULL);
  timeval_subtract(&stdresult,&stoptime,&starttime);
  printf(" Allocated %lu bytes in %d objects, in total %lu bytes, it took %d.%06ld [s] \n", allocationSize*sizeof(int),repeats, allocation,(int)stdresult.tv_sec, stdresult.tv_usec);




  printf("I will allocate Memory, one Blob, then populate it and use a linked list.!\n");
  gettimeofday(&starttime,NULL);
  allocation = ((chunk*sizeof(int)+sizeof(struct memNode))*repeats);
  void *ptr=(void*)malloc(allocation);

  if(ptr==NULL){
    printf("Cant allocate %lu bytes.\n", allocation);
    return(-1);
  }
  gettimeofday(&stopAlltime,NULL);

#ifdef DEBUG  
  void *upperptr=ptr+allocation;
  printf("ptr : %p -- %p \n", ptr, upperptr);
#endif  

  struct memNode *mBase=NULL;
  struct memNode *mCurrent=NULL;

  mBase=(struct memNode*)(ptr);
  mCurrent=(struct memNode*)(ptr);


  for (int k=0;k<repeats;k++){
    mCurrent=(struct memNode*)(ptr+k*(sizeof(struct memNode)+chunk*sizeof(int)));
    mCurrent->size=chunk*sizeof(int);
    mCurrent->id=k;
    mCurrent->location=mCurrent+sizeof(struct memNode);

    bzero(mCurrent->location,chunk*sizeof(int));

    mCurrent->next=mCurrent+sizeof(struct memNode)+chunk*sizeof(int);
#ifdef DEBUG
    if(k%1000==0){
      printf("%d %p location =%p %d next %p  (%ld)  %p [%lu] \n", k, mCurrent, mCurrent->location, mCurrent->id, mCurrent->next, (mCurrent->next-mCurrent), upperptr, (upperptr-(void*)mCurrent));
    }
#endif    
  }


  gettimeofday(&stoptime,NULL);
  timeval_subtract(&stdresult,&stoptime,&starttime);
  timeval_subtract(&fresult,&stopAlltime,&starttime);
  
  printf(" All+assign. %lu bytes in %d objects, in total %lu bytes, it took %d.%06ld [s] \n", allocationSize*sizeof(int),repeats, allocation,(int)stdresult.tv_sec, stdresult.tv_usec);
  printf(" Allocated   %lu bytes in %d objects, in total %lu bytes, it took %d.%06ld [s] \n", allocationSize*sizeof(int),repeats, allocation,(int)fresult.tv_sec, fresult.tv_usec);

 

  mCurrent=mBase;
  for (int k=0;k<repeats;k++){
    mCurrent=(struct memNode*)(ptr+k*(sizeof(struct memNode)+chunk*sizeof(int)));
#ifdef DEBUG
    if(k%1000==0){
	 printf("Loop: %d %d : Node %p\n", k, mCurrent->id,mCurrent);
    }
#endif    
  }
   


  
  free(ptr);
  printf("Leaving.\n");


  

  return 1;
}
