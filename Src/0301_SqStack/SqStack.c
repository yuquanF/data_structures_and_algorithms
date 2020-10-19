//
// Created by fyq on 2020/10/19.
//
#include "SqStack.h"

Status InitStack(SqStack *s)
{
    if (s == NULL) {
        return ERROR;
    }
    s->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (s->base == NULL) {
        exit(OVERFLOW);
    }

    s->top = s->base;
    s->stack_size = STACK_INIT_SIZE;

    return OK;
}

Status DestroyStack(SqStack *s)
{
    if (s == NULL) {
        return ERROR;
    }

    free(s->base);

    s->base = NULL;
    s->top = NULL;
    s->stack_size = 0;

    return OK;
}

Status ClearStack(SqStack *s){
    if (s == NULL || s->base == NULL) {
        return ERROR;
    }

    s->top = s->base;

    return OK;
}

Status StackEmpty(SqStack s)
{
    if (s.top == s.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int StackLength(SqStack s)
{
    if (s.base == NULL) {
        return 0;
    }

    return (int) (s.top - s.base);
}

Status GetTop(SqStack s, SElemType *e)
{
    if (s.base == NULL || s.base == s.top) {
        return ERROR;
    }

    *e = *(s.top - 1);

    return OK;
}

Status Push(SqStack *s, SElemType e)
{
    if (s == NULL || s->base == NULL) {
        return ERROR;
    }

    // 判断栈满
    if (s->top - s->base >= s->stack_size) {
        // 栈满，追加存储空间
        s->base = (SElemType*) realloc(s->base, (s->stack_size + STACK_INCREMENT) * sizeof(SElemType));
        if (s->base == NULL) {
            exit(OVERFLOW);
        }

        s->top = s->base + s->stack_size;
        s->stack_size += STACK_INCREMENT;
    }

    *(s->top++) = e;

    return OK;
}

Status Pop(SqStack *s, SElemType *e)
{
    if (s == NULL || s->base == NULL) {
        return ERROR;
    }

    // 判断栈空
    if (s->top == s->base) {
        return ERROR;
    }

    *e = *(--s->top);

    return OK;
}

Status StackTraverse(SqStack s, void (Visit)(SElemType))
{
    if(s.base == NULL) {
        return ERROR;
    }

    SElemType *p = s.base;
    while (p < s.top) {
        Visit(*p++);
    }

    printf("\n");

    return OK;
}