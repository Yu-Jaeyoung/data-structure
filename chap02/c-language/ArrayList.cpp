#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"

ArrayList *creatList(int count) {
    if (count <= 0) {
        fprintf(stderr, "오류 발생");
        return NULL;
    } else {

        ArrayList *pReturn = (ArrayList *) malloc(sizeof(ArrayList));
        pReturn->maxCount = count;
        pReturn->currentCount = 0;
        pReturn->pData = (ArrayListNode *) malloc(sizeof(ArrayList) * count);
        memset(pReturn->pData, 0, sizeof(ArrayListNode) * count);

        return pReturn;
    }
}

int addListData(ArrayList *pList, int position, element data) {
    if (!pList) {
        fprintf(stderr, "오류 발생");
        exit(1);
    }

    if (position > pList->currentCount) {
        fprintf(stderr, "오류 발생");
        exit(2);
    }

    int i = 0;

    for (i = pList->currentCount - 1; i >= position; i--) {
        pList->pData[i + 1] = pList->pData[i];
    }
    pList->pData[position].data = data;
    pList->currentCount++;
    return 0;
}

int removeListData(ArrayList *pList, int position) {

    if (!pList) {
        fprintf(stderr, "오류 발생");
        exit(1);
    }

    if (position >= pList->currentCount) {
        fprintf(stderr, "오류 발생");
        exit(2);
    }

    int i = 0;


    for (i = position; i < pList->currentCount - 1; i++) {
        pList->pData[i] = pList->pData[i + 1];
    }
    pList->currentCount--;
    return 0;
}

element getListData(ArrayList *pList, int position) {
    if (!pList) {
        fprintf(stderr, "오류 발생");
        exit(1);
    }

    if (position >= pList->currentCount) {
        fprintf(stderr, "오류 발생");
        exit(2);
    }

    return pList->pData[position].data;
}

void deleteList(ArrayList *pList) {
    if (!pList) {
        fprintf(stderr, "오류 발생");
        exit(1);
    }
    free(pList->pData);
    free(pList);
}

int getListLength(ArrayList *pList) {
    int length = pList->currentCount;
    return length;
}