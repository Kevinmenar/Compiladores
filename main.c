#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** fileReader (char * path) {
    FILE * fl;
    long fl_size;
    char * buffer;
    size_t res;

    fl = fopen ( path , "r+" );
    if (fl==NULL) {
        fprintf (stderr, "File error\n"); 
        exit (1);
    }

    fseek (fl , 0 , SEEK_END);
    fl_size = ftell (fl);
    rewind (fl);

    buffer = (char*) malloc (sizeof(char)*fl_size);
    if (buffer == NULL) {
        fputs ("Memory error",stderr); 
        exit (2);
    }

    res = fread (buffer,1,fl_size,fl);
    if (res != fl_size) {
        fputs ("Reading error",stderr); 
        exit (3);
    }

    char ** arrayString = malloc(10 * sizeof(char*));;
    char * strtok_res;
    strtok_res = strtok(buffer, " ");
    int cont = 0;
    while (strtok_res != NULL)
    {
        printf ("%s\n", strtok_res);
        arrayString[cont] = strtok_res;
        strtok_res = strtok (NULL, " ");
        cont++;
    }

    fclose (fl);
    free (buffer);

}

int main () {

	char * file = "test.txt";
	char ** listString = fileReader (file);
    return 0;
}