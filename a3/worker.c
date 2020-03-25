#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <math.h>
#include <float.h>
#include "worker.h"


/*
 * Read an image from a file and create a corresponding 
 * image struct 
 */

Image* read_image(char *filename)
{
	FILE *fp;
	Image *img = malloc(sizeof(Image));
	char buf[4];
	fp = fopen(filename, "r");
	 if(fp == NULL)
    {
        fprintf(stderr,"Error opening file\n");
        exit(1);
    }
	fgets(buf, 4, fp);
	if(buf[0] != 'P' || buf[1] != '3'){
		fprintf(stderr, "Error, magic number incorrect");
		free(img);
		return NULL;
	}
	fscanf(fp, "%d", &img->width);
	fscanf(fp, "%d", &img->height);
	fscanf(fp, "%d", &img->max_value);
	img->p = malloc(sizeof(Pixel) * (img->width *img->height));
	int i = 0;
	while(i < img -> height * img ->width){
	fscanf(fp, "%d", &img->p[i].red);
	fscanf(fp, "%d", &img->p[i].green);
	fscanf(fp, "%d", &img->p[i].blue);
	i++;
	}
fclose(fp);
return img;
}

/*
 * Print an image based on the provided Image struct 
 */

void print_image(Image *img){
        printf("P3\n");
        printf("%d %d\n", img->width, img->height);
        printf("%d\n", img->max_value);
       
        for(int i=0; i<img->width*img->height; i++)
           printf("%d %d %d  ", img->p[i].red, img->p[i].green, img->p[i].blue);
        printf("\n");
}

/*
 * Compute the Euclidian distance between two pixels 
 */
float eucl_distance (Pixel p1, Pixel p2) {
		return sqrt( pow(p1.red - p2.red,2 ) + pow( p1.blue - p2.blue, 2) + pow(p1.green - p2.green, 2));
}

/*
 * Compute the average Euclidian distance between the pixels 
 * in the image provided by img1 and the image contained in
 * the file filename
 */

float compare_images(Image *img1, char *filename) {
	Image *newimg = read_image(filename);
	int average = 0;
	if((img1->width == newimg->width) && (img1->height == newimg->height)){
		for(int i = 0; i < (img1->width * img1->height); i++){
			average += eucl_distance(img1->p[i],newimg->p[i]);
		}
		free(newimg);
		return ((float)average)/((float)(img1->width * img1->height));
	} else {
		free(newimg);
		return FLT_MAX;
	}
}

/* process all files in one directory and find most similar image among them
* - open the directory and find all files in it 
* - for each file read the image in it 
* - compare the image read to the image passed as parameter 
* - keep track of the image that is most similar 
* - write a struct CompRecord with the info for the most similar image to out_fd
*/
CompRecord process_dir(char *dirname, Image *img, int out_fd){
	DIR *dir = NULL;
	char path[PATHLENGTH];
	CompRecord Crec;
	strcpy(Crec.filename, " ");
	Crec.distance = FLT_MAX;
	if((dir = opendir(dirname)) == NULL) {
		perror("opendir");
		exit(1);
	}
	
	struct dirent *dp = NULL;
while((dp = readdir(dir)) != NULL) {
	if(strcmp(dp->d_name, ".") == 0 || 
		   strcmp(dp->d_name, "..") == 0 ||
		   strcmp(dp->d_name, ".svn") == 0){
			continue;
		}
		
		strncpy(path, dirname, PATHLENGTH);
		strncat(path, "/", PATHLENGTH - strlen(path) - 1);
		strncat(path, dp->d_name, PATHLENGTH - strlen(path) - 1);

	struct stat sbuf;
		if(stat(path, &sbuf) == -1) {
			//This should only fail if we got the path wrong
			// or we don't have permissions on this entry.
			perror("stat");
			exit(1);
		} 
		
		if(S_ISREG(sbuf.st_mode)) {
			
					float temp = compare_images(img, path);
					if(temp < Crec.distance){
						strcpy(Crec.filename, dp->d_name);
						Crec.distance = temp;
					}
		}		
}
closedir(dir);
        return Crec;
}
/*
int main(int argc, char **argv) {
	Image *img = read_image("./tinypix.ppm");
	CompRecord rec = process_dir("./test", img, STDOUT_FILENO);
	printf("%s %f\n", rec.filename, rec.distance);
}
*/
	
