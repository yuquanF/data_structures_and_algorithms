#include "Union.h"

/*
 * 算法2.1
 *
 * A=A∪B
 *
 * 计算La与Lb的并集并返回。
 * 由于生成的并集会拼接在La上，所以La的入参为指针类型。
 */
void Union(SqList* La, SqList Lb) {
    ElemType e;
    int aLen = La->length;
    for (int i = 0; i < Lb.length; i++)
    {
        // 遍历Lb中元素，找到不存在La中的元素，插入La中
        e = Lb.elem[i];
        if (!LocateElem(*La, e, equal))
        {
            ListInsert(La, ++aLen, e);
        }
    }
}

/*
 * 判等
 *
 * 判断两元素是否相等。
 * 如果相等，则返回TRUE，否则，返回FALSE。
 */
boolean equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}