#include <stdio.h>

	// Declarations

void insmode(unsigned int currxpos,unsigned int currypos,char str4ed[25]);
		/* ^ File insertion mode.
		 * How to use:
		 * Append 'i' to the start
		 * of the string u wanna add
		 * then write it normally.
		 * Special chars noted with \* as in C.
		*/

int main(){

	// Program startup

	// These store your current position in the file:
	long unsigned int xpos = 0,ypos = 0;

	// Error code. Will be 1 if no errors. Not std, sorry
	int errcode = 0;

	// Command to be run, only way of input
	char function = 0;

	// What is displayed when 'h' is pressed.
	char helpmsg[] = "Command list: q to quit\n";

	// Current string. Temp implementation.
	char currstr[25];

	// File pointer, idk how this works but ig 'tis std
	FILE * urfile;

	// File loading. TODO: take name from cmdargs.
	urfile = fopen("test.txt", "r");

	// Empty file prevention:
	if (urfile == NULL) return 1;

	// Put first string of file in RAM:
	fgets(currstr, 25, urfile);
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
			insmode(xpos,ypos,currstr);
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

	// Making sure normal execution is 0 as it should
	if (errcode == 1) return 0;

	// Stop execution
	return errcode;

}

	// Extra functions called from the main loop:

void insmode(unsigned int currxpos, unsigned int currypos, char str4ed[25]){

	// RAM init:
	char streamedinchars[20];

	// Wait for input: TODO: put hard char limit
	printf("You\'re using insert mode. 20 chars max.\n");

	// Okay, so, i am BAFFLED this is also a standard
	// C thing, but to limit how many letters are read,
	// between the % sign and vartype id, you tell it
	// the length you wanna read. Minus one.
	// Ex.: %50s can read 51 chars of a string. ..weird.
	// BUG/INTENDED STANDARD C FUNCTIONALITY:
	// This will not absorb what comes next in iostream
	// So anything over 20 chars gets interpreted
	// as input. I do not know how to fix this,
	// please help!
	scanf("%19s",streamedinchars);

	// Echo saved stdin (debug)
	printf("Found chars:%s\n",streamedinchars);

	// Remember how many letters were entered
	// this is how we figure out the length of the transfer
	char insstrlen = 0;
	while(streamedinchars[insstrlen] != '\0'){
		insstrlen++;
	}

	// This starts adding the chars we inputted
	// starting from our xpos in the string.
	// Currently overwrites text there (replace mode)
	// TODO: add insert mode (push back existing data)
	char z = 0; unsigned int i = currxpos;
	while(i < currxpos + insstrlen){
		str4ed[i] = streamedinchars[z];
		i++;
		z++;
	}

	// Make sure string has a terminator
	// Bug: This allows it to go into unallocated
	// memory and still work fine, but it is not
	// in fact, fine.
	// Fix: add length check BEFORE concatenating strs.
	if (insstrlen + currxpos >= 25){
		str4ed[i] = '\0';
	}

	// Go back to main loop.
	return;
}
