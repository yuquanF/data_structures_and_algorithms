#include <stdio.h>
#include "Union.h"
#include "SqList.h"

int main(int argc, char **argv) {
    ElemType a[5] = {1, 2, 3, 4, 5};
    ElemType b[7] = {6, 7, 8, 9, 1, 2, 10};
    SqList La, Lb;

    // 初始化La
    InitList(&La);
    for (int i = 1; i <= 5; i++) {
        ListInsert(&La, i, a[i - 1]);
    }

    // 初始化Lb
    InitList(&Lb);
    for (int i = 1; i <= 7; i++) {
        ListInsert(&Lb, i, b[i - 1]);
    }

    // 输出La
    printf("La = ");
    ListTraverse(La, PrintIntElem);

    // 输出Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintIntElem);

    // 输出新表La的内容
    printf("La = La∪Lb = ");
    Union(&La, Lb);
    ListTraverse(La, PrintIntElem);

    return 0;
}
