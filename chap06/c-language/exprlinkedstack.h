#ifndef C_LANGUAGE_EXPRLINKEDSTACK_H
#define C_LANGUAGE_EXPRLINKEDSTACK_H

typedef enum PrecedenceType {
    lparen, rparen, multiply, divide, plus, minus, operand
} Precedence;

typedef struct ExprTokenType {
    double value;
    Precedence type;
} ExprToken;

typedef struct LinkedStackNodeType {
    ExprToken data;
    struct LinkedStackNode *pLink;
} LinkedStackNode;

typedef struct LinkedStackType {
    int currentCount;
    LinkedStackNode *pTop; // 탑 노드의 포인터
} LinkedStack;

LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, ExprToken data);
int isLinkedStackEmpty(LinkedStack *pStack);
LinkedStackNode *popLS(LinkedStack *pStack);
LinkedStackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
void displayLinkedStack(LinkedStack *pStack);

#endif