//alencryenfo
// 本代码实现了链式栈的基本操作，解决问题：利用链式存储结构实现栈的初始化、判空、压栈、弹栈以及获取栈顶元素。
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;  // 定义栈中元素类型

// 单链表结点结构
struct Node {
    DataType info;  // 存储数据
    Node *link;     // 指向下一个结点的指针
};

// 链式栈类型定义
struct LinkStack {
    Node *top;  // 指向栈顶结点的指针
};

typedef LinkStack* PLinkStack;

// 判断链式栈是否为空
int isEmptyStack_link(PLinkStack plstack) {
    return (plstack->top == NULL);
}

// 初始化链式栈
PLinkStack createEmptyStack_link() {
    PLinkStack plstack = (PLinkStack)malloc(sizeof(LinkStack));
    if (plstack != NULL)
        plstack->top = NULL;
    else
        cout << "Out of space!\n";
    return plstack;
}

// 压栈操作（链式实现）
void push_link(PLinkStack plstack, DataType x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        cout << "Out of space!\n";
    else {
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
    }
}

// 弹栈操作（链式实现）
DataType pop_link(PLinkStack plstack) {
    Node *p;
    DataType elem;
    if (isEmptyStack_link(plstack))
        cout << "Empty stack pop.\n";
    else {
        p = plstack->top;
        elem = p->info;
        plstack->top = plstack->top->link;
        free(p);
    }
    return elem;
}

// 获取栈顶元素（链式实现）
DataType top_link(PLinkStack plstack) {
    if (isEmptyStack_link(plstack)) {
        cout << "Empty Stack!\n";
        exit(1);
    } else
        return plstack->top->info;
}

// 测试主函数
int main() {
    PLinkStack stack = createEmptyStack_link();
    push_link(stack, 30);
    push_link(stack, 40);
    cout << "链式栈顶元素: " << top_link(stack) << endl;
    cout << "弹出元素: " << pop_link(stack) << endl;
    return 0;
}
