#include <stdio.h>

	// Declarations

void insmode(); /* File insertion mode.
		 * How to use:
		 * Append 'i' to the start
		 * of the string u wanna add
		 * then write it normally.
		 * Special chars noted with \* as in C.
		*/

int main(){

	// Program startup

	int errcode = 0;
	char function = 0;
	char helpmsg[] = "You'll figure it out. q to quit.\n";

	//Main loop

	while (!errcode){

		// Show file from RAM
		printf("\nFile contents here\n");

		// Ask for input
		printf("Command: ");
		scanf(" %c", &function);

		// We have input, lets determine the cmd:
		switch(function){
		case 'q' : {
			errcode = 1;
			break;
			}
		case 'h' : {
			printf("%s",helpmsg);
			break;
			}
		case 'i' : {
			insmode();
			break;
			}
		default : {
			printf("Unknown command %c.\n",function);
			break;
			}
		}
	}

	//Cleanup code

	return errcode;

}

	//Extra functions called from the main loop:

void insmode(){
	printf("You\'re using insert mode.\n");
	return;
}
