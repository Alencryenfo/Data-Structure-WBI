//alencryenfo
// 本代码实现了顺序栈的基本操作，解决问题：利用顺序存储结构实现栈的初始化、判空、压栈、弹栈以及获取栈顶元素。
#include <iostream>
#include <cstdlib>
#define MAXNUM 100

typedef int ElemType;  // 定义栈中元素的数据类型

// 顺序栈类型定义
typedef struct SeqStack {
    ElemType s[MAXNUM];  // 用于存储栈元素的数组
    int top;             // 栈顶指针
} SeqStack, *PSeqStack;

// 初始化顺序栈
PSeqStack createEmptyStack_seq(void) {
    PSeqStack pastack = (PSeqStack)malloc(sizeof(SeqStack));
    if (pastack == NULL)
        std::cout << "Out of space!!\n";
    else
        pastack->top = -1;  // 空栈时，top为-1
    return pastack;
}

// 判断顺序栈是否为空
int isEmptyStack_seq(PSeqStack pastack) {
    return (pastack->top == -1);
}

// 压栈操作
void push_seq(PSeqStack pastack, ElemType x) {
    if (pastack->top >= MAXNUM - 1)
        std::cout << "overflow!\n";
    else {
        pastack->top = pastack->top + 1;
        pastack->s[pastack->top] = x;
    }
}

// 弹栈操作
ElemType pop_seq(PSeqStack pastack) {
    ElemType temp;
    if (isEmptyStack_seq(pastack))
        std::cout << "Underflow!\n";
    else {
        temp = pastack->s[pastack->top];
        pastack->top = pastack->top - 1;
    }
    return temp;
}

// 获取栈顶元素
ElemType top_seq(PSeqStack pastack) {
    if (isEmptyStack_seq(pastack)) {
        std::cout << "Empty Stack!\n";
        exit(1);
    } else
        return pastack->s[pastack->top];
}

// 测试主函数
int main() {
    PSeqStack stack = createEmptyStack_seq();
    push_seq(stack, 10);
    push_seq(stack, 20);
    std::cout << "顺序栈顶元素: " << top_seq(stack) << std::endl;
    std::cout << "弹出元素: " << pop_seq(stack) << std::endl;
    return 0;
}
