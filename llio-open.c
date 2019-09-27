#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <sys/time.h> /* select() */



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

int stddump(char *fname){
  int fid=open(fname, O_RDONLY);
  if(fid<1){
    perror("Issues opening file");
    return(-1);
  }
  char buffer[10000];
  int a;
  int sizeCnt=0;
  while( a=read(fid,buffer,10000-1),a>0){
    sizeCnt+=a;
  }
  //  printf("Read %d\n",sizeCnt);
  return(sizeCnt);
}
      
  

int fdump(char *fname){
  FILE *fid=fopen(fname, "r");
  if(fid==0){
    perror("Issues opening file");
    return(-1);
  }
  char buffer[10000];
  int a;
  int sizeCnt=0;
  //printf("starting fread\n");
  while(!feof(fid)){
    a=fread(buffer,1, 10000-1,fid);
    //    printf("read %d\n",a);
    sizeCnt+=a;
   
  }
  //  printf("Read %d\n",sizeCnt);
  return(sizeCnt);
}
   



int main(int arc, char **argv){

  FILE *fid;
  int descriptor;
  struct timeval starttime,stoptime,stdresult;
  struct timeval fstarttime,fstoptime,fresult;
  
  printf("I will open Sesame!\n");

  int repeats=atoi(argv[1]);

  
  descriptor = open("foobar",O_RDONLY);
  
  char bob[1];
  int a;
  a=read(descriptor,&bob,(size_t)1);
    
  while(a>0){
    //    printf("%d:%c ",a, *bob);
    printf("%c ", *bob);
    a=read(descriptor,&bob,(size_t)1);
  }
  printf("\nEOF\n");
  close(descriptor);

  printf("fopen\n");
  fid = fopen("foobar", "r");
  while( (a=fgetc(fid)) ) {
    if(feof(fid)){
      break;
    }
    printf("%c ", a);
  }
  fclose(fid);
  printf("\nEOF\n");


  printf("Difference in buffering. \n");

  for (int k=0;k<repeats;k++){
  //  printf("Std..............\n");

  gettimeofday(&starttime,NULL);
  if(stddump("randfile")<0){
    printf("Bummer, read().\n");
    return(-1);
  }
  gettimeofday(&stoptime,NULL);

  //  printf("f variant..............\n");
  gettimeofday(&fstarttime,NULL);
  if(fdump("randfile")<0){
    printf("Bummer, fread().\n");
    return(-1);
  }
  gettimeofday(&fstoptime,NULL);

  //  printf("done....\n");
  
  if (timeval_subtract(&stdresult,&stoptime,&starttime)<0){
    timeval_subtract(&stdresult,&starttime,&stoptime);
  }
  if (timeval_subtract(&fresult,&fstoptime,&fstarttime)<0){
    timeval_subtract(&fresult,&fstarttime,&fstoptime);
  }
  
  printf("Std:%d.%06ld \t", (int)stdresult.tv_sec, stdresult.tv_usec);
  printf("f  :%d.%06ld \n", (int)fresult.tv_sec, fresult.tv_usec);
  }
  
  return 1;
}
