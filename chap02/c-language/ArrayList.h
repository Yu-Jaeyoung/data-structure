#pragma once
typedef int element;

typedef struct ArrayListNodeType {
    element data;
} ArrayListNode;

typedef struct ArrayListType {
    int maxCount;
    int currentCount;
    ArrayListNode *pData;
} ArrayList;

ArrayList *creatList(int count);
int addListData(ArrayList *pList, int position, element data);
int removeListData(ArrayList *pList, int position);
element getListData(ArrayList *pList, int position);
void deleteList(ArrayList *pList);
int getListLength(ArrayList *pList);
