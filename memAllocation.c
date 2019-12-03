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



int main(int arc, char **argv){

  FILE *fid;
  int descriptor;
  struct timeval starttime,stoptime,stdresult;
  struct timeval fstarttime,fstoptime,fresult;
  
  printf("I will allocate Memory!\n");

  int chunk=atoi(argv[1]);
  int repeats=atoi(argv[2]);

  struct Node *base=NULL;
  struct Node *newnode=NULL;
  struct Node *current=NULL;


  unsigned long int allocationSize=chunk;
  int scaleFactor=10;
  unsigned long int allocation=0;
  
  for (int k=0;k<repeats;k++){
    printf("%d Trying : %lu => ",k, allocationSize);
    
    gettimeofday(&starttime,NULL);


    newnode=(struct Node*)calloc(1,sizeof(struct Node));
    newnode->dataPtr=(int *)calloc(allocationSize,sizeof(int));
    newnode->next=NULL;

    if (newnode->dataPtr==NULL) {
      printf("\n\tCalloc failed,scaling back and fixing scale factor to 1.\n");
      allocationSize/=scaleFactor;
      printf("%d Trying : %lu => ",k, allocationSize);
      newnode->dataPtr=(int *)calloc(allocationSize,sizeof(int));

      if(newnode->dataPtr==NULL) {
	printf("\n\t\tCalloc failed again, thats it I quit.\n");
	break;
      }
      scaleFactor=1;
    }
    if(base==NULL){
      base=newnode;
      current=base;
    } else {
      current->next=newnode;
      current=newnode;
    }
    
    gettimeofday(&stoptime,NULL);
    allocation+=allocationSize*sizeof(int);
    timeval_subtract(&stdresult,&stoptime,&starttime);
    printf(" Allocated %lu bytes, (total %lu MiB)  in %d.%06ld \n", allocationSize*sizeof(int),allocation/(1024*1024),(int)stdresult.tv_sec, stdresult.tv_usec);

    allocationSize*=scaleFactor;
  }
  return 1;
}
