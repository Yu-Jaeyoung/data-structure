#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"


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

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode != NULL) {
        printf("%c ", pRootNode->data);
        preorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        preorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
    }
}

void preorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    if (pBinTree != NULL) {
        preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
        printf("\n");
    }
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode != NULL) {
        inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        printf("%c ", pRootNode->data);
        inorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
    }
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    if (pBinTree != NULL) {
        inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
        printf("\n");
    }
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode != NULL) {
        postorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        postorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
        printf("%c ", pRootNode->data);
    }
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    if (pBinTree != NULL) {
        postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
        printf("\n");
    }
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
        printf("전위 순회 결과 : ");
        preorderTraversalRecursiveBinTree(pBinTree);
        printf("중위 순회 결과 : ");
        inorderTraversalRecursiveBinTree(pBinTree);
        printf("후위 순회 결과 : ");
        postorderTraversalRecursiveBinTree(pBinTree);

        deleteBinTree(pBinTree);
    }

    return 0;
}