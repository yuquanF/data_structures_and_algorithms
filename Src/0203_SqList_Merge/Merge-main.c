#include "Merge.h"

int main(int argc, char **argv) {
    ElemType a[5] = {1, 3, 5, 7, 9};
    ElemType b[5] = {2, 4, 6, 8, 10};

    SqList La, Lb, Lc1, Lc2;
    int i;

    // 初始化La
    InitList(&La);
    for (i = 1; i <= 5; i++) {
        ListInsert(&La, i, a[i - 1]);
    }

    // 初始化Lb
    InitList(&Lb);
    for (i = 1; i <= 5; i++) {
        ListInsert(&Lb, i, b[i - 1]);
    }

    // 输出La
    printf("La = ");
    ListTraverse(La, PrintIntElem);

    // 输出Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintIntElem);

    // 归并顺序表La和Lb，算法2.2
    MergeSqList_1(La, Lb, &Lc1);
    printf("归并La和Lb为Lc1 = ");
    ListTraverse(Lc1, PrintIntElem);

    // 归并顺序表La和Lb，算法2.7
    MergeSqList_2(La, Lb, &Lc2);
    printf("归并La和Lb为Lc2 = ");
    ListTraverse(Lc2, PrintIntElem);

    return 0;
}
