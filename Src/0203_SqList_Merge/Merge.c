#include "Merge.h"

/*
 *  算法2.2
 *
 * 非递减链表归并：C=A+B
 *
 * 归并顺序表La和Lb，生成新的顺序表Lc。
 * 其中，La、Lb、Lc均为非递减序列。
 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc) {
    int i = 0, j = 0, k = 0;
    int lenA = La.length;
    int lenB = Lb.length;
    ElemType eA, eB, e;

    InitList(Lc);

    while (i < lenA && j < lenB) {
        eA = La.elem[i];
        eB = Lb.elem[j];
        if (eA <= eB) {
            e = eA;
            i++;
        } else {
            e = eB;
            j++;
        }
        ListInsert(Lc, ++k, e);
    }
    while (i < lenA) {
        e = La.elem[i++];
        ListInsert(Lc, ++k, e);
    }
    while (j < lenB) {
        e = Lb.elem[j++];
        ListInsert(Lc, ++k, e);
    }
}

/*
 *  算法2.7
 *
 * 非递减链表归并：C=A+B
 *
 * 归并顺序表La和Lb，生成新的顺序表Lc。
 * 其中，La、Lb、Lc均为非递减序列。
 */
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc) {
    ElemType* pa, * pb, * pc;
    ElemType* pa_last, * pb_last;

    pa = La.elem;                        // 指向La第一个元素
    pb = Lb.elem;                        // 指向Lb第一个元素

    // 没有使用InitList创建Lc
    Lc->listsize = Lc->length = La.length + Lb.length;
    pc = Lc->elem = (ElemType*) malloc(Lc->listsize * sizeof(ElemType));
    if(pc == NULL) {
        exit(OVERFLOW);
    }

    pa_last = La.elem + La.length - 1;    // 指向La最后一个元素
    pb_last = Lb.elem + Lb.length - 1;    // 指向Lb最后一个元素

    // 如果La及Lb均未遍历完
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }

    // 如果Lb已遍历完，但La还未遍历完，将La中剩余元素加入Lc
    while(pa <= pa_last) {
        *pc++ = *pa++;
    }

    // 如果La已遍历完，但Lb还未遍历完，将Lb中剩余元素加入Lc
    while(pb <= pb_last) {
        *pc++ = *pb++;
    }
}