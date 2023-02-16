/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayGraph.h"

#define ARRAY_GRAPH_TYPE_DIRECT 0
#define ARRAY_GRAPH_TYPE_UNDIRECT 1

void traversalDFS(ArrayGraph *pGraph, int startNodeID, int *pVisit) {
    int i = 0;
    pVisit[startNodeID] = 1;
    printf("노드-[%d] 방문\n", startNodeID);
    for (i = 0; i < pGraph->nodeCount; i++) {
        if (i != startNodeID) { // 자기 자신을 다시 방문 하지 않기 위해 설정
            if (0 != getEdgeAG(pGraph, startNodeID, i)) { // 간선 존재 여부 점검
                if (0 == pVisit[i]) { // 기존 방문 여부를 점검
                    traversalDFS(pGraph, i, pVisit);
                }
            }
        }
    }
}

int main() {
    int nodeCount = 4;
    ArrayGraph *pG1 = createArrayGraph(ARRAY_GRAPH_TYPE_UNDIRECT, nodeCount);
    int *pVisit = malloc(sizeof(int) * nodeCount);
    if (pG1 != NULL && pVisit != NULL) {
        addEdgeAG(pG1, 0, 1);
        addEdgeAG(pG1, 0, 2);
        addEdgeAG(pG1, 1, 3);
        memset(pVisit, 0, sizeof(int) * nodeCount);
        printf("G1: DFS\n");
        traversalDFS(pG1, 0, pVisit);
        deleteGraphAG(pG1);
        free(pVisit);
    }
    return 0;
}*/
