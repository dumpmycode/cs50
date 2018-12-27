#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32

// prototypes
void printS(int);
void printB(int);
void chkinput(char*, int*);

int main(){

	int uplist[8] = {1, 2, 3, 4, 5, 6 ,7 ,8};
	int downlist[8] = {7, 6, 5, 4, 3, 2, 1, 0};
	int input = 0;
	char txtinput[MAX];
	
	txtinput[strcspn(txtinput, "\n")] = '\0'; //strip newline thats added by fgets()
	chkinput(txtinput, &input);
	
	// if input = 1, print 7 space, 1 brick. repeat by input times
	for (int i=0; i<input; i++){
		int printR = downlist[i];
		int printL = uplist[i];

		// printf("space to print: %d\n",spc);
		// printf("brick to print: %d\n",brk);

		// print spaces first then bricks
		printS(printR);
		printB(printL);//brickr

		// print dividing spaces
		printf("  ");	

		// print bricks first then spaces
		printB(printL);
		printS(printR);//brickl

		printf("\n");
	}	
	return 0;
}

// functions:

// print n number of spaces provided in argument
void printS(int n){
	for (int i=0; i<n; i++){
		printf(" ");
	}
}

// print n number of bricks
void printB(int n){
	for (int i=1; i<=n; i++){
		printf("#");
	}
}

void chkinput(char *txtinput, int *input) {// inputs: txtinput, *input
	
	int exit = 0;
	int len = strlen(txtinput);

	while (1){	

		printf("Enter brick length: ");
		fgets(txtinput, MAX, stdin);
		printf("finished fgets()\n");
		
		for(int i=0; i<len; i++) { // check for letters & digit length
			
			printf("now in 1st for loop\n");		
			char x = txtinput[i];
			printf("txtinput[i] = %p\n", x);
			
			if(len > 1) {
				// if input is 2+ digit long, retry
				printf("Incorrect input (> 1 digit). Try again.\n");
				exit = 1; // raise invalid char flag
				break; //break the for loop and continue the while loop
			}   
			else if( (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9') ){
				// if input is letter, retry
				printf("Incorrect input (letter). Try again.\n");
				exit = 1;
				break; //break the for loop and continue the while loop
			}   
		}

		if(exit == 1) { // if flag raised for invalid char, skip back to top
			continue;
		}
		
		for (int i=0; i<len; i++) {
			
			char x = txtinput[i];

			if(x >= '0' && x <= '9') {
				// if input is number then change char input to int
				*input = x - '0';
				printf("Entered number: %d\n", *input);
				return; //exit function
			}   
			else {
				printf("Incorrect input (special char). Try again.\n");
				break;	
			}	   
		}
	}
}
