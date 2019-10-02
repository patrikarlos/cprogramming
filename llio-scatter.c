#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

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
  char buffer[104858];
  int a;
  int sizeCnt=0;
  while( a=read(fid,buffer,104858-1),a>0){
    sizeCnt+=a;
  }
  //  printf("Read %d\n",sizeCnt);
  return(sizeCnt);
}

int main(int arc, char **argv){

 
  int fid;
  struct timeval starttime,stoptime,stdresult;
  struct timeval fstarttime,fstoptime,fresult;
  
  
  fid = open("randfile",O_RDONLY);
  
  struct iovec myvector[10];
  char *buffer[10];
  
  buffer[0]=(char *)malloc(104858);
  buffer[1]=(char *)malloc(104858);
  buffer[2]=(char *)malloc(104858);
  buffer[3]=(char *)malloc(104858);
  buffer[4]=(char *)malloc(104858);
  buffer[5]=(char *)malloc(104858);
  buffer[6]=(char *)malloc(104858);
  buffer[7]=(char *)malloc(104858);
  buffer[8]=(char *)malloc(104858);
  buffer[9]=(char *)malloc(104858);



  myvector[0].iov_base=buffer[0];
  myvector[0].iov_len=104858;
  myvector[1].iov_base=buffer[1];
  myvector[1].iov_len=104858;
  myvector[2].iov_base=buffer[2];
  myvector[2].iov_len=104858;
  myvector[3].iov_base=buffer[3];
  myvector[3].iov_len=104858;
  myvector[4].iov_base=buffer[4];
  myvector[4].iov_len=104858;
  myvector[5].iov_base=buffer[5];
  myvector[5].iov_len=104858;
  myvector[6].iov_base=buffer[6];
  myvector[6].iov_len=104858;
  myvector[7].iov_base=buffer[7];
  myvector[7].iov_len=104858;
  myvector[8].iov_base=buffer[8];
  myvector[8].iov_len=104858;
  myvector[9].iov_base=buffer[9];
  myvector[9].iov_len=104858;


  gettimeofday(&starttime,NULL);
  int resp=readv(fid,myvector,10);
  gettimeofday(&stoptime,NULL);


  //  printf("f variant..............\n");
  gettimeofday(&fstarttime,NULL);
  int read_bytes=stddump("randfile");
  if( read_bytes<0){
    printf("Bummer, fread().\n");
    return(-1);
  }
  gettimeofday(&fstoptime,NULL);
  
    
  if (timeval_subtract(&stdresult,&stoptime,&starttime)<0){
    timeval_subtract(&stdresult,&starttime,&stoptime);
  }
  if (timeval_subtract(&fresult,&fstoptime,&fstarttime)<0){
    timeval_subtract(&fresult,&fstarttime,&fstoptime);
  }

  
  lseek(fid,0,SEEK_SET);

  printf("Std: %d -  %d.%06ld \t", resp, (int)stdresult.tv_sec, stdresult.tv_usec);
  printf("f  : %d - %d.%06ld \n", read_bytes, (int)fresult.tv_sec, fresult.tv_usec);

  gettimeofday(&starttime,NULL);
  resp=readv(fid,myvector,10);
  gettimeofday(&stoptime,NULL);


  //  printf("f variant..............\n");
  gettimeofday(&fstarttime,NULL);
  read_bytes=stddump("randfile");
  if( read_bytes<0){
    printf("Bummer, fread().\n");
    return(-1);
  }
  gettimeofday(&fstoptime,NULL);
  
    
  if (timeval_subtract(&stdresult,&stoptime,&starttime)<0){
    timeval_subtract(&stdresult,&starttime,&stoptime);
  }
  if (timeval_subtract(&fresult,&fstoptime,&fstarttime)<0){
    timeval_subtract(&fresult,&fstarttime,&fstoptime);
  }
  

  printf("Std: %d -  %d.%06ld \t", resp, (int)stdresult.tv_sec, stdresult.tv_usec);
  printf("f  : %d - %d.%06ld \n", read_bytes, (int)fresult.tv_sec, fresult.tv_usec);




  
  
  return 1;
}
