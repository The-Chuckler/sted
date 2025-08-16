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

	// These store your current position in the file:
	long unsigned int xpos,ypos = 0;

	// Error code. Will be 1 if no errors. Not std, sorry
	int errcode = 0;

	// Command to be run, only way of input
	char function = 0;

	// What is displayed when 'h' is pressed.
	char helpmsg[] = "Command list: q to quit\n";

	// Current string. Temp implementation.
	char currstr[20];

	// File pointer, idk how this works but ig 'tis std
	FILE * urfile;

	// File loading. TODO: take name from cmdargs.
	urfile = fopen("test.txt", "r");

	// Empty file prevention:
	if (urfile == NULL) return 2;

	// Put first string of file in RAM:
	fgets(currstr, 20, urfile);
	// Main loop

	while (!errcode){

		// Show file from RAM
		printf("\n%s\n",currstr);

		// Tell user the cursor position
		printf("Cursor at %ld x, %ld y.\n",xpos,ypos);
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

		// Navigating the document:
		case 'u' : {
			if (!ypos) break;
			ypos--;
			break;
		}
		case 'd' : { //TODO: find doc ylen; limit dis.
			ypos++;
			break;
		}
		case 'l' : {
			if (!xpos) break;
			xpos--;
			break;
		}
		case 'r' : { //TODO: check curr line xlen b4 ++
			xpos++;
			break;
		}

		// Default option, if command is invalid:
		default : {
			printf("Unknown command %c.\n",function);
			break;
			}
		}
	}

	// Cleanup code

	// Closing and saving the file:
	fclose(urfile);

	// Stop execution
	return errcode;

}

	// Extra functions called from the main loop:

void insmode(){
	char stdinchars[20];
	printf("You\'re using insert mode. 20 chars max.\n");
	scanf("%s",stdinchars);
	printf("Found chars:%s\n",stdinchars);
	return;
}
