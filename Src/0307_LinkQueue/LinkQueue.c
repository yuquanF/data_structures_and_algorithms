//
// Created by fyq on 2020/10/19.
//

#include "LinkQueue.h"

/**
 * 初始化，构造一个空的链队。
 * 这里的队列是带有头结点的
 * @param q
 * @return
 */
Status InitQueue(LinkQueue *q) {
    if (q == NULL) {
        return ERROR;
    }

    q->front = q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (q->front == NULL) {
        exit(OVERFLOW);
    }

    q->front->next = NULL;

    return OK;
}

/**
 * 销毁，需要释放链队所占的所有内存。
 * @param q
 * @return
 */
Status DestroyQueue(LinkQueue *q) {
    if (q == NULL) {
        return ERROR;
    }

    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }

    return OK;
}

/**
 * 置空，需要释放除头结点外的空间
 * @param q
 * @return
 */
Status ClearQueue(LinkQueue *q) {
    if (q == NULL) {
        return ERROR;
    }

    q->rear = q->front->next;

    while (q->rear) {
        q->front->next = q->rear->next; // 保留了头结点，用头结点指向下一结点
        free(q->rear);
        q->rear = q->front->next;
    }

    q->rear = q->front;

    return OK;
}

Status QueueEmpty(LinkQueue q) {
    if (q.front == q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 计算链队包含的有效元素的数量（不包含头结点）
 * @param q
 * @return
 */
int QueueLength(LinkQueue q) {
    int count = 0;
    QueuePtr p = q.front;

    while (p != q.rear) { // 因为p从头结点开始，所以循环结束条件是p == q.rear
        count++;
        p = p->next;
    }

    return count;
}

Status GetHead(LinkQueue q, QElemType *e) {
    if (q.front == NULL || q.front == q.rear) {
        return ERROR;
    }

    *e = q.front->next->data;

    return OK;
}

Status EnQueue(LinkQueue *q, QElemType e) {
    if (q == NULL || q->front == NULL) {
        return ERROR;
    }

    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (p == NULL) {
        exit(OVERFLOW);
    }

    p->data = e;
    p->next = NULL;

    q->rear->next = p;
    q->rear = p;

    return OK;
}

Status DeQueue(LinkQueue *q, QElemType *e) {
    if (q == NULL || q->front == NULL || q->front == q->rear) {
        return ERROR;
    }

    QueuePtr ptr = q->front->next;
    *e = ptr->data;

    q->front->next = ptr->next;
    // 避免删除最后一个结点，q->rear变成野指针
    if (q->rear == ptr) {
        q->rear = q->front;
    }

    free(ptr);

    return OK;
}

Status QueueTraverse(LinkQueue q, void (Visit)(QElemType)) {
    if (q.front == NULL) {
        return ERROR;
    }

    QueuePtr p = q.front->next;

    while (p != NULL) {
        Visit(p->data);
        p = p->next;
    }

    return OK;
}