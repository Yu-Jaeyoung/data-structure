typedef struct HeapNodeType {
    int data;
} HeapNode;

typedef struct ArrayHeapType {
    int maxCount;
    int currentCount;
    HeapNode *pData; // 노드 저장을 위한 1차원 array
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap *createArrayMaxHeap(int maxCount);

int insertMaxHeapAH(ArrayMaxHeap *pHeap, int value);

HeapNode *removeMaxHeapAH(ArrayMaxHeap *pHeap);

void deleteArrayMaxHeap(ArrayMaxHeap *pHeap);

void displayArrayHeap(ArrayMaxHeap *pHeap);