#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define FALSE 0
#define TRUE 1

typedef int ElemType; // 定义元素类型为整型

typedef struct Node {
    // 单链表结点结构
    ElemType info;
    Node *next;
} Node, *PNode; // 结点及结点指针类型

typedef struct LinkList {
    // 单链表类型定义
    PNode head; // 指向单链表中的第一个结点（通常是头结点）
} LinkList, *PLinkList; // 单链表类型及指针类型

PLinkList pllist; // pllist是指向单链表的一个指针变量 (全局变量，通常建议作为参数传递)

void insert_link(PLinkList pList, ElemType x, PNode p)
// 在单链表 pList 中 p 所指结点的后面插入元素 x
{
    PNode q;
    q = (PNode) malloc(sizeof(Node)); // 分配新结点空间
    if (q == NULL) {
        cout << "内存分配失败，无法插入新结点" << endl; // 使用 cout 输出
        return; // 或者进行其他错误处理
    }
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void delete_link(PLinkList pList, ElemType x)
// 在 pList 所指的带有头结点的单链表中删除元素为 x 的结点
{
    PNode p, q;
    p = pList->head;
    // 在 pList 所指的带有头结点的单链表中查找元素为 x 的结点的前驱结点
    while (p->next != NULL && p->next->info != x) {
        p = p->next;
    }

    if (p->next == NULL) {
        // 未找到元素为 x 的结点
        cout << "链表中不存在值为 " << x << " 的结点" << endl;
    } else {
        q = p->next; // q 指向待删除结点
        p->next = q->next; // 从链表中移除 q
        free(q); // 释放 q 所指结点的内存
    }
}

PNode locate_link(PLinkList pList, ElemType x)
// 在 pList 所指的带有头结点的单链表中查找元素为 x 的结点，并返回其指针
// 若未找到，则返回 NULL
{
    PNode p;
    p = pList->head->next; // 从第一个数据结点开始查找
    while (p != NULL && p->info != x) {
        p = p->next;
    }
    return p; // p 为 NULL 或指向找到的结点
}

PLinkList createNullList_link()
/* 创建一个带头结点的空链表 */
{
    PLinkList pllist;
    PNode p;
    pllist = (PLinkList) malloc(sizeof(struct LinkList));
    if (pllist != NULL) {
        p = (PNode) malloc(sizeof(struct Node));
        if (p != NULL) {
            pllist->head = p;
            p->next = NULL;
        } else {
            printf("内存不足，无法分配内存\n");
            pllist->head = NULL;
        }
    } else
        printf("内存不足，无法分配内存\n");
    return pllist;
}





//这里补充静态链表的特殊函数
void InitList (SLinkList list)
{
    int  i;
    for(i = 0; i < MaxSize - 1; i++)
        list[i].cursor = i + 1;
    list[MaxSize-1].cursor = 0;
}
int Malloc (SLinkList list)
{/* Always return the first available unit */
    int  i;
    i = list[0].cursor;
    if (list[0].cursor != 0)
        list[0].cursor = list[i].cursor;
    return i;
}
void Free (SLinkList list, int k)
{
    list[k].cursor = list[0].cursor;
    list[0].cursor = k;
}