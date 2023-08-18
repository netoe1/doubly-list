#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[100];
    struct node *prev;
    struct node *next;
} Node;

Node *DLIST_createNode(const char *data);
void DLIST_insertEnd(Node **head, const char *data);
void DLIST_insertStart(Node **head, const char *data);
void DLIST_insertMiddle(Node **head, const char *data, int position);
void DLIST_deleteNode(Node **head, Node *toDelete);
void DLIST_display(Node *head);
void DLIST_cleanup(Node *head);
Node *DLIST_search(Node *head, const char *target);
#endif