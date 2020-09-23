/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

/* global variable */
int count = 0;

void counter(int signum) {
  count++;
	printf("Count: %d\n", count);
	alarm(1); //Schedule a SIGALRM for 1 second
}

void stop(int signum) { //signal handler
	printf("\nRan for %d seconds.\n", count);
	exit(0);
}

int main(int argc, char * argv[]) {
  signal(SIGALRM, counter); //register handler to handle SIGALRM
  signal(SIGINT, stop); //register handler to handle SIGINT

	alarm(1); //Schedule a SIGALRM for 1 second

  while(1);

  return 0; //never reached
}


