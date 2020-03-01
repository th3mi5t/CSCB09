/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */
/*
Jason Yu
Feb.29,2020
CSCB09
yujason9
*/
#include <stdio.h>
#include <string.h>

#include "utils.h"


/*
 * Tokenize the string stored in cmd based on DELIMITERS as separators.
 * Return the number of tokens, and store pointers to them in cmd_argv.
 */
int tokenize(char *cmd, char **cmd_argv) {
int count = 0;
      char *start_token = strtok(cmd, DELIMITERS);
       while( start_token != NULL ) {
    cmd_argv[count] = start_token; //Assigns current token pointer to current array
    count++;
      start_token = strtok(NULL, DELIMITERS);
   }
    return count;
}
