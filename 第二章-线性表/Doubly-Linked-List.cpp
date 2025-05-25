#include <iostream>
#include <cstdlib> // 包含 malloc, free 等函数的声明
#include <cassert> // 包含 assert 函数的声明

using namespace std;

#define FALSE 0
#define TRUE 1

typedef int DataType; // 定义数据元素类型为整型

// 双向链表结点定义
typedef struct DoubleNode {
    DataType info;
    DoubleNode *llink, *rlink; // llink 指向前驱结点，rlink 指向后继结点
}DoubleNode, *PDoubleNode;

// 双向链表类型定义
typedef struct DoubleList {
    PDoubleNode head; // 指向头结点 (通常是一个哑结点/哨兵结点)
    PDoubleNode tail; // 指向最后一个实际数据结点 (若列表为空，可指向头结点)
    // int length;    // 可选：用于存储链表当前长度
} DoubleList, *PDoubleList;

// 全局双向链表指针变量 (通常建议将链表指针作为参数传递，而不是使用全局变量)
// 注意：函数参数中的 pdlist 会覆盖此全局变量 pdlist。
PDoubleList  pdlist;


// 函数：GetData_dbllink
// 功能：获取双向链表 pdlist 中第 i 个数据结点 (1-indexed)。
// 返回：成功则返回指向第 i 个数据结点的指针；若 i 无效或结点不存在，则返回 NULL。
PDoubleNode GetData_dbllink(PDoubleList pdlist, int i) {
    if (i <= 0) { // 位置编号从1开始
        return NULL;
    }

    PDoubleNode p = pdlist->head->rlink; // p 指向第一个数据结点
    int count = 1;

    // 遍历链表寻找第 i 个结点
    while (p != NULL && count < i) {
        p = p->rlink;
        count++;
    }

    // 如果 p 不为 NULL 且 count 等于 i, 则找到了第 i 个结点
    // 如果 p 为 NULL (链表长度小于 i) 或 count 未达到 i (虽然 p 不为 NULL 但 i 过大，理论上这种情况不会发生，因为 count 会先达到 i 或 p 变为 NULL)
    // 实际上，循环结束后，如果 p 不是 NULL，那么 count 必然等于 i。
    // 如果 p 是 NULL，说明 i 超出了链表长度。
    if (p != NULL && count == i) {
        return p;
    } else {
        return NULL; // 未找到第 i 个结点 (i 超出范围或链表为空)
    }
}


/*
 * 函数名：insert_dbllink
 * 功能：在带有头结点的双向链表 pdlist 中，在第 i 个数据结点前插入一个新结点，其值为 x。
 * 参数：
 *   pdlist: 指向双向链表控制结构的指针。
 *   i:      目标插入位置，新结点将插入在原第 i 个结点之前 (1-indexed)。
 *   x:      要插入的数据元素的值。
 * 注意：此函数假定 GetData_dbllink(pdlist, i) 能正确返回第 i 个结点。
 *       如果 i 超出范围 (例如 i <= 0 或 i > 当前链表长度)，则 GetData_dbllink 应返回 NULL。
 */
