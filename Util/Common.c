#include <stdio.h>
#include "Common.h"


void PressEnterToContinue(Boolean isDebug) {
    fflush(stdin);

    // 处于测试阶段时，可以让debug=TRUE，手动输入换行，以便让程序暂停下来，观察每一步的输出
    if (isDebug) {
        printf("\nPress Enter to Continue...");
        getchar();

        // 发布时，可以让debug=FALSE，自动添加换行，直接出结果
    } else {
        printf("\n");
    }

    fflush(stdin);
}

// 测试函数，打印元素
void PrintIntElem(int e) {
    printf("%d ", e);
}