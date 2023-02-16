/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define ARRAY_GRAPH_TYPE_DIRECT 0
#define ARRAY_GRAPH_TYPE_UNDIRECT 1

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

    if (pList->currentCount < position) {
        fprintf(stderr, "오류 발생 프로그램 종료");
        exit(1);
    }

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

typedef struct LinkedGraphType {
    int graphType;
    int nodeCount; // 노드 개수
    LinkedList **ppAdjEdge; // 간선 저장을 위한 연결 리스트(포인터)의 배열
} LinkedGraph;

LinkedGraph *createLinkedGraph(int graphType, int nodeCount) {
    int i = 0;
    LinkedGraph *pReturn = NULL;

    if (nodeCount > 0) {
        pReturn = (LinkedGraph *) malloc(sizeof(LinkedGraph));
        if (pReturn == NULL) {
            printf("오류, 메모리 할당 in createLikedGraph()\n");
            return NULL;
        }
        pReturn->nodeCount = nodeCount;
    } else {
        printf("오류, 최대 노드 개수는 0보다 커야됩니다.");
        return NULL;
    }

    pReturn->ppAdjEdge = (LinkedList **) malloc(sizeof(LinkedList *) * nodeCount);
    if (pReturn->ppAdjEdge == NULL) {
        printf("오류, 메모리 할당 in createLinkedGraph() -> ppAdjEdge\n");
        if (pReturn != NULL) {
            free(pReturn);
            return NULL;
        }
    }
    for (i = 0; i < nodeCount; i++) {
        pReturn->ppAdjEdge[i] = createLinkedList();
        if (pReturn->ppAdjEdge[i] == NULL) {
            printf("오류, 메모리 할당 in ppAdjEdge[]\n");
            if (pReturn->ppAdjEdge != NULL) {
                free(pReturn->ppAdjEdge);
                if (pReturn != NULL) {
                    free(pReturn);
                }
            }
            return NULL;
        }
    }
    pReturn->graphType = graphType;
    return pReturn;
}

int checkVertexValid(LinkedGraph *pGraph, int node) {
    if (pGraph != NULL && node >= 0 && node < pGraph->nodeCount) {
        return 1;
    } else {
        return 0;
    }
}

int addEdgeInternalLG(LinkedGraph *pGraph, int fromNode, int toNode) {
    int ret = 0;
    if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        addLinkedListData(pGraph->ppAdjEdge[fromNode], 0, toNode);
    } else {
        ret = -1;
    }
    return ret;
}

int addEdgeLG(LinkedGraph *pGraph, int fromNode, int toNode) {
    int ret = 0;

    ret = addEdgeInternalLG(pGraph, fromNode, toNode);
    if (0 == ret && ARRAY_GRAPH_TYPE_UNDIRECT == pGraph->graphType) {
        ret = addEdgeInternalLG(pGraph, toNode, fromNode);
    }
    return ret;
}

int removeEdgeInternalLG(LinkedGraph *pGraph, int fromNode, int toNode) {
    int ret = -1;
    LinkedList *pList = NULL;
    int i = 0, count = 0;

    if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        pList = pGraph->ppAdjEdge[fromNode];
        count = getLinkedListLength(pList);
        for (i = 0; i < count; i++) {
            if (getLinkedListData(pList, i) == toNode) {
                removeLinkedListData(pList, i);
                ret = 0;
                break;
            }
        }
    } else { // 해당하는 간선이 없는 경우
        ret = -1;
    }
    return ret;
}

int removeEdgeLG(LinkedGraph *pGraph, int fromNode, int toNode) {
    int ret = -1;
    ret = removeEdgeInternalLG(pGraph, fromNode, toNode);
    if (0 == ret && ARRAY_GRAPH_TYPE_UNDIRECT == pGraph->graphType) {
        removeEdgeInternalLG(pGraph, toNode, fromNode);
    }
    return ret;
}

int getEdgeLG(LinkedGraph *pGraph, int fromNode, int toNode) {
    int ret = 0;
    LinkedList *pList = NULL;
    int i = 0, count = 0;

    if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        pList = pGraph->ppAdjEdge[fromNode];
        count = getLinkedListLength(pList);
        for (i = 0; i < count; i++) {
            if (getLinkedListData(pList, i) == toNode) {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int displayGraphLG(LinkedGraph *pGraph) {
    int i = 0, j = 0, count = 0;
    if (pGraph != NULL) {
        count = pGraph->nodeCount;
        for (i = 0; i < count; i++) {
            for (j = 0; j < count; j++) {
                if (getEdgeLG(pGraph, i, j)) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}

void deleteGraphLG(LinkedGraph *pGraph) {
    int i = 0;
    if (pGraph != NULL) {
        for (i = 0; i < pGraph->nodeCount; i++) {
            deleteLinkedList(pGraph->ppAdjEdge[i]);
        }
        if (pGraph->ppAdjEdge != NULL) {
            free(pGraph->ppAdjEdge);
        }
        free(pGraph);
    }
}*/
