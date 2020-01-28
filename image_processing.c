#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
	int count = 0;
	int input;
	char magic_num[2];
	scanf("%s", &magic_num);//Finds and prints magic number
	printf("%s ", magic_num);
 while (scanf("%d", input) != EOF){
	count++; // Keeps track of the current string

	if (count > 4 && (count % 3) == 2) {//Calculation to see if it is on the R column of RGB
	printf("0 ");//if so changes to 0 (removes red)
	}
	else{
	printf("%d ",input);//Prints as normally
	}
 }
 
}

/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
	
 	int count = 1;
	int sum = 0;
	int col = 0;
	int pixel = 0;
	int average = 0;
	char input[3];
	scanf("%s", input);//Finds and prints magic number
	printf("%s ", input);
 while (scanf("%d", &pixel) != EOF){//Starts reading input after magic number
	count++; // Keeps track of the current string
	if (count > 4) {//Checks if it is now in image pixels
	sum = sum + pixel;
	col++;
	if(col == 3){//First set of RGB passed
	average = sum / 3; //Calculates and prints average
	printf("%d %d %d ", average, average, average);
	col = 0;//Reset for next column
	sum = 0;
	}
	}
	else{
	printf("%d ",pixel);//Prints as normally, particularly header info
	} 
}
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
	
 	int count = 1;//Tracks the (index) of the input, One added to count for magic number
	char input[3];
	int pixel = 0;
	int old_col;
	int old_row;
	int col = 0;
	int row = 0;
	scanf("%s", input);//Scans and prints magic number
	printf("%s ", input);
	int pixel_count;
 while (scanf("%d", &pixel) != EOF){//Starts reading input after magic number
	count++; // Keeps track of the current string
	if(count == 2 && pixel > 4) {
		old_col = pixel;
		pixel = 4;
		printf("%d ", pixel);
	}
	else if(count == 3 && pixel > 4){
		old_row = pixel;
		pixel = 4;
		printf("%d ", pixel);
	}
	else if (count == 2  && pixel < 3) {
		
	else if(count == 4) {
		printf("%d ", pixel);
	}
	else if (count > 4) {//Checks if it is now in image pixels
		pixel_count++;
		if(pixel_count <= )
	}
}
 
}

