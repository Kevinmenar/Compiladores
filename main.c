#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void fileReader (char * path) {

    struct node *ptr = NULL;
    FILE *fp = fopen(path, "r");
    const char s[1] = " ";
    char *token;
    int i;
    if(fp != NULL)
    {
        char line[100];
        char ** arrayString = malloc(10 * sizeof(char*));
        while(fgets(line, sizeof line, fp) != NULL)
        {
        	strcpy(line, line);
    		removeChar(line, '\n');
    		char * copy = malloc(strlen(line) + 1);
    		strcpy(copy, line);
    		ptr = add_to_list(ptr, copy, 1, true);
        }
        fclose(fp);
    } else {
        perror(path);
    }    
    print_list(ptr);
    return 
}

int main () {

	int i = 0;

	char * file = "test.txt";
	fileReader (file);
	struct node *node_numbers = struct node_txt *ptr;
	struct node *node_txt = struct node_txt *ptr;

    return 0;
}