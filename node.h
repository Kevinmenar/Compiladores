#ifndef _SUDO_NODE_H
#define _SUDO_NODE_H

#include <string.h>
#include <stdbool.h>

struct node
{
    char * name;
    int value;
    struct node *next;
};

struct node* create_list(char * name, int value);
struct node* add_to_list(char * name, int value, bool add_to_end);
struct node* search_in_list(int value, struct node **prev);
int delete_from_list(int value);
void print_list(void);

#endif /* _SUDO_NODE_H */