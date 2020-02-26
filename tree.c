/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


/**
 *  A helper function that allocates a new tree node.
 *
 *  @param value The entry's value. It represents either an attribute or a filename.
 *  @return A pointer to the newly allocated node.
 *  (for now it returns NULL, so the compiler does not complain)
 */
struct TreeNode *allocate_node(const char *value) {
	struct TreeNode *new_node = malloc(sizeof(struct TreeNode));
	new_node -> value = malloc(sizeof(value) + 1);//Allocating size of the string value + 1 for EOF delimiter 
	strcpy(new_node->value, value);
	return new_node;
}

/**
 *  Insert a new image to a tree
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array, whose first three members are the attribute values for 
 *                the image and the last one is the filename
 */
void tree_insert(struct TreeNode *root, char **values) {
	struct TreeNode *prev;
	struct TreeNode *new_node;
		if(root->sibling == NULL && root->child == NULL){//Adding first image if there is none.
			root->child = allocate_node(values[0]);
			root->child->child = allocate_node(values[1]);
			root->child->child->child = allocate_node(values[2]);
			root->child->child->child->child = allocate_node(value[3]);
			return 0;
		}
		root = root -> child; //Changes head to the first actual image in the tree
		new_node = traverse_level(root, values[0]);//Traverses first level of the tree, returns pointer to the new_node or the sibling of that level
		new_node = traverse_level(new_node->child, values[1]);//Traverses second level, as above.
		new_node = traverse_level(new_node->child, values[2]);//Traverses second level, as above.
		new_node = traverse_level(new_node->child, values[3]);//Traverses second level, as above.
				
}
/**
 *  Traverses a level of the tree and checks whether the value is already present or not.
	If present, returns a pointer to that node. Otherwise creates a new sibling for that level
	ande returns it.
 *
 *  @param tree A pointer to the root of the tree level, the one that holds a pointer to the first sibling
 *  @param value A string value that is checked to see if it exists in the tree on this level.
	@return either the pre-existing node or a newly inserted sibling
 */
struct TreeNode *traverse_level(struct TreeNode *root, char *value){
struct TreeNode *temp = root;//Temp node to traverse the level
while(temp != NULL){
if(strcmp(temp->value,value) == 0){	//If value is already present on level
return temp;//returns a pointer for that attribute/image
} else {
	root= root-> sibling;//Checks siblings
}
}
//Value is not present, prompting a new node to be inserted.
struct TreeNode *prev = root;//Node to previous sibling
while(root != NULL){	
	if(strcmp(value,root->value) < 0){//If new value is less than pre-existing
		struct TreeNode *new_node = allocate_node(value); //Adds a sibling before root
		new_node -> sibling = root; //New node is siblings with the old root in this case
		prev->child = new_node; //Changes root to point to the new node
		return new_node;
	}else if(strcmp(value,root->value) > 0){
		prev = root;
		root = root->sibling;
	}
}
	//Below runs if the new value is greater than all other siblings in ascii value
	root = allocate_node(value); //Previous while loop would have set root to be its sibling, which is null currently
	prev -> sibling = new_node; 
	return root; //Returns the new node
}

/**
 *  Searches a tree to print all files with matching attribute values.
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array of attribute values
 */
void tree_search(const struct TreeNode *root, char **values) {
	int level_index = 0;
    root = root->child; //Increments root to start at first value, not "" value
    while(root != NULL && level_index != 3){
        if(strcmp(values[level_index],root->value) == 0){//If the value of that level is found, advances down that child
            root = root->child;
            level_index++;//Increases level to next one
            }else if(strcmp(values[level_index],root->value) > 0){
        root = root->sibling;
    }
    else {
        fprintf(stderr, "File not found.");
        root = NULL;
    }
    }
    //At this point traversal should be at the last level of the tree, where files are located
while(root != NULL){//Loops all siblings of the file level, as to reach this point either root is null or the wanted attributes are found
printf(("%s ", root->value);
root = root->sibling;
}
}

/**
 *  Prints a complete tree to the standard output.
 *
 *  @param tree A pointer to the root of the tree.
 */
void tree_print(const struct TreeNode *tree) {
}
