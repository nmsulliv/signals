/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* global variable */
int count = 0;
int g = 0;

void counter(int signum) { //signal handler
  count++;
	printf("Count: %d\n", count);
	g = 1;
}

void handler(int signum) {
	printf("\nRan for %d seconds.\n", count);
	exit(0);
}

int main(int argc, char * argv[]) {
  signal(SIGALRM, counter); //register handler to handle SIGALRM
  
  while(1) {
    alarm(1); //Schedule a SIGALRM for 1 second

    while(g == 0); //busy wait for signal to be delivered
    g = 0;
		
		signal(SIGINT, handler); //register handler to handle SIGINT
  }

  return 0; //never reached
}


