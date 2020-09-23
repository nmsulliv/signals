# Operating Systems Signals Lab
This is a simple C program that will teach you the basics of signal handling.

## Instructions
Change signal.c such that after the handler is invoked, an additional 
printf("Turing was right!\n") occurs in main() before exiting. 
You will probably need to use a global variable and change the condition on 
the while loop.

Change signal.c such that every second, first “Hello World!” prints from the
signal handler followed by “Turing was right!” in main(), over and over 
again indefinitely. The output should look like:
	Hello World!
	Turing was right!
	Hello World!
	Turing was Right!
	...

Program a new program timer.c that after exiting (via CTRL-C), will print out
the total time the program was executing in seconds. To accomplish this task,
you will need to register a second signal handler for the SIGINT signal, the
signal that is delivered when CTRL-C is pressed. Conceptually, your program
will request a SIGALRM signal to occur every second, tracking the number of
alarms delivered, and when the program exits via CTRL-C, it will print how 
many alarms occurred, or the number of seconds it was executed.
