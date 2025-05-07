//
// Created by 26444 on 25-3-17.
//
//alencryenfo
// 本代码实现了计算广义表的深度，采用递归算法。解决问题：给定一个广义表，计算其嵌套层数（深度）。
#include <iostream>
#include <cstdlib>
#define OK 1

// 定义元素类型标志，Atom表示原子，List表示子表
typedef enum { Atom, List } ElemTag;
typedef int AtomType;

// 定义广义表节点结构体，采用递归结构存储
typedef struct _GLNode {
    ElemTag tag; // 节点类型标志
    union {
        AtomType atom; // 当节点为原子时，存储其值
        struct {
            struct _GLNode *head, *tail; // 当节点为表时，head指向表头，tail指向表尾
        } ptr;
    } p;
} *GList;

// 递归函数：计算广义表的深度
int GListDepth(GList L) {
    if (!L) return 1;             // 空表的深度定义为1
    if (L->tag == Atom) return 0;   // 原子的深度为0

    int maxDepth = 0, depth;
    // 遍历广义表中每个元素
    for (GList p = L; p; p = p->p.ptr.tail) {
        depth = GListDepth(p->p.ptr.head);
        if (depth > maxDepth) maxDepth = depth;
    }
    return maxDepth + 1;
}

// 测试主函数：构造简单的广义表 (a, (b, c)) 并计算其深度
int main() {
    // 构造广义表节点，手动构造表示：( 'a', ( 'b', 'c' ) )
    GList L = (GList)malloc(sizeof(struct _GLNode));
    L->tag = List;

    // 构造表头节点 (原子 'a')
    GList node1 = (GList)malloc(sizeof(struct _GLNode));
    node1->tag = Atom;
    node1->p.atom = 'a';

    // 构造表尾节点，表示子表 ( 'b', 'c' )
    GList node2 = (GList)malloc(sizeof(struct _GLNode));
    node2->tag = List;

    // 表头部分 of 子表：原子 'b'
    GList subNode1 = (GList)malloc(sizeof(struct _GLNode));
    subNode1->tag = Atom;
    subNode1->p.atom = 'b';

    // 表尾部分 of 子表：原子 'c'
    GList subNode2 = (GList)malloc(sizeof(struct _GLNode));
    subNode2->tag = Atom;
    subNode2->p.atom = 'c';

    // 链接子表节点：子表 = ( 'b', 'c' )
    subNode1->p.ptr.tail = subNode2;
    subNode2->p.ptr.tail = NULL;
    node2->p.ptr.head = subNode1;
    node2->p.ptr.tail = NULL;

    // 链接主表：L = ( node1, node2 )
    node1->p.ptr.tail = node2;
    L->p.ptr.head = node1;
    L->p.ptr.tail = NULL;

    int depth = GListDepth(L);
    std::cout << "广义表的深度为: " << depth << std::endl;

    return 0;
}
