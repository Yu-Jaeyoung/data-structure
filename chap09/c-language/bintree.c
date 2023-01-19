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