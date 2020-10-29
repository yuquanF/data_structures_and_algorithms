//
// Created by fyq on 2020/10/28.
//

#include "LinkList.h"

Status InitList(LinkList *l) {
    (*l) = (LinkList) malloc(sizeof(LNode));
    if (*l == NULL) {
        exit(OVERFLOW);
    }

    (*l)->next = NULL;

    return OK;
}

Status DestroyList(LinkList *l) {
    if (l == NULL || *l == NULL) {
        return ERROR;
    }

    LinkList p = *l;

    while (p != NULL) {
        p = p->next;
        free(*l);
        *l = p;
    }

    *l = NULL;

    return OK;
}

/**
 * 置空，需要释放链表中非头结点的空间
 * @param l
 * @return
 */
Status ClearList(LinkList l) {
    if (l == NULL) {
        return ERROR;
    }

    LinkList pre, p = l->next;

    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }

    l->next = NULL;

    return OK;
}

Status ListEmpty(LinkList l) {
    if (l != NULL && l->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(LinkList l) {
    if (l == NULL || l->next == NULL) {
        return 0;
    }

    LinkList p = l->next;
    int i = 0;

    while (p!=NULL) {
        p = p->next;
        i++;
    }

    return i;
}

Status GetElem(LinkList l, int i, ElemType *e) {
    if(l == NULL || l->next == NULL) {
        return ERROR;
    }

    LinkList p = l->next;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    *e = p->data;

    return OK;
}

int LocateElem(LinkList l, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(LinkList l, ElemType cur_e, ElemType *pre_e);

Status NextElem(LinkList l, ElemType cur_e, ElemType *next_e);

Status ListInsert(LinkList l, int i, ElemType e);

Status ListDelete(LinkList l, int i, ElemType *e);

void ListTraverse(LinkList l, void(Visit)(ElemType));