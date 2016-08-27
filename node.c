
#include <sys/types.h>
#include <sys/param.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "node.h"


//struct node *head = NULL;
//struct node *curr = NULL;

struct node* create_list(struct node *head, char * name, long long value)
{
    printf("\n creating list with headnode as [%d]\n",value);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->value = value;
    ptr->name = name;
    ptr->next = NULL;

    head = ptr;
    return ptr;
}

struct node* add_to_list(struct node *head, char * name, long long value, bool add_to_end)
{
    struct node *curr = last_node(head);
    if(NULL == head)
    {
        return (create_list(head, name, value));
    }

    //if(add_to_end)
        //printf("\n Adding node to end of list with value [%d]\n",value);
    //else
        //printf("\n Adding node to beginning of list with value [%d]\n",value);

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->name = name;
    ptr->value = value;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return head;
}

struct node * last_node(struct node *head)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    
    return tmp;
};

//struct node* search_in_list(struct node *head, int value, struct node **prev)
struct node* search_in_list(struct node *head, long long value)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",value);

    while(ptr != NULL)
    {
        if(ptr->value == value)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        //if(prev)
            //*e = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

void printNames (struct node *list_numbers, struct node *txt)
{
    struct node *ptr = txt;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        createStringNumber (list_numbers, ptr->name);
        tmp = ptr;
        ptr = ptr->next;
    }

}

char * lower_conver (char * name){
    int i = 0;
    char name2[15];
    strcpy(name2, name);

    while( name2[i] ) 
    {
      name2[i] = (tolower(name2[i]));
      i++;
    }

    char * copy = malloc(strlen(name2) + 1);
    strcpy(copy, name2);
    return copy;
}

int int_lenght (int number){
    return floor(log10(abs(number))) + 1;
}

char * createStringNumber (struct node *list_numbers, char * line){
    int cont = 0;
    int flag = 0;
    const char s[1] = " ";
    char *token_anterior;
    char *token;
    long long temp = 0;
    long long tempMax = 0;
    long long total = 0;
    long long ultraTotal = 0;

    token = strtok(line, " ");
    while(token != NULL)
    {
        token = lower_conver (token);
        if (strcmp(token, "y") == 0 && (30 < temp < 100)) {
            cont = cont + 1;
            token = strtok(NULL,s);
            continue;
        }
        else {
            if ((is_in_list(list_numbers, token) == 1)) {
                int number = search_name(list_numbers, token);
                if (temp == 0) {
                    temp = number;
                    total = number;
                    if(number == 1000000){ //Para este caso deberia escribir una lista donde este tipo de saltos, ya esta implementado en funcion
                        ultraTotal = total + ultraTotal;
                        total = 0;
                        tempMax = 0;
                        temp = 0;
                    }
                }
                else {
                    if (number >= 1000 && number > temp){
                        if (tempMax < temp*number){
                            tempMax = total*number;
                            total = total*number;
                            temp = number;
                            if(number == 1000000){ //Para este caso deberia escribir una lista donde este tipo de saltos, ya esta implementado en funcion
                                ultraTotal = total + ultraTotal;
                                total = 0;
                                tempMax = 0;
                                temp = 0;
                            }
                            if (((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "un") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "mil") == 0)) || ((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "millon") == 0)) || ((strcmp(token_anterior, "veintiuno") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "ciento") == 0) && ( (strcmp(token, "mil") == 0))) || ((strcmp(token_anterior, "ciento") == 0) && ( (strcmp(token, "millones") == 0))) || ( (1000000>temp>1) && ( (strcmp(token, "millon") == 0)))) {
                                flag = 1;
                                printf("Error in the token %d ", cont);
                                printf(" Token con inconsistencias %s \n",token);
                                break;
                            }
                        }
                        else{
                            flag = 1;
                            printf("Error in the token %d ", cont);
                            printf(" Token con inconsistencias %s \n",token);
                            break;
                        }
                    }
                    else{
                        if (number < 1000 && (int_lenght (temp) > int_lenght (number))){
                            total = total + number;
                            temp = number;
                            if (((strcmp(token_anterior, "cien") == 0) && ( 0 < number < 100))) {
                                flag = 1;
                                printf("Error in the token %d ", cont);
                                printf(" Token con inconsistencias [%s] \n",token);
                                break;
                            }
                        }
                        else{
                            flag = 1;
                            printf("Error in the token %d ", cont);
                            printf(" Token con inconsistencias [%s] \n",token);
                            break;
                        }
                    }
                }
            }
            else {
                flag = 1;
                printf("Error in the token %d ", cont);
                printf("  Token con inconsistencias [%s] \n",token);
                break;
            }
        }
        cont = cont + 1;
        token_anterior = token;
        token = strtok(NULL,s);
    }
    if ((strcmp(token_anterior, "ciento") != 0)) {
        if (flag != 1){
            ultraTotal = total + ultraTotal;
            printf("The ultraTotal is %lu \n", ultraTotal);
        }
    }
    else {
        printf("Error in the token %d ", cont);
        printf("  Token con inconsistencias [%s] \n",token_anterior);
    }
}


int is_in_list(struct node *head, char * name)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        
        if(strcmp(ptr->name, name) == 0)
        {
            return 1;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    return 0;
}

long long  search_name(struct node *head, char * name)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            return ptr->value;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    return 0;
}

void print_list(struct node *head)
{
    struct node *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->value);
        printf("\n [%s] \n",ptr->name);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}