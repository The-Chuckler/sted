#include <stdio.h>

int main(){

	// Program startup

	int errcode = 0;
	char function = 0;

	//Main loop

	while (!errcode){

		// Show file from RAM
		printf("\nFile contents here\n");

		// Ask for input
		printf("Command: ");
		scanf(" %c", &function);

		// We have input, lets determine the cmd:
		switch(function){
		case '0' : {
			errcode = 1;
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
