/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprlinkedstack.h"

int inStackPrecedence(Precedence oper);

int outStackPrecedence(Precedence oper);

void printToken(ExprToken element);

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount) {
    LinkedStack *pStack = NULL;
    LinkedStackNode *pNode = NULL;

    Precedence tokenType, inStackTokenType;
    int i = 0;

    pStack = createLinkedStack();
    if (pStack != NULL) {
        for (i = 0; i < tokenCount; i++) {
            tokenType = pExprTokens[i].type;
            switch (tokenType) {
                case operand:
                    printf("%4.1f\t", pExprTokens[i].value);
                    break;
                case rparen:
                    pNode = popLS(pStack);
                    while (pNode != NULL && pNode->data.type != lparen) {
                        printToken(pNode->data);
                        free(pNode);

                        pNode = popLS(pStack);
                    }
                    if (pNode != NULL) free(pNode);
                    break;
                default:
                    while (isLinkedStackEmpty(pStack) == 0) {
                        inStackTokenType = peekLS(pStack)->data.type;
                        if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType)) {
                            pNode = popLS(pStack);
                            if (pNode != NULL) {
                                printToken(pNode->data);
                                free(pNode);
                            }
                        } else {
                            break;
                        }
                    }
                    pushLS(pStack, pExprTokens[i]);
                    break;
            }
        }
        while (isLinkedStackEmpty(pStack) == 0) {
            pNode = popLS(pStack);
            if (pNode != NULL) {
                printToken(pNode->data);
                free(pNode);
            }
        }
        deleteLinkedStack(pStack);
    }
}

int inStackPrecedence(Precedence oper) {
    switch (oper) {
        case lparen:
            return 0;
        case rparen:
            return 4;
        case multiply:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }
    return -1;
}

int outStackPrecedence(Precedence oper) {
    switch (oper) {
        case lparen:
            return 5;
        case rparen:
            return 4;
        case multiply:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }
    return -1;
}

int prec(char op) {
    switch (op) {
        case '(':
        case ')':
            return 0;
        case '+' :
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void printToken(ExprToken element) {
    switch (element.type) {
        case lparen:
            printf("(\t");
            break;
        case rparen:
            printf(")\t");
            break;
        case plus:
            printf("+\t");
            break;
        case minus:
            printf("-\t");
            break;
        case multiply:
            printf("*\t");
            break;
        case divide:
            printf("/\t");
            break;
        case operand:
            printf("%4.1f\t", element.value);
            break;
    }
}

int infix_to_postfix(char exp[], char result[]) {
    int i = 0;
    int n = 0;
    char ch, top_top;
    int len = strlen(exp);
    LinkedStack *pStack = NULL;
    LinkedStackNode *pNode = NULL;

    Precedence tokenType, inStackTokenType;

    pStack = createLinkedStack();

    if (pStack != NULL) {
        for (i = 0; i < sizeof(exp) + 1; i++) {
            tokenType = exp[i];
            switch (tokenType) {
                case '+':
                case '-':
                case '*':
                case '/':
                while(isLinkedStackEmpty(pStack) == 0)
            }
            while (isLinkedStackEmpty(pStack) == 0) {
                pNode = popLS(pStack);
                if (pNode != NULL) {
                    printToken(pNode->data);
                    free(pNode);
                }
            }
            deleteLinkedStack(pStack);
        }

    }

    int main() {
        return 0;
    }*/
