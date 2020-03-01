/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */
/*
Jason Yu
Feb.29, 2020
yujason9
CSCB09
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
	new_node ->sibling = NULL;
	new_node ->child = NULL;
	new_node -> value = malloc(sizeof(value) + 1);//Allocating size of the string value + 1 for EOF delimiter 
	strcpy(new_node->value, value);
	return new_node;
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
struct TreeNode *temp = NULL;
temp = root->child;//Temp node to traverse the level
if(root->child == NULL){//If children are empty creates a new node for that level
	root->child = allocate_node(value);
	return root->child;
}

while(temp != NULL){
if(strcmp(temp->value,value) == 0){	//If value is already present on level
return temp;//returns a pointer for that attribute/image
} else {
	temp = temp -> sibling;//Checks siblings
}
}
//Value is not present, prompting a new node to be inserted.
struct TreeNode *prev = root;//Node to previous sibling, initially set as the parent
struct TreeNode *traversal = root -> child; //Lowers root one level to the one currently being searched.
	if(strcmp(value,traversal->value) < 0) { //Case for inserting a value less than the very first sibling
		struct TreeNode *new_node = allocate_node(value); 
		new_node -> sibling = traversal; 
		prev->child = new_node; 
		return new_node;
	}
	else {
	prev = traversal;
	traversal = traversal ->sibling;
	}
while(traversal != NULL){
	if(strcmp(value,traversal->value) < 0){//If new value is less than pre-existing
		struct TreeNode *new_node = allocate_node(value); //Adds a sibling between two values
		new_node -> sibling = traversal; //New node is siblings with the old sibling in this case
		prev->sibling = new_node; //Changes previous sibling to point to the new node
		return new_node;
	}else if(strcmp(value,traversal->value) > 0){
		prev = traversal; 
		traversal = traversal->sibling;
	}
}
	//Below runs if the new value is greater than all other siblings in ascii value
	traversal = allocate_node(value); //Previous while loop would have set root to be its sibling, which is null currently
	prev -> sibling = traversal; 
	return traversal; //Returns the new node
}
/**
 *  Insert a new image to a tree
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array, whose first three members are the attribute values for 
 *                the image and the last one is the filename
 */
void tree_insert(struct TreeNode *root, char **values) {
	struct TreeNode *new_node = NULL;
	
		if(root->sibling == NULL && root->child == NULL){//Adding first image if there is none.
			root->child = allocate_node(values[1]);
			root->child->child = allocate_node(values[2]);
			root->child->child->child = allocate_node(values[3]);
			root->child->child->child->child = allocate_node(values[4]);
		} else {	
		new_node = traverse_level(root, values[1]);//Traverses first level of the tree, returns pointer to the new_node or the sibling of that level
		new_node = traverse_level(new_node, values[2]);//Traverses second level, as above.
		new_node = traverse_level(new_node, values[3]);//Traverses third level, as above.
		new_node = traverse_level(new_node, values[4]);//Traverses last level, as above.
		}
}


/**
 *  Searches a tree to print all files with matching attribute values.
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array of attribute values
 */
void tree_search(const struct TreeNode *root, char **values) {
	struct TreeNode *node = NULL;
	int level_index = 1;
	if(root->child == NULL) {
		printf("(NULL)\n");
		return;
	}
    node = root->child; //Increments root to start at first value, not "" value
      
    while((node != NULL) && (level_index != 4)){   
        if(strcmp(values[level_index],node->value) == 0){//If the value of that level is found, advances down that child
		   node = node->child;
            level_index++;//Increases level to next one
        } else if(strcmp(values[level_index],node->value) > 0){
        node = node->sibling;
		if(node->sibling == NULL){//If terms not found
			printf("(NULL)\n");
			return;
		}
    }
    }
    //At this point traversal should be at the last level of the tree, where files are located
while(node != NULL){//Loops all siblings of the file level, as to reach this point either root is null or the wanted attributes are found
printf("%s ", node->value);
node = node->sibling;
}
printf("\n");
}
/**
 *  Prints a complete tree to the standard output.
 *
 *  @param tree A pointer to the root of the tree.
 */
void tree_print(const struct TreeNode *tree) {
	struct TreeNode *levelone = tree->child;
	struct TreeNode *leveltwo = NULL;
	struct TreeNode *levelthree = NULL;
	struct TreeNode *levelfour = NULL;
	struct TreeNode *one = NULL;
			struct TreeNode *two = NULL;
				struct TreeNode *three = NULL;
					struct TreeNode *four = NULL;
	if(levelone == NULL){
		printf("(NULL)\n");
		return;
	}
	while(levelone != NULL){//Traverses first level and siblings
	one = levelone;
	leveltwo = levelone->child;
	while(leveltwo != NULL){//Traverses first level and siblings
	two = leveltwo;
	levelthree = leveltwo->child;
	while(levelthree!= NULL){//Traverses first level and siblings
	three = levelthree;
	levelfour = levelthree->child;
	while(levelfour != NULL){//Traverses first level and siblings
	four = levelfour;
	printf("%s %s %s %s\n",one->value, two->value, three->value, four->value);;
	levelfour= levelfour->sibling;
	}
	levelthree = levelthree->sibling;
	}
	leveltwo = leveltwo->sibling;
	}
	levelone = levelone->sibling;
	}	
}
	
	
	
