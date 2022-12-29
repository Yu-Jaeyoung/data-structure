#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TermType { // '항을 나타내는 구조체'
    double coef; // 계수
    int degree; // 차수
} Term;

typedef struct LinkedListNodeType {
    Term data;
    struct LinkedListNodeType *pLink;
} LinkedListNode;

typedef struct LinkedListType {
    int currentCount;
    LinkedListNode headerNode;
} LinkedList, PolyList; // 추가 이름 부여

LinkedList *createLinkedList() {
    LinkedList *pReturn = (LinkedList *) malloc(sizeof(LinkedList));
    memset(pReturn, 0, sizeof(LinkedList)); // 할당된 메모리를 0으로 초기화
    return pReturn;
}

Term getLinkedListData(LinkedList *pList, int position) {
    int i = 0;

    LinkedListNode *pCurrentNode = &(pList->headerNode);
    for (; i <= position; i++) {
        pCurrentNode = pCurrentNode->pLink;
    }

    return pCurrentNode->data;
}

int addLinkedListData(LinkedList *pList, int position, Term data) {
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
    LinkedListNode *pPreNode = pList->headerNode.pLink;
    while (pPreNode != NULL) {
        pDelNode = pPreNode;
        pPreNode = pPreNode->pLink;

        free(pDelNode);
    }

    free(pList);
}

int getLinkedListLength(LinkedList *pList) {
    if (pList != NULL) {
        return pList->currentCount;
    }
    return 0;
}

int addPolyNodeLast(PolyList *pList, double coef, int degree) {
    int position = 0;

    Term term;
    term.coef = coef;
    term.degree = degree;

    if (pList != NULL) {
        position = pList->currentCount;
        addLinkedListData(pList, position, term);
    }
    return 0;
}

void displayPolyList(PolyList *pList) {
    int i = 0;
    LinkedListNode *pNode = pList->headerNode.pLink;
    if (0 == pList->currentCount) {
        printf("자료가 없습니다.\n");
    } else {
        for (; i < pList->currentCount; i++) {
            if (i > 0) {
                printf(" + ");
            }
            printf("%.1fx^%d", pNode->data.coef, pNode->data.degree);
            pNode = pNode->pLink;
        }
        printf("\n");
    }
}

PolyList *polyAdd(PolyList *pListA, PolyList *pListB) {
    PolyList *pReturn = NULL;
    LinkedListNode *pNodeA = NULL, *pNodeB = NULL;
    double coefSum = 0;

    if (pListA != NULL && pListB != NULL) {
        pReturn = createLinkedList();
        if (pReturn == NULL) {
            printf("메모리 할당 오류, PolyAdd()\n");
            return NULL;
        }

        pNodeA = pListA->headerNode.pLink;
        pNodeB = pListB->headerNode.pLink;
        while (pNodeA != NULL && pNodeB != NULL) {
            int degreeA = pNodeA->data.degree;
            int degreeB = pNodeB->data.degree;
            if (degreeA > degreeB) { // 1번 과정
                coefSum = pNodeA->data.coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;
            } else if (degreeA == degreeB) { // 2번 과정
                coefSum = pNodeA->data.coef + pNodeB->data.coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;
                pNodeB = pNodeB->pLink;
            } else { // 3번 과정
                coefSum = pNodeB->data.coef;
                addPolyNodeLast(pReturn, coefSum, degreeB);
                pNodeB = pNodeB->pLink;
            }
        }
        // 남은 노드 처리
        while (pNodeA != NULL) {
            coefSum = pNodeA->data.coef;
            addPolyNodeLast(pReturn, coefSum, pNodeA->data.degree);
            pNodeA = pNodeA->pLink;
        }

        while (pNodeB != NULL) {
            coefSum = pNodeB->data.coef;
            addPolyNodeLast(pReturn, coefSum, pNodeB->data.degree);
            pNodeB = pNodeB->pLink;
        }
    } else {
        printf("오류, NULL 다항식이 전달됨, PolyAdd()\n");
    }

    return pReturn;
}

int main() {
    PolyList *pListA = NULL;
    PolyList *pListB = NULL;
    PolyList *pListC = NULL;


    pListA = createLinkedList();
    pListB = createLinkedList();

    if (pListA != NULL && pListB != NULL) {
        addPolyNodeLast(pListA, 7, 6);
        addPolyNodeLast(pListA, 3, 5);
        addPolyNodeLast(pListA, 5, 2);
        displayPolyList(pListA);

        addPolyNodeLast(pListB, 1, 5);
        addPolyNodeLast(pListB, 2, 4);
        addPolyNodeLast(pListB, 3, 2);
        addPolyNodeLast(pListB, 4, 0);
        displayPolyList(pListB);

        pListC = polyAdd(pListA, pListB);
        if (pListC != NULL) {
            displayPolyList(pListC);
            deleteLinkedList(pListC);
        }

        deleteLinkedList(pListA);
        deleteLinkedList(pListB);
    }
    return 0;
}
