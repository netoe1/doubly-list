#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dlist.h"
Node *DLIST_createNode(const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        strcpy(newNode->data, data);
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void DLIST_insertEnd(Node **head, const char *data)
{
    Node *newNode = DLIST_createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void DLIST_insertStart(Node **head, const char *data)
{
    Node *newNode = DLIST_createNode(data);
    if (*head != NULL)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void DLIST_insertMiddle(Node **head, const char *data, int position)
{
    if (position <= 0)
    {
        DLIST_insertStart(head, data);
        return;
    }

    Node *newNode = DLIST_createNode(data);
    Node *current = *head;
    int count = 0;
    while (count < position - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        insertEnd(head, data);
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

void DLIST_deleteNode(Node **head, Node *toDelete)
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

void DLIST_display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%s <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void DLIST_cleanup(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

Node *DLIST_search(Node *head, const char *target)
{
    Node *current = head;
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

// Using example

/*
int main() {
     Node* head = NULL;

    insertEnd(&head, "World");
    insertStart(&head, "Hello");
    insertEnd(&head, "Linked");
    insertMiddle(&head, "Doubly", 1);
    insertMiddle(&head, "Awesome", 2);

    printf("Original Doubly Linked List: ");
    display(head);

    // Deleting the node containing "Doubly"
     Node* nodeToDelete = head->next->next->next;
    deleteNode(&head, nodeToDelete);

    printf("Doubly Linked List after deletion: ");
    display(head);

    cleanup(head);

    return 0;
}


*/