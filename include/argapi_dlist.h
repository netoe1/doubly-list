#ifndef ARGAPI_DLIST_H_
#define ARGAPI_DLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_REQUIRED 1
#define ARG_NOT_REQUIRED 0
#define BUFFER_LIMIT 255
typedef int REQUIRE_TYPE;
typedef unsigned int POSITION_LIST;

typedef struct node
{
    char data[BUFFER_LIMIT];
    REQUIRE_TYPE required_or_not;
    struct node *prev;
    struct node *next;
} ARGAPI_DLIST_ARG;

void ARGAPI_DLIST_insertEnd(ARGAPI_DLIST_ARG **head, const char *data, const REQUIRE_TYPE required_or_not);
void ARGAPI_DLIST_insertStart(ARGAPI_DLIST_ARG **head, const char *data, const REQUIRE_TYPE required_or_not);
void ARGAPI_DLIST_insertMiddle(ARGAPI_DLIST_ARG **head, const char *data, const REQUIRE_TYPE required_or_not, int position);
void ARGAPI_DLIST_deleteNode(ARGAPI_DLIST_ARG **head, ARGAPI_DLIST_ARG *toDelete);
void ARGAPI_DLIST_display(ARGAPI_DLIST_ARG *head);
void ARGAPI_DLIST_cleanup(ARGAPI_DLIST_ARG *head);
ARGAPI_DLIST_ARG *ARGAPI_DLIST_search(ARGAPI_DLIST_ARG *head, const char *target);

#endif