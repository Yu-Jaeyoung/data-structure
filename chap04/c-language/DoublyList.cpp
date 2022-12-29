#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyListNodeType {
    int data;
    struct DoublyListNodeType *pLLink;
    struct DoublyListNodeType *pRLink;
} DoublyListNode;

typedef struct DoublyListType {
    int currentCount;
    DoublyListNode headerNode;
} DoublyList;

DoublyList *createDoublyList() {
    DoublyList *pReturn = (DoublyList *) malloc(sizeof(DoublyList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(DoublyList));

        pReturn->headerNode.pLLink = &(pReturn->headerNode);
        pReturn->headerNode.pRLink = &(pReturn->headerNode);
    }

    return pReturn;
}

int getDoublyListData(DoublyList *pList, int position) {
    int i = 0;

    DoublyListNode *pCurrentNode = &(pList->headerNode);
    for (; i <= position; i++) {
        pCurrentNode = pCurrentNode->pRLink;
    }
    return pCurrentNode->data;
}

int addDoublyListData(DoublyList *pList, int position, int data) {
    int i = 0;

    DoublyListNode *pNewNode = (DoublyListNode *) malloc(sizeof(DoublyListNode));
    if (pNewNode != NULL) {
        memset(pNewNode, 0, sizeof(DoublyListNode));
        pNewNode->data = data;

        DoublyListNode *pPreNode = &(pList->headerNode);

        for (; i < position; i++) {
            pPreNode = pPreNode->pRLink;
        }

        pNewNode->pRLink = pPreNode->pRLink;
        pNewNode->pLLink = pPreNode;
        pPreNode->pRLink = pNewNode;
        pPreNode->pRLink->pLLink = pNewNode;

        pList->currentCount++;
    } else {
        printf("오류, 메모리 할당 addListData()\n");
        return 1;
    }

    return 0;
}

int removeDoublyListData(DoublyList *pList, int position) {
    int i = 0;
    DoublyListNode *pPreNode = &(pList->headerNode);
    for (; i < position; i++) {
        pPreNode = pPreNode->pRLink;
    }
    DoublyListNode *pDelNode = pPreNode->pRLink;

    pPreNode->pRLink = pDelNode->pRLink;
    pDelNode->pRLink->pLLink = pPreNode;

    free(pDelNode);
    pList->currentCount--;

    return 0;
}

int getDoublyListLength(DoublyList *pList) {
    int ret = 0;
    if (pList != NULL) {
        ret = pList->currentCount;
    }
    return ret;
}

void displayDoublyList(DoublyList *pList) {
    int i = 0;
    DoublyListNode *pNode = pList->headerNode.pRLink;
    if (0 == pList->currentCount) {
        printf("자료가 없습니다.\n");
    } else {
        printf("노드 개수: %d\n", pList->currentCount);

        for (; i < pList->currentCount; i++) {
            printf("[%d],%d\n", i, pNode->data);
            pNode = pNode->pRLink;
        }
    }
}

void deleteDoublyList(DoublyList *pList) {
    if (pList != NULL) {
        while (pList->currentCount > 0) {
            removeDoublyListData(pList, 0);
        }
        free(pList);
    }
}

int main() {
    DoublyList *pList = createDoublyList();
    if (pList != NULL) {
        addDoublyListData(pList, 0, 10);
        addDoublyListData(pList, 1, 20);
        addDoublyListData(pList, 1, 30);
        displayDoublyList(pList);

        removeDoublyListData(pList, 0);
        displayDoublyList(pList);

        deleteDoublyList(pList);
    }
    return 0;
}