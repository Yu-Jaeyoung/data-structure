#include <stdio.h>
#include "arraylist.h"


int main() {
    ArrayList *pList = NULL;
    int value;

    //pList = creatList(5);
    addListData(pList, 0, 10);
    addListData(pList, 1, 20);
    addListData(pList, 0, 30);

    value = getListData(pList, 1);
    printf("위치 : %d, 값 : %d\n", 1, value);

    value = getListLength(pList);
    printf("자료의 개수 : %d\n", value);

    removeListData(pList, 0);
    deleteList(pList);

    return 0;
}