//
// Created by fyq on 2020/10/28.
//

#ifndef D_A_LINKLIST_H
#define D_A_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Common.h"

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *l);

Status DestroyList(LinkList *l);

Status ClearList(LinkList l);

Status ListEmpty(LinkList l);

int ListLength(LinkList l);

Status GetElem(LinkList l, int i, ElemType *e);

int LocateElem(LinkList l, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(LinkList l, ElemType cur_e, ElemType *pre_e);

Status NextElem(LinkList l, ElemType cur_e, ElemType *next_e);

Status ListInsert(LinkList l, int i, ElemType e);

Status ListDelete(LinkList l, int i, ElemType *e);

void ListTraverse(LinkList l, void(Visit)(ElemType));

#endif //D_A_LINKLIST_H
