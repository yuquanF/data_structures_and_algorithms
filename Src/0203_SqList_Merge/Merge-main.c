#include "Merge.h"

int main(int argc, char **argv) {
    ElemType a[5] = {1, 3, 5, 7, 9};
    ElemType b[5] = {2, 4, 6, 8, 10};

    SqList La, Lb, Lc1, Lc2;
    int i;

    // ��ʼ��La
    InitList(&La);
    for (i = 1; i <= 5; i++) {
        ListInsert(&La, i, a[i - 1]);
    }

    // ��ʼ��Lb
    InitList(&Lb);
    for (i = 1; i <= 5; i++) {
        ListInsert(&Lb, i, b[i - 1]);
    }

    // ���La
    printf("La = ");
    ListTraverse(La, PrintIntElem);

    // ���Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintIntElem);

    // �鲢˳���La��Lb���㷨2.2
    MergeSqList_1(La, Lb, &Lc1);
    printf("�鲢La��LbΪLc1 = ");
    ListTraverse(Lc1, PrintIntElem);

    // �鲢˳���La��Lb���㷨2.7
    MergeSqList_2(La, Lb, &Lc2);
    printf("�鲢La��LbΪLc2 = ");
    ListTraverse(Lc2, PrintIntElem);

    return 0;
}
