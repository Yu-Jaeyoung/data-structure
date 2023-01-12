/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayQueueNodeType {
    char data;
} ArrayQueueNode;

typedef struct ArrayQueueType {
    int maxCount;
    int currentCount;
    int front;
    int rear;
    ArrayQueueNode *pData;
} ArrayQueue;

int isArrayQueueFull(ArrayQueue *pQueue);

int isArrayQueueEmpty(ArrayQueue *pQueue);

ArrayQueue *createArrayQueue(int size) {
    ArrayQueue *pReturn = (ArrayQueue *) malloc(sizeof(ArrayQueue));
    memset(pReturn, 0, sizeof(ArrayQueue));
    pReturn->maxCount = size;
    pReturn->front = -1;
    pReturn->rear = -1;

    pReturn->pData = (ArrayQueueNode *) malloc(sizeof(ArrayQueueNode) * size);
    memset(pReturn->pData, 0, sizeof(ArrayQueueNode) * size);

    return pReturn;
}

int enqueueAQ(ArrayQueue *pQueue, char data) {
    int ret = 0;
    if (pQueue != NULL) {
        if (isArrayQueueFull(pQueue) == 0) {
            pQueue->rear++;
            pQueue->pData[pQueue->rear].data = data;
            pQueue->currentCount++;
            ret = 1;
        } else {
            printf("오류, 큐가 가득 찼습니다. enqueueAQ()\n");
        }
    }

    return ret;
}

int isArrayQueueFull(ArrayQueue *pQueue) {
    int ret = 0;

    if (pQueue != NULL) {
        if (pQueue->currentCount == pQueue->maxCount || pQueue->rear == pQueue->maxCount - 1) {
            ret = 1;
        }
    }
    return ret;
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue) {
    ArrayQueueNode *pReturn = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == 0) {
            pReturn = (ArrayQueueNode *) malloc(sizeof(ArrayQueueNode));
            if (pReturn != NULL) {
                pQueue->front++;
                pReturn->data = pQueue->pData[pQueue->front].data;
                pQueue->currentCount--;
            } else {
                printf("오류, 메모리할당, dequeueAQ()\n");
            }
        }
    }
    return pReturn;
}

int isArrayQueueEmpty(ArrayQueue *pQueue) {
    int ret = 0;
    if (pQueue != NULL) {
        if (pQueue->currentCount == 0) {
            ret = 1;
        }
    }
    return ret;
}

ArrayQueueNode *peekAQ(ArrayQueue *pQueue) {
    ArrayQueueNode *pReturn = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == 0) {
            pReturn = &(pQueue->pData[pQueue->front + 1]);
        }
    }
    return pReturn;
}

void deleteArrayQueue(ArrayQueue *pQueue) {
    if (pQueue != NULL) {
        if (pQueue->pData != NULL) {
            free(pQueue->pData);
        }
        free(pQueue);
    }
}

void displayArrayQueue(ArrayQueue *pQueue) {
    int i = 0;

    if (pQueue != NULL) {
        printf("큐의 크기 : %d, 현재 노드 개수 : %d\n", pQueue->maxCount, pQueue->currentCount);

        for (i = pQueue->front + 1; i <= pQueue->rear; i++) {
            printf("[%d]-[%c]\n", i, pQueue->pData[i].data);
        }
    }
}

int main() {
    ArrayQueue *pQueue = NULL;
    ArrayQueueNode *pNode = NULL;

    pQueue = createArrayQueue(4);
    if (pQueue != NULL) {

        enqueueAQ(pQueue, 'A');
        enqueueAQ(pQueue, 'B');
        enqueueAQ(pQueue, 'C');
        enqueueAQ(pQueue, 'D');
        displayArrayQueue(pQueue);

        pNode = dequeueAQ(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n", pNode->data);
            free(pNode);
        }
        displayArrayQueue(pQueue);

        pNode = peekAQ(pQueue);
        if (pNode != NULL) {
            printf("Peek Value-[%c]\n", pNode->data);
        }
        displayArrayQueue(pQueue);
        enqueueAQ(pQueue, 'E');
        displayArrayQueue(pQueue);
        deleteArrayQueue(pQueue);
    }
    return 0;
}*/
