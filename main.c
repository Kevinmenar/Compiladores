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

struct node * fileReader (char * path, struct node *node_txt) {

    struct node *ptr = NULL;
    FILE *fp = fopen(path, "r");
    const char s[1] = " ";
    char *token;
    int i;
    if(fp != NULL)
    {
        char line[200];
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
    return ptr;
}

int main () {

	int i = 0;
	//long long temp = (long long)1000000 * (long long)999999;
	//printf("\n The first number is %lu ", temp);

	char * file = "test.txt";
	struct node *node_numbers = NULL;
	struct node *node_txt = fileReader (file, node_txt);

	node_numbers = add_to_list(node_numbers, "uno", 1, true);
	node_numbers = add_to_list(node_numbers, "un", 1, true);
	node_numbers = add_to_list(node_numbers, "dos", 2, true);
	node_numbers = add_to_list(node_numbers, "tres", 3, true);
	node_numbers = add_to_list(node_numbers, "cuatro", 4, true);
	node_numbers = add_to_list(node_numbers, "cinco", 5, true);
	node_numbers = add_to_list(node_numbers, "seis", 6, true);
	node_numbers = add_to_list(node_numbers, "siete", 7, true);
	node_numbers = add_to_list(node_numbers, "ocho", 8, true);
	node_numbers = add_to_list(node_numbers, "nueve", 9, true);
	node_numbers = add_to_list(node_numbers, "diez", 10, true);
	node_numbers = add_to_list(node_numbers, "once", 11, true);
	node_numbers = add_to_list(node_numbers, "doce", 12, true);
	node_numbers = add_to_list(node_numbers, "trece", 13, true);
	node_numbers = add_to_list(node_numbers, "catorce", 14, true);
	node_numbers = add_to_list(node_numbers, "quince", 15, true);
	node_numbers = add_to_list(node_numbers, "dieciseis", 16, true);
	node_numbers = add_to_list(node_numbers, "diecisiete", 17, true);
	node_numbers = add_to_list(node_numbers, "dieciocho", 18, true);
	node_numbers = add_to_list(node_numbers, "diecinueve", 19, true);
	node_numbers = add_to_list(node_numbers, "veinte", 20, true);
	node_numbers = add_to_list(node_numbers, "veintiuno", 21, true);
	node_numbers = add_to_list(node_numbers, "veintiun", 21, true);
	node_numbers = add_to_list(node_numbers, "veintidos", 22, true);
	node_numbers = add_to_list(node_numbers, "veintitres", 23, true);
	node_numbers = add_to_list(node_numbers, "veinticuatro", 24, true);
	node_numbers = add_to_list(node_numbers, "veinticinco", 25, true);
	node_numbers = add_to_list(node_numbers, "veintiseis", 26, true);
	node_numbers = add_to_list(node_numbers, "veintisiete", 27, true);
	node_numbers = add_to_list(node_numbers, "veintiocho", 28, true);
	node_numbers = add_to_list(node_numbers, "veintinueve", 29, true);
	node_numbers = add_to_list(node_numbers, "treinta", 30, true);
	node_numbers = add_to_list(node_numbers, "cuarenta", 40, true);
	node_numbers = add_to_list(node_numbers, "cincuenta", 50, true);
	node_numbers = add_to_list(node_numbers, "sencenta", 60, true);
	node_numbers = add_to_list(node_numbers, "setenta", 70, true);
	node_numbers = add_to_list(node_numbers, "ochenta", 80, true);
	node_numbers = add_to_list(node_numbers, "noventa", 90, true);
	node_numbers = add_to_list(node_numbers, "cien", 100, true);
	node_numbers = add_to_list(node_numbers, "ciento", 100, true);
	node_numbers = add_to_list(node_numbers, "docientos", 200, true);
	node_numbers = add_to_list(node_numbers, "trecientos", 300, true);
	node_numbers = add_to_list(node_numbers, "cuatrocientos", 400, true);
	node_numbers = add_to_list(node_numbers, "quinientos", 500, true);
	node_numbers = add_to_list(node_numbers, "seicientos", 600, true);
	node_numbers = add_to_list(node_numbers, "setecientos", 700, true);
	node_numbers = add_to_list(node_numbers, "ochocientos", 800, true);
	node_numbers = add_to_list(node_numbers, "novecientos", 900, true);
	node_numbers = add_to_list(node_numbers, "mil", 1000, true);
	node_numbers = add_to_list(node_numbers, "millon", 1000000, true);
	node_numbers = add_to_list(node_numbers, "millones", 1000000, true);

	//print_list(node_numbers);

	printNames (node_numbers, node_txt);

	free(node_numbers);
	free(node_txt);

    return 0;
}