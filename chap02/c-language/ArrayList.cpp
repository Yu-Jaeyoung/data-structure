#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define element int

typedef struct ArrayListNodeType {
    element data;
} ArrayListNode;

typedef struct ArrayListType {
    element maxCount;
    element currentCount;
    ArrayListNode *pData;
} ArrayList;

