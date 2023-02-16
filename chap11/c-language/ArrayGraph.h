typedef struct ArrayGraphType {
    int graphType; // 그래프의 종류 : 방향 그래프, 무방향 그래프
    int nodeCount; // 노드 개수
    int **ppEdge; // 간선 저장을 위한 2차원 array
} ArrayGraph;

ArrayGraph *createArrayGraph(int graphType, int nodeCount);
int checkVertexValid(ArrayGraph *pGraph, int node);
int addEdgeInternalAG(ArrayGraph *pGraph, int fromNode, int toNode);
int addEdgeAG(ArrayGraph *pGraph, int fromNode, int toNode);
int removeEdgeInternalAG(ArrayGraph *pGraph, int fromNode, int toNode);
int removeEdgeAG(ArrayGraph *pGraph, int fromNode, int toNode);
int getEdgeAG(ArrayGraph *pGraph, int fromNode, int toNode);
void displayGraphAG(ArrayGraph *pGraph);
void deleteGraphAG(ArrayGraph *pGraph);
