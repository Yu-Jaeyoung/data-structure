#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxCount) {
    ArrayMaxHeap *pReturn = NULL;
    if (maxCount > 0) {
        pReturn = (ArrayMaxHeap *) malloc(sizeof(ArrayMaxHeap));
        if (pReturn != NULL) { // 메모리 할당 이후 확인
            pReturn->maxCount = maxCount;
            pReturn->currentCount = 0;
        }
        pReturn->pData = (HeapNode *) malloc(sizeof(HeapNode) * (maxCount + 1));
        if (pReturn->pData != NULL) { // 메모리 할당 이후 확인
            memset(pReturn->pData, 0, sizeof(HeapNode) * (maxCount + 1));
        }
    } else {
        printf("최대 원소의 개수는 0보다 커야 합니다.\n");
    }

    return pReturn;
}

int insertMaxHeapAH(ArrayMaxHeap *pHeap, int value) {
    int i = 0;
    if (pHeap != NULL) {
        if (pHeap->currentCount == pHeap->maxCount) { // 히프의 크기를 초과하여 저장하는지 점검
            printf("오류, 히프가 가득찼습니다. maxCount : [%d], insertMaxHeapAH()\n", pHeap->maxCount);
            return 0;
        }
        pHeap->currentCount++;
        i = pHeap->currentCount;
        while ((i != 1) && (value > pHeap->pData[i / 2].data)) {
            pHeap->pData[i] = pHeap->pData[i / 2];
            i /= 2;
        }
        pHeap->pData[i].data = value;
    }

    return i;
}

HeapNode *removeMaxHeapAH(ArrayMaxHeap *pHeap) {
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;
    int parent = 1, child = 2; // 루트 노드(1)와 루트 노드의 왼쪽 자식 노드(2) 인덱스

    if (pHeap != NULL && pHeap->currentCount > 0) { // 반환 가능한 노드가 있는지 점검
        pReturn = (HeapNode *) malloc(sizeof(HeapNode));
        if (pReturn == NULL) { // 반환되는 노드에 대한 메모리 할당 및 점검
            printf("오류, 메모리 할당, deleteMaxHeapAH()\n");
            return NULL;
        }
        pReturn->data = pHeap->pData[1].data; // 반환되는 노드의 값으로 기존 루트 노드의 자료를 대입
        pTemp = &(pHeap->pData[pHeap->currentCount]); // 히프의 제일 마지막 노드를 가리킴
        pHeap->currentCount--; // 히프에 저장된 자료의 개수를 1 감소시킴

        while (child <= pHeap->currentCount) {
            if ((child < pHeap->currentCount) && pHeap->pData[child].data < pHeap->pData[child + 1].data) {
                child++; // 오른쪽 자식 노드가 존재하고, 왼쪽 자식 노드보다 오른쪽 자식 노드의 키 값이 더 크다면,
            }            // 오른쪽 자식 노드가 비교 대상이 되도록 인덱스 수정

            if (pTemp->data >= pHeap->pData[child].data) {
                break; // 만약 마지막 노드의 값이 child 노드(비교 대상)의 값보다 큰 경우
            }          // 그 부모 노드에 마지막 노드의 값을 저장해야 하므로 break;

            pHeap->pData[parent] = pHeap->pData[child]; // 아닌 경우 삭제된 부모 노드 자리에 자식 노드의 값을 저장
            parent = child; // 부모 노드 인덱스 번호에 자식 노드 인덱스 번호 사용
            child *= 2; // 자식은 자손으로 연산을 활용하여 넘어가서 while문 반복 진행
        }
        pHeap->pData[parent] = *pTemp; // 나오면서, 해당 부모 자리에 마지막 노드의 값을 대입
    }

    return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap *pHeap) {
    if (pHeap != NULL) {
        if (pHeap->pData != NULL) {
            free(pHeap->pData);
        }
        free(pHeap);
    }
}

void displayArrayHeap(ArrayMaxHeap *pHeap) {
    if (pHeap != NULL) {
        for (int i = 1; i <= pHeap->currentCount; i++) {
            printf("[%d], %d\n", i, pHeap->pData[i].data);
        }
    }
}

int main() {
    int maxHeapSize = 20;
    ArrayMaxHeap *pHeap1 = NULL;
    HeapNode *pNode = NULL;

    pHeap1 = createArrayMaxHeap(maxHeapSize);
    if (pHeap1 != NULL) {
        insertMaxHeapAH(pHeap1, 90);
        insertMaxHeapAH(pHeap1, 85);
        insertMaxHeapAH(pHeap1, 80);
        insertMaxHeapAH(pHeap1, 75);
        insertMaxHeapAH(pHeap1, 70);
        insertMaxHeapAH(pHeap1, 65);
        insertMaxHeapAH(pHeap1, 60);
        insertMaxHeapAH(pHeap1, 55);
        insertMaxHeapAH(pHeap1, 50);
        insertMaxHeapAH(pHeap1, 45);
        insertMaxHeapAH(pHeap1, 40);
        insertMaxHeapAH(pHeap1, 35);
        insertMaxHeapAH(pHeap1, 30);

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        insertMaxHeapAH(pHeap1, 99);
        printf("After insertMaxHeapAH()-%d\nMax Heap:\n", 99);
        displayArrayHeap(pHeap1);

        pNode = removeMaxHeapAH(pHeap1);
        if (pNode != NULL) {
            printf("removeMaxHeapAH()-[%d]\n", pNode->data);
            free(pNode);
        }

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        deleteArrayMaxHeap(pHeap1);
    }

    return 0;
}