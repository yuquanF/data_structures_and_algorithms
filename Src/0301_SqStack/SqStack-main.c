//
// Created by fyq on 2020/10/19.
//

#include "SqStack.h"

int main() {
    SqStack s;
    SElemType e;
    Boolean debug = FALSE;
    Status status = ERROR;

    printf("--------InitStack-------- \n");
    InitStack(&s);
    PressEnterToContinue(debug);

    printf("--------StackEmpty-------- \n");
    status =  StackEmpty(s);
    if (status){
        printf("stack is empty! \n");
    } else {
        printf("stack is not empty! \n");
    }
    PressEnterToContinue(debug);

    printf("--------Push-------- \n");
    for(int i = 1; i <= 7; i++) {
        Push(&s, i);
        printf("Push %d to stack! \n", i);
    }
    PressEnterToContinue(debug);

    printf("--------StackTraverse-------- \n");
    StackTraverse(s, PrintIntElem);
    PressEnterToContinue(debug);

    printf("--------StackLength-------- \n");
    int len = StackLength(s);
    printf("stack length is %d!\n", len);
    PressEnterToContinue(debug);

    printf("--------Pop-------- \n");
    Pop(&s, &e);
    printf("the pop value is %d!", e);
    printf("now stack is: \n");
    StackTraverse(s, PrintIntElem);
    PressEnterToContinue(debug);

    printf("--------GetTop-------- \n");
    GetTop(s, &e);
    printf("Get the pop value is %d!", e);
    printf("now stack is: \n");
    StackTraverse(s, PrintIntElem);
    PressEnterToContinue(debug);

    printf("--------ClearStack-------- \n");
    printf("before clear stack: \n");
    StackTraverse(s, PrintIntElem);
    ClearStack(&s);
    printf("after clear stack: \n");
    StackTraverse(s, PrintIntElem);
    PressEnterToContinue(debug);

    printf("--------DestroyStack-------- \n");
    DestroyStack(&s);
    if (s.base == NULL && s.top == NULL && s.stack_size == 0){
        printf("stack has been destroyed!");
    }
}