#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* This flag controls termination of the main loop. */
volatile sig_atomic_t keep_going = 1;

/* The signal handler just clears the flag and re-enables itself. */
void catch_alarm (int sig)
{
  puts("Got ALARM!\n");
  keep_going = 0;
  //  signal (sig, catch_alarm);
}


int intrcnt=0;
void catch_int (int sig)
{
  printf("Got INT %d!\n", intrcnt);
  intrcnt++;
  //  signal (sig, catch_alarm);
}




void
do_stuff (void)
{
  puts ("Doing stuff while waiting for alarm....");
}

int
main (void)
{
  /* Establish a handler for SIGALRM signals. */
  signal (SIGALRM, catch_alarm);
  signal (SIGINT, catch_int);

  /* Set an alarm to go off in a little while. */
  alarm (20);

  /* Check the flag once in a while to see when to quit. */
  while (keep_going){
    do_stuff ();
    sleep(1);
  }
  return EXIT_SUCCESS;
}
