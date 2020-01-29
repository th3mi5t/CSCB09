#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
	int count = 1;
	int input;
	char magic_num[3];
	scanf("%s", magic_num);//Finds and prints magic number
	printf("%s ", magic_num);
 while (scanf("%d", &input) != EOF){
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
	char magic_num[3];
	scanf("%s", magic_num);//Finds and prints magic number
	printf("%s ", magic_num);
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
	char magic_num[3];
	int pixel = 0;
	int col;
	int row;
	int old_col = 0;
	int col_count = 0;
	int row_count = 0;
	int temp_count = 0;
	scanf("%s", magic_num);//Scans and prints magic number
	printf("%s ", magic_num);
 while (scanf("%d", &pixel) != EOF){//Starts reading input after magic number
	count++; // Keeps track of the current string
	if((count == 2 || count == 3) && pixel <= 4) {
		if(count == 2){
		old_col = pixel;
		col = pixel;
		}
		if(count == 3) {
		row = pixel;
		}
		printf("%d ", pixel);
	}
	else if((count == 2 || count == 3) && pixel > 4){

		if(count == 2){
		old_col = pixel;
		pixel = 4;
		col = pixel;
		}
		if(count == 3) {
		pixel = 4;
		row = pixel;
		}
		printf("%d ", pixel);
	}
	if(count == 4) {
		printf("%d ", pixel);
	}
	else if (count > 4) {//Checks if it is now in image pixels
		col_count++;
		if(row_count < row){
		if(col_count <= 3*col){ //Total pixel count must be 144 or less.
		printf("%d ", pixel);
		}
		else if(col_count > 3*col) {
			temp_count = count ;
		while(count < temp_count + 3 * (old_col - col)){
		scanf("%d", &pixel);
		count++;
		}
		col_count = 1;
		row_count += 1;
		if(row_count != row){
		printf("%d ", pixel);
		}
		}
	}
	}
 }
}
 


