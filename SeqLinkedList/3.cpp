//alencryenfo
// 本代码实现了顺序队列的基本操作，解决问题：利用顺序存储结构实现队列的初始化、判空、入队、出队以及获取队头元素。
#include <iostream>
#include <cstdlib>
#define MAXNUM 100

typedef int DataType;  // 定义队列中存储的元素类型

// 顺序队列类型定义
struct SeqQueue {
    DataType q[MAXNUM];  // 用于存储队列元素的数组
    int front, rear;     // 队头和队尾指针
};

typedef SeqQueue* PSeqQueue;

// 初始化顺序队列
PSeqQueue createEmptyQueue_seq(void) {
    PSeqQueue paqu = (PSeqQueue)malloc(sizeof(SeqQueue));
    if (paqu == NULL)
        std::cout << "Out space!!\n";
    else {
        paqu->front = 0;
        paqu->rear = 0;
    }
    return paqu;
}

// 判断顺序队列是否为空
int isEmptyQueue_seq(PSeqQueue paqu) {
    return (paqu->front == paqu->rear);
}

// 入队操作
void enQueue_seq(PSeqQueue paqu, DataType x) {
    if ((paqu->rear + 1) % MAXNUM == paqu->front)
        std::cout << "Full queue.\n";
    else {
        paqu->q[paqu->rear] = x;
        paqu->rear = (paqu->rear + 1) % MAXNUM;
    }
}

// 出队操作
void deQueue_seq(PSeqQueue paqu) {
    if (isEmptyQueue_seq(paqu))
        std::cout << "Empty Queue.\n";
    else
        paqu->front = (paqu->front + 1) % MAXNUM;
}

// 获取队头元素
DataType frontQueue_seq(PSeqQueue paqu) {
    if (isEmptyQueue_seq(paqu)) {
        std::cout << "Empty queue.\n";
        exit(1);
    } else
        return paqu->q[paqu->front];
}

// 测试主函数
int main() {
    PSeqQueue queue = createEmptyQueue_seq();
    enQueue_seq(queue, 5);
    enQueue_seq(queue, 10);
    std::cout << "队头元素: " << frontQueue_seq(queue) << std::endl;
    deQueue_seq(queue);
    std::cout << "新队头元素: " << frontQueue_seq(queue) << std::endl;
    return 0;
}
