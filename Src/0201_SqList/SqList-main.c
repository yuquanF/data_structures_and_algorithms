#include <stdio.h>
#include "SqList.h"

// �ж�data>e�Ƿ����
status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

int main() {
    SqList L;   // ��������˳���

    int i;
    ElemType e;
    boolean debug = FALSE;

    printf("------------- InitList -------------\n");
    {
        printf("��ʼ��˳��� L ...\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);


    printf("------------- ListEmpty -------------\n");
    {
        if(ListEmpty(L) == TRUE) {
            printf("L Ϊ�գ���\n");
        } else {
            printf("L ��Ϊ�գ�\n");
        }
    }
    PressEnterToContinue(debug);


    printf("------------- ListInsert -------------\n");
    {
        for(i = 1; i <= 7; i++) {
            printf("��Ϊʾ������ L �� %d ��λ�ò��� \"%d\"...\n", i, i);
            ListInsert(&L, i, i);
        }
    }
    PressEnterToContinue(debug);


    printf("------------- ListTraverse -------------\n");
    {
        printf("L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintIntElem);
    }
    PressEnterToContinue(debug);


    printf("------------- ListLength -------------\n");
    {
        i = ListLength(L);
        printf("L �ĳ���Ϊ %d \n", i);
    }
    PressEnterToContinue(debug);


    printf("------------- ListDelete -------------\n");
    {
        printf("ɾ��ǰ��Ԫ�أ�L = ");
        ListTraverse(L, PrintIntElem);

        printf("����ɾ�� L �е� 6 ��Ԫ��...\n");

        if(ListDelete(&L, 6, &e) == OK) {
            printf("ɾ���ɹ�����ɾ��Ԫ���ǣ�\"%d\"\n", e);
        } else {
            printf("ɾ��ʧ�ܣ��� 6 ��Ԫ�ز����ڣ�\n");
        }

        printf("ɾ�����Ԫ�أ�L = ");
        ListTraverse(L, PrintIntElem);
    }
    PressEnterToContinue(debug);


    printf("------------- GetElem -------------\n");
    {
        GetElem(L, 4, &e);
        printf("L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
    }
    PressEnterToContinue(debug);


    printf("------------- LocateElem -------------\n");
    {
        i = LocateElem(L, 5, CmpGreater);
        printf("L �е�һ��Ԫ��ֵ���� \"5\" ��Ԫ���� \"%d\" \n", L.elem[i - 1]);
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