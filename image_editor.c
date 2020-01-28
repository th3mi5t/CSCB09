/*Jason Yu
yujason9
CSCB09
*/
#include <stdio.h>
#include <stdlib.h>
/*
 * Include the function prototypes of all those functions implemented in image_processing.c.
 * Do not remove or modify them in any way.
 */

void remove_red();
void convert_to_black_and_white();
void instagram_square();

int main(int argc, char *argv[]) {
        /* Task 1 needs to be completed here: Make sure that the command line arguments are correct. In case an error exists,
         * print the error message and terminate the program. Otherwise, invoke the corresponding
         * image processing function. */
		if(argc == 1){//Checks for at least one command
		printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.");
				return 1;
		}
		if(argv[1][0] == '1'){ //Checks command for 1, being red removal
		remove_red();
		}
		else if(argv[1][0] == '2'){ //Same as above, checks for black/white
		convert_to_black_and_white();
		}
		else if(argv[1][0] == '3'){//Checks for insta square
		instagram_square();
		} else {//Returns error message
			printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.");
				return 1;
		}
	
        return 0;
}
