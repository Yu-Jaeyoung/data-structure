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

    }
}