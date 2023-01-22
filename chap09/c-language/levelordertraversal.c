#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.h"

typedef struct LinkedQueueNodeType {
    BinTreeNode *data;
    struct LinkedQueueNodeType *pLink;
} LinkedQueueNode;

typedef struct LinkedQueueType {
    int currentCount; // 현재 노드의 개수
    LinkedQueueNode *pFront; // Front 노드의 포인터
    LinkedQueueNode *pRear; // Rear 노드의 포인터
} LinkedQueue;

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

int enqueueLQ(LinkedQueue *pQueue, BinTreeNode *data) {
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

BinTreeNode *makeNewNodeBT(char data) {
    BinTreeNode *pReturn = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pReturn != NULL) {
        pReturn->data = data;
        pReturn->pLeftChild = NULL;
        pReturn->pRightChild = NULL;
    }
    return pReturn;
}

BinTree *makeBinTree(char rootNodeData) {
    BinTree *pReturn = NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn != NULL) {
        pReturn->pRootNode = makeNewNodeBT(rootNodeData);
        if (pReturn->pRootNode == NULL) {
            free(pReturn);
            pReturn = NULL;
            printf("오류, 메모리 할당, makeBinTree()\n");
        }
    } else {
        printf("오류, 메모리 할당, makeBinTree()\n");
    }
    return pReturn;
}

BinTreeNode *addLeftChildNodeBT(BinTreeNode *pParentNode, char data) {
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL) {
        // pReturn->data = data; 이 부분이 왜 없을까?
        if (pParentNode->pLeftChild == NULL) {
            // pParentNode->pLeftChild = makeNewNodeBT(data); -
            pReturn = makeNewNodeBT(data);
            pParentNode->pLeftChild = pReturn;
        } else {
            printf("오류, 이미 노드가 존재\n");
        }
    } else {
        printf("오류, 메모리 할당 실패 \n");
    }
    return pReturn;
}

BinTreeNode *addRightChildNodeBT(BinTreeNode *pParentNode, char data) {
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL) {
        // pReturn->data = data; 이 부분이 왜 없을까?
        if (pParentNode->pRightChild == NULL) {
            // pParentNode->pRightChild = makeNewNodeBT(data); - 기존
            pReturn = makeNewNodeBT(data);
            pParentNode->pRightChild = pReturn;
        } else {
            printf("오류, 이미 노드가 존재\n");
        }
    } else {
        printf("오류, 메모리 할당 실패 \n");
    }
    return pReturn;
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree) {
    BinTreeNode *pReturn = NULL;

    if (pBinTree != NULL) {
        pReturn = pBinTree->pRootNode;
    }

    return pReturn;
}

void deleteBinTreeNode(BinTreeNode *pNode) {
    if (pNode != NULL) {
        deleteBinTreeNode(pNode->pRightChild);
        deleteBinTreeNode(pNode->pLeftChild);
        free(pNode);
    }
}

void deleteBinTree(BinTree *pBinTree) {
    if (pBinTree != NULL) {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}

void levelOrderTraversalBinTree(BinTree *pBinTree) {
    LinkedQueue *pQueue = NULL;
    LinkedQueueNode *pLinkedQueueNode = NULL;

    BinTreeNode *pCurrentNode = NULL;
    if (pBinTree == NULL) {
        return;
    }

    pCurrentNode = getRootNodeBT(pBinTree);
    if (pCurrentNode == NULL) {
        return;
    }

    pQueue = createLinkedQueue();
    if (pQueue == NULL) {
        return;
    }

    enqueueLQ(pQueue, pCurrentNode); // 책은 왜 '->data' 를 미작성..? -> enqueue를 수정해야됨 ㅋㅋ

    while (1) {
        if (isLinkedQueueEmpty(pQueue)) {
            return;
        } else {
            pLinkedQueueNode = dequeueLQ(pQueue);
            if (pLinkedQueueNode != NULL) {
                pCurrentNode = pLinkedQueueNode->data;
                printf("%c ", pCurrentNode->data);
                if (pCurrentNode->pLeftChild != NULL) {
                    enqueueLQ(pQueue, pCurrentNode->pLeftChild);
                }
                if (pCurrentNode->pRightChild != NULL) {
                    enqueueLQ(pQueue, pCurrentNode->pRightChild);
                }
                free(pLinkedQueueNode);
            }
        }
    }
    // deleteLinkedQueue(pQueue); -> 애초에 리턴 처리해서 의미 없는 코드
}

BinTree *createExampleBinTree() {
    BinTree *pBinTree = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL, *pNodeG = NULL;

    pBinTree = makeBinTree('A');

    if (pBinTree != NULL) {
        pNodeA = getRootNodeBT(pBinTree);
        pNodeB = addLeftChildNodeBT(pNodeA, 'B');
        pNodeC = addRightChildNodeBT(pNodeA, 'C');
        if (pNodeB != NULL) {
            //printf("실행 여부 확인용 1\n");
            pNodeD = addLeftChildNodeBT(pNodeB, 'D');
            pNodeE = addRightChildNodeBT(pNodeB, 'E');

        } else {
            printf("NULL이면 이게 출력됨\n");
        }

        if (pNodeC != NULL) {
            //printf("실행 여부 확인용 2\n");
            pNodeF = addLeftChildNodeBT(pNodeC, 'F');
            pNodeG = addRightChildNodeBT(pNodeC, 'G');
        } else {
            printf("NULL이면 이게 출력됨\n");
        }
    }

    return pBinTree;
}

int main() {
    BinTree *pBinTree = createExampleBinTree();
    if (pBinTree != NULL) {
        levelOrderTraversalBinTree(pBinTree);
        // deleteBinTree(pBinTree);
    }
    return 0;
}