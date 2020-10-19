#include <stdio.h>
#include "SqList.h"

// 判断 data > e 是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

int main() {
    SqList L;   // 待操作的顺序表

    int i;
    ElemType e;
    Boolean debug = FALSE;

    printf("------------- InitList -------------\n");
    {
        printf("初始化顺序表 L ...\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);


    printf("------------- ListEmpty -------------\n");
    {
        if(ListEmpty(L) == TRUE) {
            printf("L 为空！\n");
        } else {
            printf("L 不为空！\n");
        }
    }
    PressEnterToContinue(debug);


    printf("------------- ListInsert -------------\n");
    {
        for(i = 1; i <= 7; i++) {
            printf("作为示范，在 L 第 %d 个位置插入 \"%d\"...\n", i, i);
            ListInsert(&L, i, i);
        }
    }
    PressEnterToContinue(debug);


    printf("------------- ListTraverse -------------\n");
    {
        printf("L 中的元素为：L = ");
        ListTraverse(L, PrintIntElem);
    }
    PressEnterToContinue(debug);


    printf("------------- ListLength -------------\n");
    {
        i = ListLength(L);
        printf("L 的长度为 %d \n", i);
    }
    PressEnterToContinue(debug);


    printf("------------- ListDelete -------------\n");
    {
        printf("删除前的元素：L = ");
        ListTraverse(L, PrintIntElem);

        printf("尝试删除 L 中第 6 个元素...\n");

        if(ListDelete(&L, 6, &e) == OK) {
            printf("删除成功，被删除的元素是：\"%d\"\n", e);
        } else {
            printf("删除失败！\n");
        }

        printf("删除元素后的 L = ");
        ListTraverse(L, PrintIntElem);
    }
    PressEnterToContinue(debug);


    printf("------------- GetElem -------------\n");
    {
        GetElem(L, 4, &e);
        printf("L 中第 4 个位置的元素为 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);


    printf("------------- LocateElem -------------\n");
    {
        i = LocateElem(L, 5, CmpGreater);
        printf("L 在第一个元素值大于 \"5\" 的元素是 \"%d\" \n", L.elem[i - 1]);
    }
    PressEnterToContinue(debug);


    printf("------------- PriorElem -------------\n");
    {
        ElemType cur_e = 5;

        if(PriorElem(L, cur_e, &e) == OK) {
            printf("Ԫ�� \"%d\" ��ǰ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("Ԫ�� \"%d\" ��ǰ�������ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue(debug);


    printf("------------- NextElem -------------\n");
    {
        ElemType cur_e = 5;

        if(NextElem(L, cur_e, &e) == OK) {
            printf("Ԫ�� \"%d\" �ĺ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("Ԫ�� \"%d\" �ĺ�̲����ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue(debug);


    printf("------------- ClearList -------------\n");
    {
        printf("��� L ǰ��");
        if(ListEmpty(L) == TRUE) {
            printf(" L Ϊ�գ���\n");
        } else {
            printf(" L ��Ϊ�գ�\n");
        }

        ClearList(&L);

        printf("��� L ��");
        if(ListEmpty(L) == TRUE) {
            printf(" L Ϊ�գ���\n");
        } else {
            printf(" L ��Ϊ�գ�\n");
        }
    }
    PressEnterToContinue(debug);


    printf("------------- DestroyList -------------\n");
    {
        printf("���� L ǰ��");
        if(L.elem != NULL) {
            printf(" L ���ڣ�\n");
        } else {
            printf(" L �����ڣ���\n");
        }

        DestroyList(&L);

        printf("���� L ��");
        if(L.elem != NULL) {
            printf(" L ���ڣ�\n");
        } else {
            printf(" L �����ڣ���\n");
        }
    }
    PressEnterToContinue(debug);


    return 0;
}