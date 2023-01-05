/*
#ifndef C_LANGUAGE_LINKEDSTACK_H
#define C_LANGUAGE_LINKEDSTACK_H

typedef struct LinkedStackNodeType {
    char data;
    struct LinkedStackNode *pLink;
} LinkedStackNode;

typedef struct LinkedStackType {
    int currentCount;
    LinkedStackNode *pTop; // 탑 노드의 포인터
} LinkedStack;

LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, char data);
int isLinkedStackEmpty(LinkedStack *pStack);
LinkedStackNode *popLS(LinkedStack *pStack);
LinkedStackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
void displayLinkedStack(LinkedStack *pStack);

#endif
*/
