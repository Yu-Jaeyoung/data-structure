#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"
#include "ArrayGraph.h"

#define ARRAY_GRAPH_TYPE_DIRECT 0
#define ARRAY_GRAPH_TYPE_UNDIRECT 1

void traversalBFS(ArrayGraph *pGraph, int startNodeID) {
    int i = 0;
    int nodeID = 0;
    LinkedQueue *pQueue = NULL;
    LinkedQueueNode *pQueueNode = NULL;
    int *pVisit = NULL;

    if (pGraph == NULL) {
        return;
    }
    pQueue = createLinkedQueue();
    pVisit = malloc(sizeof(int) * pGraph->nodeCount);
    if (pQueue == NULL || pVisit == NULL) {
        return;
    }
    memset(pVisit, 0, sizeof(int) * pGraph->nodeCount);
    pVisit[startNodeID] = 1;
    enqueueLQ(pQueue, startNodeID);

    while (isLinkedQueueEmpty(pQueue) == 0) {
        pQueueNode = dequeueLQ(pQueue);
        if (pQueueNode != NULL) {
            nodeID = pQueueNode->data;
            printf("노드-[%d] 방문\n", nodeID);
            for (i = 0; i < pGraph->nodeCount; i++) {
                if (i != nodeID) {
                    if (0 != getEdgeAG(pGraph, nodeID, i)) {
                        if (0 == pVisit[i]) {
                            pVisit[i] = 1;
                            enqueueLQ(pQueue, i);
                        }
                    }
                }
            }
            free(pQueueNode);
        }
    }
    deleteLinkedQueue(pQueue);
    free(pVisit);
}

int main() {
    int nodeCount = 4;
    ArrayGraph *pG1 = createArrayGraph(ARRAY_GRAPH_TYPE_UNDIRECT, nodeCount);

    if (pG1 != NULL) {
        addEdgeAG(pG1, 0, 1);
        addEdgeAG(pG1, 0, 2);
        addEdgeAG(pG1, 1, 3);
        printf("G1: BFS\n");
        traversalBFS(pG1, 0);

        deleteGraphAG(pG1);
    }
}