#ifndef DLIST_H_
#define DLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_REQUIRED 1
#define ARG_NOT_REQUIRED 0

typedef struct node
{
    char data[100];
    int required_or_not;
    struct node *prev;
    struct node *next;
} ARGAPI_DLIST_ARG;

ARGAPI_DLIST_ARG *DLIST_createNode(const char *data, const int required_or_not);
void ARGAPI_DLIST_insertEnd(ARGAPI_DLIST_ARG **head, const char *data, const int required_or_not);
void ARGAPI_DLIST_insertStart(ARGAPI_DLIST_ARG **head, const char *data, const int required_or_not);
void ARGAPI_DLIST_insertMiddle(ARGAPI_DLIST_ARG **head, const char *data, const int required_or_not, int position);
void ARGAPI_DLIST_deleteNode(ARGAPI_DLIST_ARG **head, ARGAPI_DLIST_ARG *toDelete);
void ARGAPI_DLIST_display(ARGAPI_DLIST_ARG *head);
void ARGAPI_DLIST_cleanup(ARGAPI_DLIST_ARG *head);
ARGAPI_DLIST_ARG *ARGAPI_DLIST_search(ARGAPI_DLIST_ARG *head, const char *target);

#endif