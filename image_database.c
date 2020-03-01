/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */
/*
Jason Yu
Feb.18, 2020
CSCB09
yujason9
*/
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "utils.h"

int main(void) {

        // char array to hold a line of input
	char buf[BUFFER_SIZE] = {'\0'};

        // char* array to hold the pointers to tokens
	char *args[INPUT_ARG_MAX_NUM];

        // the root of the tree
        struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;

	struct TreeNode *root_ptr = &root;

        // Add your code below:
		int tokenize_value;
	while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
		tokenize_value = tokenize(buf, args);
		if((tokenize_value == 5) && (args[0][0] == 'i')){
			tree_insert(root_ptr, args);
		}
		else if((tokenize_value == 4) && (args[0][0] == 'q')){
			tree_search(root_ptr, args);
		}
		else if((tokenize_value == 1) && (args[0][0] == 'p')){
			if(root_ptr->child != NULL) {
			tree_print(root_ptr);
			}else{
				printf("(null)");
			}
		}		
		else {
			fprintf(stderr, "Invalid command.\n");
		}
		}
        return 0;		
	}


