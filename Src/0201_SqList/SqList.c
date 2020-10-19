#include "SqList.h"

/*
 * 算法2.3
 *
 * 初始化
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(SqList *L) {
    // 分配指定容量的内存，如果分配失败，则返回NULL
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL) {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/*
 * 销毁(结构)
 *
 * 释放顺序表所占内存。
 */
Status DestroyList(SqList *L) {
    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
    return OK;
}

/*
 * 置空(内容)
 *
 * 只是清理顺序表中存储的数据，不释放顺序表所占内存。
 */
Status ClearList(SqList *L) {
    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    L->length = 0;
    return OK;
}

/*
 * 判空
 *
 * 判断顺序表中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序表为空
 * FALSE: 顺序表不为空
 */
Boolean ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

/*
 * 计数
 *
 * 返回顺序表包含的有效元素的数量。
 */
int ListLength(SqList L) {
    return L.length;
}

/*
 * 取值
 *
 * 获取顺序表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
Status GetElem(SqList L, int i, ElemType *e) {
    // 确保顺序表结构存在
    if (L.elem == NULL) {
        return ERROR;
    }
    // 因为i的含义是位置，所以其合法范围是：[1, length]
    if (i < 1 || i > L.length) {
        return ERROR;                    //i值不合法
    }
    *e = L.elem[i - 1];
    return OK;
}

/*
 * 算法2.6
 *
 * 查找
 *
 * 返回顺序表中首个与e满足compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是compare函数第二个形参
 */
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    // 确保顺序表结构存在
    if (L.elem == NULL) {
        return ERROR;
    }
    ElemType *p = L.elem;
    int idx = 0;
    for (int i = 0; i < L.length; i++) {
        if (compare(p[i], e) == OK) {
            idx = i + 1;
        }
    }
    return idx;
}

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    // 确保顺序表结构存在，且最少包含两个元素
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }
    ElemType *p = L.elem;
    Status flag = ERROR;
    for (int i = 1; i < L.length; i++) {
        // 从索引1开始查找，若找到，设置标志位为OK，并设置pre_e的值
        if (p[i] == cur_e) {
            flag = OK;
            *pre_e = p[i - 1];
            break;
        }
    }
    return flag;
}

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    // 确保顺序表结构存在，且最少包含两个元素
    if (L.elem == NULL || L.length < 2) {
        return ERROR;
    }
    ElemType *p = L.elem;
    Status flag = ERROR;
    for (int i = 0; i < L.length - 1; i++) {
        // 从索引0开始查找，到length-1截止，若找到，设置标志位为OK，并设置next_e的值
        if (p[i] == cur_e) {
            flag = OK;
            *next_e = p[i + 1];
            break;
        }
    }
    return flag;
}

/*
 *  算法2.4
 *
 * 插入
 *
 * 向顺序表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SqList *L, int i, ElemType e) {
    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }
    // i值越界
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }

    ElemType *newBase, *p;
    // 检验L是否已满
    if (L->length >= L->listsize) {
        newBase = (ElemType *) realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (newBase == NULL) {
            exit(OVERFLOW);
        }
        L->elem = newBase;
        L->listsize += LIST_INCREMENT;
    }
    // 插入之后的元素后移
    p = L->elem;
    for (int j = L->length; j > i - 1; j--) {
        p[j] = p[j - 1];
    }
    p[i-1] = e;
    L->length += 1;
    return OK;
}

/*
 *  算法2.5
 *
 * 删除
 *
 * 删除顺序表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(SqList *L, int i, ElemType *e) {
    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }
    // i值越界
    if (i < 1 || i > L->length) {
        return ERROR;
    }

    ElemType *p = L->elem;

    // 获取被删元素
    *e = p[i - 1];
    // 删除的位置之后的元素前移
    for (int j = i - 1; j < L->length - 1; j++) {
        p[j] = p[j + 1];
    }

    L->length -= 1;
    return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void (*visit)(ElemType)) {
    for(int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
    }

    printf("\n");
}