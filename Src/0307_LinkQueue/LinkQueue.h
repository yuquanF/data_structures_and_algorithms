//
// Created by fyq on 2020/10/19.
//

#ifndef D_A_LINKQUEUE_H
#define D_A_LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Common.h"

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *q);

Status DestroyQueue(LinkQueue *q);

Status ClearQueue(LinkQueue *q);

Status QueueEmpty(LinkQueue q);

int QueueLength(LinkQueue q);

Status GetHead(LinkQueue q, QElemType *e);

Status EnQueue(LinkQueue *q, QElemType e);

Status DeQueue(LinkQueue *q, QElemType *e);

Status QueueTraverse(LinkQueue q, void (Visit)(QElemType));

#endif //D_A_LINKQUEUE_H
