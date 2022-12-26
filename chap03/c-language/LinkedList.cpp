#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType {
    int data;
    struct LinkedListNodeType *pLink;
} LinkedListNode;