
// External Libs
#include "../include/dlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    Node *head = NULL;
    DLIST_insertEnd(&head, "Hello");
    DLIST_insertEnd(&head, "World!");

    DLIST_display(head);
    DLIST_cleanup(head);
    return 0;
}