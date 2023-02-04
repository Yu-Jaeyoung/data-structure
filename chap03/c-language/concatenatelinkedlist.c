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

void iterateLinkedList(LinkedList *pList) {
    int count = 0;
    LinkedListNode *pNode = pList->headerNode.pLink;

    while (pNode != NULL) {
        printf("[%d], %d\n", count++, pNode->data);
        pNode = pNode->pLink;
    }
    printf("노드 개수 : %d\n", count);
}

void concatenateLinkedList(LinkedList *pListA, LinkedList *pListB) {
    LinkedListNode *pNodeA = NULL;

    if(pListA->currentCount == 0){
        fprintf(stderr,"오류 발생, 연결 실패");
        exit(0);
    }


    if (pListA != NULL && pListB != NULL) {
        pNodeA = pListA->headerNode.pLink;

        while (pNodeA != NULL && pNodeA->pLink != NULL) {
            pNodeA = pNodeA->pLink;
        }
        pNodeA->pLink = pListB->headerNode.pLink;

        pListB->headerNode.pLink = NULL;
    }
}

int main() {
    LinkedList *pListA = NULL;
    LinkedList *pListB = NULL;

    pListA = createLinkedList();
    pListB = createLinkedList();
    addLinkedListData(pListA, 0, 10);
    addLinkedListData(pListA, 1, 20);
    addLinkedListData(pListA, 2, 30);
    addLinkedListData(pListB, 0, 40);
    addLinkedListData(pListB, 1, 50);

    printf("연결 리스트 결합 전\n");
    printf("\n연결 리스트 A\n");
    iterateLinkedList(pListA);
    printf("\n연결 리스트 B\n");
    iterateLinkedList(pListB);

    concatenateLinkedList(pListA, pListB);
    printf("\n연결 리스트 결합 후\n");
    printf("\n연결 리스트 A\n");
    iterateLinkedList(pListA);
    printf("\n연결 리스트 B\n");
    iterateLinkedList(pListB);

    deleteLinkedList(pListA);
    deleteLinkedList(pListB);

    return 0;
}
*/
