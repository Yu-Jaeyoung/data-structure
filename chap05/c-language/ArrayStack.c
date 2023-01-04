#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayStackNodeType {
    char data;
} ArrayStackNode;

typedef struct ArrayStackType {
    int maxCount;
    int currentCount;
    ArrayStackNode *pData;
} ArrayStack;

ArrayStack *createArrayStack(int size) {
    ArrayStack *pReturn = (ArrayStack *) malloc(sizeof(ArrayStack));
    memset(pReturn, 0, sizeof(ArrayStack));
    pReturn->maxCount = size;

    pReturn->pData = (ArrayStackNode *) malloc(sizeof(ArrayStackNode) * size);
    memset(pReturn->pData, 0, sizeof(ArrayStackNode) * size);

    return pReturn;
}