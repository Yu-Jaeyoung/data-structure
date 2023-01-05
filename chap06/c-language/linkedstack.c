#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack *createLinkedStack() {
    LinkedStack *pReturn = (LinkedStack *) malloc(sizeof(LinkedStack));
    memset(pReturn, 0, sizeof(LinkedStack));
    return pReturn;
}

int pushLS(LinkedStack *pStack, char data) {
    LinkedStackNode *pNode = NULL;

    if (pStack != NULL) {
        pNode = (LinkedStackNode *) malloc(sizeof(LinkedStackNode));
        if (pNode != NULL) {
            pNode->data = data;
            pNode->pLink = pStack->pTop;
            pStack->pTop = pNode;

            pStack->currentCount++;
            return 1;
        } else {
            printf("오류, 메모리 할당, pushLS()\n");
        }
    }
    return 0;
}

int isLinkedStackEmpty(LinkedStack *pStack) {
    if (pStack != NULL) {
        if (pStack->currentCount == 0)
            return 1;
    }
    return 0;
}

LinkedStackNode *popLS(LinkedStack *pStack) {
    LinkedStackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == 0) {
            pReturn = pStack->pTop;
            pStack->pTop = pReturn->pLink;
            pReturn->pLink = NULL;

            pStack->currentCount--;
        }
    }
    return pReturn;
}

LinkedStackNode *peekLS(LinkedStack *pStack) {
    LinkedStackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == 0) {
            pReturn = pStack->pTop;
        }
    }
    return pReturn;
}

void deleteLinkedStack(LinkedStack *pStack) {
    LinkedStackNode *pNode = NULL;
    LinkedStackNode *pDelNode = NULL;

    if (pStack != NULL) {
        pNode = pStack->pTop;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pStack);
    }
}

void displayLinkedStack(LinkedStack *pStack) {
    LinkedStackNode *pNode = NULL;
    int i = 1;
    if (pStack != NULL) {
        printf("현재 노드 개수: %d\n", pStack->currentCount);
        pNode = pStack->pTop;
        while (pNode != NULL) {
            printf("[%d]-[%c]\n", pStack->currentCount - i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}