
#include <sys/types.h>
#include <sys/param.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "node.h"


struct node *head = NULL;
struct node *curr = NULL;

struct node* create_list(char * name, int value)
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

    head = curr = ptr;
    return ptr;
}

struct node* add_to_list(char * name, int value, bool add_to_end)
{
    if(NULL == head)
    {
        return (create_list(name, value));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",value);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",value);

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
    return ptr;
}

struct node* search_in_list(int value, struct node **prev)
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
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int delete_from_list(int value)
{
    struct node *prev = NULL;
    struct node *del = NULL;

    printf("\n Deleting value [%d] from list\n",value);

    del = search_in_list(value,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
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