//
// Created by fyq on 2020-07-26.
//

#ifndef D_A_COMMON_H
#define D_A_COMMON_H

/* 状态码 */
#define TRUE        1   // 真/是
#define FALSE       0   // 假/否
#define OK          1   // 通过/成功
#define ERROR       0   // 错误/失败
#define INFEASIBLE -1

//系统中已有此状态码定义，要防止冲突
#ifndef OVERFLOW
#define OVERFLOW    -2  //堆栈上溢
#endif

//系统中已有此状态码定义，要防止冲突
#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码类型 */
typedef int status;

/* 布尔类型 */
typedef int boolean;


/*
 * 摁下回车键以继续运行。
 *
 * 通常在测试阶段时，需要让每一步测试都暂停下来，以观察其输出，此时可以让debug=TRUE。
 * 在发布时，可以让debug=FALSE，此时各个测试块将不会暂停。
 */
void PressEnterToContinue(boolean isDebug);

// 测试函数，打印元素
void PrintIntElem(int e);

#endif //D_A_COMMON_H
