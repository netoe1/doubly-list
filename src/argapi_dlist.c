#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/argapi_dlist.h"

static ARGAPI_DLIST_ARG *ARGAPI_DLIST_createNode(const char *data, const REQUIRE_TYPE required_or_not)
{
    ARGAPI_DLIST_ARG *newNode = (ARGAPI_DLIST_ARG *)malloc(sizeof(ARGAPI_DLIST_ARG));
    if (newNode != NULL)
    {
        strcpy(newNode->data, data);
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->required_or_not = required_or_not;
    }
    return newNode;
}

void ARGAPI_DLIST_addArguments(ARGAPI_DLIST_ARG **head, const char *data, const REQUIRE_TYPE required_or_not)
{
    ARGAPI_DLIST_ARG *newNode = ARGAPI_DLIST_createNode(data, required_or_not);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ARGAPI_DLIST_ARG *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void ARGAPI_DLIST_insertStart(ARGAPI_DLIST_ARG **head, const char *data, const int required_or_not)
{
    ARGAPI_DLIST_ARG *newNode = ARGAPI_DLIST_createNode(data, required_or_not);
    if (*head != NULL)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void ARGAPI_DLIST_insertMiddle(ARGAPI_DLIST_ARG **head, const char *data, const REQUIRE_TYPE required_or_not, int position)
{
    if (position <= 0)
    {
        ARGAPI_DLIST_insertStart(head, data, required_or_not);
        return;
    }

    ARGAPI_DLIST_ARG *newNode = ARGAPI_DLIST_createNode(data, required_or_not);
    ARGAPI_DLIST_ARG *current = *head;
    int count = 0;
    while (count < position - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        ARGAPI_DLIST_addArguments(head, data, required_or_not);
    }
    else
    {
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void ARGAPI_DLIST_deleteNode(ARGAPI_DLIST_ARG **head, ARGAPI_DLIST_ARG *toDelete)
{
    if (*head == NULL || toDelete == NULL)
    {
        return;
    }

    if (*head == toDelete)
    {
        *head = toDelete->next;
    }

    if (toDelete->next != NULL)
    {
        toDelete->next->prev = toDelete->prev;
    }

    if (toDelete->prev != NULL)
    {
        toDelete->prev->next = toDelete->next;
    }

    free(toDelete);
}

void ARGAPI_DLIST_display(ARGAPI_DLIST_ARG *head)
{
    ARGAPI_DLIST_ARG *current = head;
    while (current != NULL)
    {
        printf("%s <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void ARGAPI_DLIST_cleanup(ARGAPI_DLIST_ARG *head)
{
    ARGAPI_DLIST_ARG *current = head;
    while (current != NULL)
    {
        ARGAPI_DLIST_ARG *temp = current;
        current = current->next;
        free(temp);
    }
}

ARGAPI_DLIST_ARG *ARGAPI_DLIST_search(ARGAPI_DLIST_ARG *head, const char *target)
{
    ARGAPI_DLIST_ARG *current = head;
    while (current != NULL)
    {
        if (strcmp(current->data, target) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Como usar o código!
/*
int main() {
     ARGAPI_DLIST_ARG* head = NULL;

    insertEnd(&head, "World");
    insertStart(&head, "Hello");
    insertEnd(&head, "Linked");
    insertMiddle(&head, "Doubly", 1);
    insertMiddle(&head, "Awesome", 2);

    printf("Original Doubly Linked List: ");
    display(head);

    // Deleting the node containing "Doubly"
     ARGAPI_DLIST_ARG* nodeToDelete = head->next->next->next;
    deleteNode(&head, nodeToDelete);

    printf("Doubly Linked List after deletion: ");
    display(head);

    cleanup(head);

    return 0;
}


*/