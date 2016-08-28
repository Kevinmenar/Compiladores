#ifndef _SUDO_NODE_H
#define _SUDO_NODE_H

#include <string.h>
#include <stdbool.h>

struct node
{
    char * name;
    long long value;
    struct node *next;
};

struct node* create_list(struct node *head, char * name, long long value);
struct node* add_to_list(struct node *head, char * name, long long value, bool add_to_end);
struct node * last_node(struct node *head);
struct node* search_in_list(struct node *head, long long value);
void printNames (struct node *list_numbers, struct node *txt);
char * createStringNumber (struct node *list_numbers, char * line);
int is_in_list(struct node *head, char * name);
long long search_name(struct node *head, char * name);
//int delete_from_list(int value);
void print_list(struct node *head);
void dec2romanstr(long long num);

#endif /* _SUDO_NODE_H */