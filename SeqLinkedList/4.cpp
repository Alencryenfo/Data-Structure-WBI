//alencryenfo
// 本代码实现了链式队列的基本操作，解决问题：利用链式存储结构实现队列的初始化、判空、入队、出队以及获取队头元素。
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;  // 定义队列中存储的元素类型

// 单链表结点结构，用于链式队列
struct Node {
    DataType info;
    Node *link;
};

// 链式队列类型定义
struct LinkQueue {
    Node *front;  // 队头指针
    Node *rear;   // 队尾指针
};

typedef LinkQueue* PLinkQueue;

// 初始化链式队列
PLinkQueue createEmptyQueue_link() {
    PLinkQueue plqu = (PLinkQueue)malloc(sizeof(LinkQueue));
    if (plqu != NULL) {
        plqu->front = plqu->rear = NULL;
    } else {
        cout << "Out space!!\n";
    }
    return plqu;
}

// 判断链式队列是否为空
int isEmptyQueue_link(PLinkQueue plqu) {
    return (plqu->front == NULL);
}

// 入队操作（链式实现）
void enQueue_link(PLinkQueue plqu, DataType x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        cout << "Out of space!\n";
    else {
        p->info = x;
        p->link = NULL;
        if (plqu->front == NULL) {
            plqu->front = p;
            plqu->rear = p;
        } else {
            plqu->rear->link = p;
            plqu->rear = p;
        }
    }
}

// 出队操作（链式实现）
void deQueue_link(PLinkQueue plqu) {
    Node *p;
    if (plqu->front == NULL)
        cout << "Empty queue.\n";
    else {
        p = plqu->front;
        plqu->front = plqu->front->link;
        free(p);
    }
}

// 获取队头元素（链式实现）
DataType frontQueue_link(PLinkQueue plqu) {
    if (plqu->front == NULL) {
        cout << "Empty queue.\n";
        exit(1);
    }
    return plqu->front->info;
}

// 测试主函数
int main() {
    PLinkQueue queue = createEmptyQueue_link();
    enQueue_link(queue, 15);
    enQueue_link(queue, 25);
    cout << "队头元素: " << frontQueue_link(queue) << endl;
    deQueue_link(queue);
    cout << "新队头元素: " << frontQueue_link(queue) << endl;
    return 0;
}
