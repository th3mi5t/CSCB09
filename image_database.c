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
	while(fgets(buf, BUFFER_SIZE, stdin) != EOF){
		if(tokenize(buf, args) == 6 && args[0] == 'i'){
			tree_insert(root, args);
		}

		else if(tokenize(buf, args) == 5 && args[0] == 'q'){
			tree_search(root, args);
		}
		else if(tokenize(buf, args) == 1 && args[0] == 'p'){
			tree_print(root);
		}		
		else {
			fprintf(stderr, "Invalid command.");
		}
		}
        return 0;		
	}


