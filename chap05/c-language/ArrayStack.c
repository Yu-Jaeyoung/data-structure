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

    // printf("currentCount 초기값은 %d입니다.\n", pReturn->currentCount);
    // currentCount 초기값이 무엇인지 궁금하여 작성

    pReturn->pData = (ArrayStackNode *) malloc(sizeof(ArrayStackNode) * size);
    memset(pReturn->pData, 0, sizeof(ArrayStackNode) * size);

    return pReturn;
}

int isArrayStackFull(ArrayStack *pStack) {
    int ret = 0;
    if (pStack != NULL) {
        if (pStack->currentCount == pStack->maxCount) {
            ret = 1;
        }
    }
    return ret;
}

int pushAS(ArrayStack *pStack, char data) { // ret 변수 선언 -> 직접 반환 변경
    if (isArrayStackFull(pStack) == 0) {
        pStack->pData[pStack->currentCount].data = data;
        pStack->currentCount++;
        return 1;
    } else {
        printf("오류 스택이 가득 찼습니다. pushAS()\n");
    }
    return 0;
}

int isArrayStackEmpty(ArrayStack *pStack) {
    int ret = 0;
    if (pStack != NULL) {
        if (pStack->currentCount == 0) {
            ret = 1;
        }
    }
    return ret;
}

ArrayStackNode *popAS(ArrayStack *pStack) {
    ArrayStackNode *pReturn = NULL;
    if (isArrayStackEmpty(pStack) == 0) {
        pReturn = (ArrayStackNode *) malloc(sizeof(ArrayStackNode));
        if (pReturn != NULL) {
            pReturn->data = pStack->pData[pStack->currentCount - 1].data;
            pStack->currentCount--;
        } else {
            printf("오류, 메모리할당 popAS()\n");
        }
    }
    return pReturn;
}

ArrayStackNode *peekAS(ArrayStack *pStack) {
    ArrayStackNode *pReturn = NULL;
    if (pStack != NULL)
        if (isArrayStackEmpty(pStack) == 0)
            pReturn = &(pStack->pData[pStack->currentCount - 1]);
    return pReturn;
}

void deleteArrayStack(ArrayStack *pStack) {
    if (pStack != NULL) {
        if (pStack->pData != NULL) {
            free(pStack->pData);
        }
        free(pStack);
    }
}

void displayArrayStack(ArrayStack *pStack) {
    int i = 0;
    if (pStack != NULL) {
        int size = pStack->maxCount;
        int top = pStack->currentCount;

        printf("스택의 크기 : %d, 현재 노드 개수 : %d\n", pStack->maxCount, pStack->currentCount);

        for (i = size - 1; i >= top; i--) {
            printf("[%d]-[Empty]\n", i);
        }

        for (i = top - 1; i >= 0; i--) {
            printf("[%d]-[%c]\n", i, pStack->pData[i].data);
        }
    }
}

int main() {
    ArrayStack *pStack = NULL;
    ArrayStackNode *pNode = NULL;

    pStack = createArrayStack(6);
    if (pStack != NULL) {
        pushAS(pStack, 'A');
        pushAS(pStack, 'B');
        pushAS(pStack, 'C');
        pushAS(pStack, 'D');
        displayArrayStack(pStack);

        pNode = popAS(pStack);
        if (pNode != NULL) {
            printf("\nPop 값-[%c]\n\n", pNode->data);
            free(pNode);
        }

        displayArrayStack(pStack);

        pNode = peekAS(pStack);
        if (pNode != NULL) {
            printf("\nPeek 값-[%c]\n\n", pNode->data);
        }
        displayArrayStack(pStack);

        deleteArrayStack(pStack);
    }
    return 0;
}