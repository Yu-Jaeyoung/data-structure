/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNodeType {
    char data;

    struct BinTreeNodeType *pLeftChild;
    struct BinTreeNodeType *pRightChild;
} BinTreeNode;

typedef struct BinTreeType {
    struct BinTreeNodeType *pRootNode;
} BinTree;

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
            pParentNode->pLeftChild = makeNewNodeBT(data);
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
            pParentNode->pRightChild = makeNewNodeBT(data);
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

int main() {
    BinTree *pBinTree = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;

    pBinTree = makeBinTree('A');

    if (pBinTree != NULL) {
        pNodeA = getRootNodeBT(pBinTree);
        pNodeB = addLeftChildNodeBT(pNodeA, 'B');
        pNodeC = addRightChildNodeBT(pNodeA, 'C');
        if (pNodeB != NULL) {
            pNodeD = addLeftChildNodeBT(pNodeB, 'D');
        }
        if (pNodeC != NULL) {
            pNodeE = addLeftChildNodeBT(pNodeC, 'E');
            pNodeF = addRightChildNodeBT(pNodeC, 'F');
        }
        deleteBinTree(pBinTree);
    }

}*/