void insert_dbllink(PDoubleList pdlist, int i, DataType x) {
    PDoubleNode p; // p 将指向原链表中第 i 个位置的结点
    PDoubleNode s; // s 是将要插入的新结点

    // 获取第 i 个位置的结点指针
    // 如果 i 无效 (例如，i <= 0，或 i 大于链表长度导致第 i 个结点不存在)，
    // GetData_dbllink 应返回 NULL。
    p = GetData_dbllink(pdlist, i);

    if (p == NULL) {
        cout << "插入位置 " << i << " 无效或超出范围！" << endl;
        return;
    }

    // 分配新结点内存
        s = (P DoubleNode)malloc( sizeof( DoubleNode) );
    if (s == NULL) {
        cout << "内存分配失败，无法插入新结点！" << endl;
        // assert(s != NULL); // 或者使用 assert 终止程序，更符合其他文件的风格
        return;
        }
    assert(s != NULL); // 确保内存分配成功

    s->info = x;

    // 将新结点 s 插入到 p 结点之前
    s->llink = p->llink; // s 的前驱是 p 的原前驱
    s->rlink = p;       // s 的后继是 p

    // 更新 p 的原前驱结点的后继指针
    // (p->llink 指向的是哑头结点或 p 之前的另一个数据结点，它不应为 NULL)
    if (p->llink != NULL) { // 防御性检查，对于带哑头结点的链表，p->llink 总是有效
        p->llink->rlink = s;
    } else {
        // 理论上，如果 p 是第一个数据结点，p->llink 指向哑头结点。
        // 如果 p->llink 为 NULL，可能意味着 p 是头结点本身，或者链表结构不符合预期。
        // 对于“在第i个数据结点前插入”的场景，p 不应是哑头结点。
        // 如果 pdlist->head 就是第一个数据结点（无哑结点），且 p 是第一个结点，
        // 则 pdlist->head 需要更新为 s。但题目指明“带有头结点”，通常指哑头结点。
    }

    p->llink = s;       // p 的前驱更新为 s

    // 注意：此函数未处理 pdlist->tail 的更新。
    // 如果插入操作可能影响尾结点 (例如，如果允许通过特殊的 i 值在链表末尾插入，
    // 或者链表为空时插入第一个元素)，则需要相应更新 pdlist->tail。
    // 当前逻辑是“在第i个结点前插入”，不直接改变尾结点，除非链表为空且 GetData_dbllink 有特殊处理。
}

/*
 * 函数名：delete_dbllink
 * 功能：删除带有头结点的双向链表 pdlist 中的第 i 个数据结点。
 * 参数：
 *   pdlist: 指向双向链表控制结构的指针。
 *   i:      要删除的结点的位置 (1-indexed)。
 * 注意：此函数假定 GetData_dbllink(pdlist, i) 能正确返回第 i 个结点。
 */
void delete_dbllink(PDoubleList pdlist, int i) {
    PDoubleNode p; // p 将指向要删除的结点

    // 获取第 i 个位置的结点指针
    p = GetData_dbllink(pdlist, i);

    if (p == NULL) { // 如果 i 无效或结点不存在
        cout << "删除位置 " << i << " 无效或结点不存在，无法删除！" << endl;
        return;
    }

    // p 是一个有效的数据结点
    // p->llink 指向 p 的前驱 (可能是哑头结点或其他数据结点)
    // p->rlink 指向 p 的后继 (可能是 NULL 或其他数据结点)

    // 从链中断开 p
    if (p->llink != NULL) { // p 的前驱的 rlink 指向 p 的后继
        p->llink->rlink = p->rlink;
    } else {
        // 如果 p->llink 为 NULL，意味着 p 是链表的第一个结点，且没有哑头结点，
        // 或者链表结构特殊。对于带哑头结点的标准实现，数据结点的 p->llink 不会是 NULL。
        // 如果 pdlist->head 是哑结点，则 p->llink 指向它。
        // 如果 p 是第一个数据结点，则 pdlist->head->rlink (哑头的rlink) 需要更新。
        // 这一步由 p->llink->rlink = p->rlink; (当p->llink是哑头时) 隐式完成。
    }

    if (p->rlink != NULL) { // p 的后继的 llink 指向 p 的前驱
        p->rlink->llink = p->llink;
    } else {
        // p 是最后一个数据结点，需要更新 pdlist->tail
        // 新的尾结点是 p 的前驱 (p->llink)
        // 如果 p 也是第一个数据结点 (链表只有一个元素)，则 p->llink 是哑头结点，
        // 此时 pdlist->tail 应指向哑头结点，表示链表变空。
        pdlist->tail = p->llink;
    }

    free(p); // 释放被删除结点的内存

    // 可选：如果 pdlist->length 存在，则需要递减。
    // cout << "成功删除第 " << i << " 个结点。" << endl; // 可选的成功消息
}
