#include <stdio.h>
#include "ArrayList.h"


int main() {
    ArrayList *pList = NULL;
    int value = 0;

    pList = creatList(5);
    addListData(pList, 0, 10);
    addListData(pList, 1, 20);
    addListData(pList, 0, 30);

    value = getListData(pList, 1);
    printf("위치 : %d, 값 : %d\n", 1, value);

    removeListData(pList, 0);
    deleteList(pList);

    return 0;
}