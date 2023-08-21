
#include "../include/argapi_dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    ARGAPI_DLIST_ARG *argumento = NULL;
    ARGAPI_DLIST_insertEnd(&argumento, "Hello", ARG_NOT_REQUIRED);
    ARGAPI_DLIST_insertEnd(&argumento, "World", ARG_NOT_REQUIRED);
    ARGAPI_DLIST_display(argumento);
    ARGAPI_DLIST_cleanup(argumento);
    return 0;
}