//alencryenfo
// 本代码实现了广义表的深拷贝（复制），采用递归算法。解决问题：给定一个广义表，生成其一份独立的深拷贝。
#include <iostream>
#include <cstdlib>
#define OK 1
#define ERROR 0
#define OVERFLOW -1

// 定义元素类型标志，Atom表示原子，List表示子表
typedef enum { Atom, List } ElemTag;

// 定义广义表节点结构体
typedef struct _GLNode {
    ElemTag tag;  // 节点类型标志
    union {
        char atom;  // 原子节点存储一个字符
        struct {
            struct _GLNode *head, *tail;  // 表节点存储表头和表尾指针
        } ptr;
    } p;
} *GList;

// 递归函数：复制广义表，T为复制后的广义表指针，L为原广义表
int CopyGList(GList *T, GList L) {
    if (!L) {           // 如果原表为空，则复制为空
        *T = NULL;
        return OK;
    }

    // 分配新节点内存，如果分配失败则退出
    if (!(*T = (GList)malloc(sizeof(struct _GLNode))))
        exit(OVERFLOW);

    (*T)->tag = L->tag; // 复制节点类型

    if (L->tag == Atom) {
        // 如果为原子节点，直接复制原子值
        (*T)->p.atom = L->p.atom;
    } else {
        // 如果为表节点，递归复制表头和表尾
        CopyGList(&(*T)->p.ptr.head, L->p.ptr.head);
        CopyGList(&(*T)->p.ptr.tail, L->p.ptr.tail);
    }

    return OK;
}

// 测试主函数：构造简单的广义表 ( 'x', ( 'y', 'z' ) )，然后进行深拷贝并输出原表与拷贝表的部分信息
int main() {
    // 构造原广义表 L = ( 'x', ( 'y', 'z' ) )
    GList L = (GList)malloc(sizeof(struct _GLNode));
    L->tag = List;

    // 第一个元素：原子 'x'
    GList node1 = (GList)malloc(sizeof(struct _GLNode));
    node1->tag = Atom;
    node1->p.atom = 'x';

    // 第二个元素：子表 ( 'y', 'z' )
    GList node2 = (GList)malloc(sizeof(struct _GLNode));
    node2->tag = List;
    GList subNode1 = (GList)malloc(sizeof(struct _GLNode));
    subNode1->tag = Atom;
    subNode1->p.atom = 'y';
    GList subNode2 = (GList)malloc(sizeof(struct _GLNode));
    subNode2->tag = Atom;
    subNode2->p.atom = 'z';
    subNode1->p.ptr.tail = subNode2;
    subNode2->p.ptr.tail = NULL;
    node2->p.ptr.head = subNode1;
    node2->p.ptr.tail = NULL;

    // 链接主表：L = ( node1, node2 )
    node1->p.ptr.tail = node2;
    L->p.ptr.head = node1;
    L->p.ptr.tail = NULL;

    // 进行深拷贝
    GList L_copy = NULL;
    CopyGList(&L_copy, L);

    // 输出部分信息验证拷贝效果
    std::cout << "原广义表第一个元素应为: " << node1->p.atom << std::endl;
    std::cout << "拷贝广义表第一个元素为: " << L_copy->p.ptr.head->p.atom << std::endl;

    return 0;
}
