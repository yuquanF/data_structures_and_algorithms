//
// Created by fyq on 2020/10/19.
//

#ifndef D_A_SQSTACK_H
#define D_A_SQSTACK_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Common.h"

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stack_size;
} SqStack;

Status InitStack(SqStack *s);

Status DestroyStack(SqStack *s);

Status ClearStack(SqStack *s);

Status StackEmpty(SqStack s);

int StackLength(SqStack s);

Status GetTop(SqStack s, SElemType *e);

Status Push(SqStack *s, SElemType e);

Status Pop(SqStack *s, SElemType *e);

Status StackTraverse(SqStack s, void (Visit)(SElemType));

#endif //D_A_SQSTACK_H
