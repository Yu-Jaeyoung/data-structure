/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType {
    int data;
    struct LinkedListNodeType *pLink;
} LinkedListNode;

typedef struct LinkedListType {
    int currentCount;
    LinkedListNode headerNode;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *pReturn = (LinkedList *) malloc(sizeof(LinkedList));
    memset(pReturn, 0, sizeof(LinkedList)); // 할당된 메모리를 0으로 초기화
    return pReturn;
}

int getLinkedListData(LinkedList *pList, int position) {
    int i = 0;

    LinkedListNode *pCurrentNode = &(pList->headerNode);
    for (; i <= position; i++) {
        pCurrentNode = pCurrentNode->pLink;
    }

    return pCurrentNode->data;
}

int addLinkedListData(LinkedList *pList, int position, int data) {
    int i = 0;

    LinkedListNode *pNewNode = (LinkedListNode *) malloc(sizeof(LinkedList));
    pNewNode->data = data;

    LinkedListNode *preNode = &(pList->headerNode);

    for (; i < position; i++) {
        preNode = preNode->pLink;
    }

    pNewNode->pLink = preNode->pLink;
    preNode->pLink = pNewNode;
    pList->currentCount++;
    return 0;
}

int removeLinkedListData(LinkedList *pList, int position) {

    int i = 0;
    LinkedListNode *preNode = &(pList->headerNode);
    LinkedListNode *delNode = NULL;

    for (; i < position; i++) {
        preNode = preNode->pLink;
    }

    delNode = preNode->pLink;
    preNode->pLink = delNode->pLink;
    free(delNode);
    pList->currentCount--;
    return 0;
}

void deleteLinkedList(LinkedList *pList) {
    LinkedListNode *pDelNode;
    LinkedListNode *pPreNode = pList->headerNode.pLink; // 헤더 노드가 가리키는 노드 주소
    while (pPreNode != NULL) {
        pDelNode = pPreNode;
        pPreNode = pPreNode->pLink;

        free(pDelNode);
    }

    free(pList); // 연결리스트 자체 메모리 해제
}

int getLinkedListLength(LinkedList *pList) {
    if (pList != NULL) {
        return pList->currentCount;
    }
    return 0;
}

void displayList(LinkedList *pList) {
    for (int i = 0; i < pList->currentCount; i++) {
        printf("[%d], %d\n", i, getLinkedListData(pList, i));
    }
}

void iterateLinkedList(LinkedList *pList) {
    int count = 0;
    LinkedListNode *pNode = pList->headerNode.pLink;

    while (pNode != NULL) {
        printf("[%d], %d\n", count++, pNode->data);
        pNode = pNode->pLink;
    }
    printf("노드 개수 : %d\n", count);
}

int main() {
    LinkedList *pList = NULL;

    pList = createLinkedList();
    addLinkedListData(pList, 0, 10);
    addLinkedListData(pList, 1, 20);
    addLinkedListData(pList, 1, 30);

    int value = getLinkedListData(pList, 1);
    printf("위치 : %d, 값 : %d\n", 1, value);

    displayList(pList);

    iterateLinkedList(pList);

    removeLinkedListData(pList, 0);
    deleteLinkedList(pList);

    return 0;
}*/
