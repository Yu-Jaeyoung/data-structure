#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

int checkBracketMatching(char *pSource) {
    int ret = 0, i = 0;
    char symbol = '\0', checkSymbol = '\0';

    LinkedStackNode *pNode = NULL;

    LinkedStack *pStack = createLinkedStack();
    if (pStack != NULL) {
        while ('\0' != pSource[i] && ret == 0) {
            symbol = pSource[i];
            switch (symbol) {
                case '(':
                case '[':
                case '{':
                    pushLS(pStack, symbol);
                    break;
                case ')':
                case ']':
                case '}':
                    pNode = popLS(pStack);
                    if (pNode == NULL) {
                        ret = 1; // 닫는 괄호가 많은 경우
                    } else {
                        checkSymbol = pNode->data;
                        if ((symbol == ')' && checkSymbol == '(') ||
                            (symbol == ']' && checkSymbol == '[') ||
                            (symbol == '}' && checkSymbol == '{')) {}
                        else {
                            ret = 2; // 괄호의 쌍이 맞지 않는 경우
                        }
                        free(pNode);
                    }
                    break;
            }
            i++;
        }
        if (0 == ret && isLinkedStackEmpty(pStack) == 0) {
            ret = 3; // 여는 괄호가 남은 경우
        }
        deleteLinkedStack(pStack);
    }
    return ret;
}

int main() {
    int checkResult = 0, i = 0;
    char szExpressionStr[][50] = {
            "( A + B ) * C",
            "{ ( A + B ) * C } * D",
            "( A + B ) * C )",
            "( ( A + B ) * C",
            "{ ( A + B } ) * C * D"
    };

    // printf("sizeof(szExpressionStr) : [%d]\n", sizeof(szExpressionStr));
    // printf("sizeof(szExpressionStr): [%d]\n", sizeof(szExpressionStr[0]));

    for (i = 0; i < sizeof(szExpressionStr) / sizeof(szExpressionStr[0]); i++) {
        checkResult = checkBracketMatching(szExpressionStr[i]);
        if (checkResult == 0) {
            printf("SUCCESS, %s\n", szExpressionStr[i]);
        } else {
            printf("FAIL-[%d], %s\n", checkResult, szExpressionStr[i]);
        }
    }
    return 0;
}