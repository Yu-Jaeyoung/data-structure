#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"

int isLinkedQueueEmpty(LinkedQueue *pQueue) {
    int ret = 0;

    if (pQueue != NULL) {
        if (pQueue->currentCount == 0) {
            ret = 1;
        }
    }
    return ret;
}

LinkedQueue *createLinkedQueue() {
    LinkedQueue *pReturn = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    memset(pReturn, 0, sizeof(LinkedQueue));

    return pReturn;
}

int enqueueLQ(LinkedQueue *pQueue, int data) {
    int ret = 0;
    LinkedQueueNode *pNode = NULL;

    pNode = (LinkedQueueNode *) malloc(sizeof(LinkedQueueNode));
    if (pNode != NULL) {

        pNode->data = data;
        pNode->pLink = NULL;

        if (isLinkedQueueEmpty(pQueue) == 0) {
            pQueue->pRear->pLink = pNode;
            pQueue->pRear = pNode;
        } else {
            pQueue->pFront = pNode;
            pQueue->pRear = pNode;
        }
        pQueue->currentCount++;
        ret = 1;

        return ret;
    }

    return ret;
}

LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue) {
    LinkedQueueNode *pReturn = NULL;
    if (isLinkedQueueEmpty(pQueue) == 0) {
        pReturn = pQueue->pFront;
        pQueue->pFront = pQueue->pFront->pLink;
        pReturn->pLink = NULL;

        pQueue->currentCount--;
    }

    if (isLinkedQueueEmpty(pQueue) == 1) {
        pQueue->pRear = NULL;
    }
    return pReturn;
}

LinkedQueueNode *peekLQ(LinkedQueue *pQueue) {
    LinkedQueueNode *pReturn = NULL;
    if (pQueue != NULL) {
        if (isLinkedQueueEmpty(pQueue) == 0) {
            pReturn = pQueue->pFront;
        }
    }
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue *pQueue) {
    LinkedQueueNode *pNode = NULL;
    LinkedQueueNode *pDelNode = NULL;

    if (pQueue != NULL) {
        pNode = pQueue->pFront;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pQueue);
    }
}

void displayLinkedQueue(LinkedQueue *pQueue) {
    LinkedQueueNode *pNode = NULL;
    int i = 0;
    if (pQueue != NULL) {
        printf("?????? ?????? ?????? : %d\n", pQueue->currentCount);
        pNode = pQueue->pFront;
        while (pNode != NULL) {
            printf("[%d]-[%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}