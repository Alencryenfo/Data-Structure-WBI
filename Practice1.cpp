#include <iostream>
using namespace std;

// 节点定义
struct node {
    int data;  // 存储数据
    node* next;  // 指向下一个节点
};

// 创建空循环链表（带头结点）
void createNullList(node*& head) {
    head = new node;
    head->next = head;  // 头结点指向自己
}

// 插入节点到循环链表尾部
void insertNode(node* head, int x) {
    node* new_node = new node;
    new_node->data = x;
    node* temp = head;
    // 找到最后一个节点（next指向头结点）
    while (temp->next != head) {
        temp = temp->next;
    }
    new_node->next = head;  // 新节点指向头结点
    temp->next = new_node;  // 原尾节点指向新节点
}

// 合并两个有序循环链表（从小到大）
node* mergeAscending(node* list1, node* list2) {
    node* merged = new node;
    merged->next = merged;  // 初始化空循环链表
    node* tail = merged;    // 跟踪合并链表的尾部

    node* p1 = list1->next; // list1的第一个数据节点
    node* p2 = list2->next; // list2的第一个数据节点

    // 合并主循环
    while (p1 != list1 && p2 != list2) {
        if (p1->data <= p2->data) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
        tail->next = merged; // 每次更新尾部指向头结点
    }

    // 处理剩余节点
    if (p1 != list1) {
        tail->next = p1;
        while (p1->next != list1) p1 = p1->next;
        p1->next = merged;
    }
    if (p2 != list2) {
        tail->next = p2;
        while (p2->next != list2) p2 = p2->next;
        p2->next = merged;
    }

    return merged;
}

// 反转循环链表
void reverseCircularList(node* head) {
    // 检查链表是否为空：头结点的next指向自己，说明没有数据节点
    if (head->next == head) return;
    node* prev = head;       // 前驱指针，初始指向头结点
    node* curr = head->next; // 当前指针，初始指向第一个数据节点
    node* next = nullptr;    // 临时保存下一个节点的指针
    node* firstNode = curr;  // 保存原链表的第一个数据节点
    //反转代码
    do {
        next = curr->next;   // 保存当前节点的下一个节点
        curr->next = prev;   // 反转指针：当前节点的next指向前驱节点
        prev = curr;         // 前驱指针后移
        curr = next;         // 当前指针后移
    } while (curr != head);  // 循环直到回到头结点

    // 调整头结点和尾节点的指针
    head->next = prev;       // 头结点的next指向新的首节点
    firstNode->next = head;  // 原首节点的next重新指向头结点，维持循环结构
}

// 合并降序：先升序合并再反转
node* mergeDescending(node* list1, node* list2) {
    node* merged = mergeAscending(list1, list2);
    reverseCircularList(merged);
    return merged;
}

// 打印循环链表
void printList(node* head) {
    if (head->next == head) {
        cout << "空链表" << endl;
        return;
    }
    node* temp = head->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // 创建并填充链表A（从小到大：10, 30, 50）
    node* listA;
    createNullList(listA);
    insertNode(listA, 10);
    insertNode(listA, 30);
    insertNode(listA, 50);
    cout << "链表A: ";
    printList(listA); // 输出: 10 30 50

    // 创建并填充链表B（20, 40, 60）
    node* listB;
    createNullList(listB);
    insertNode(listB, 20);
    insertNode(listB, 40);
    insertNode(listB, 60);
    cout << "链表B: ";
    printList(listB); // 输出: 20 40 60

    // 合并测试（从小到大）
    node* mergedAsc = mergeAscending(listA, listB);
    cout << "升序合并结果: ";
    printList(mergedAsc); //10 20 30 40 50 60

    // 合并测试（从大到小）
    node* mergedDesc = mergeDescending(listA, listB);
    cout << "降序合并结果: ";
    printList(mergedDesc); //60 50 40 30 20 10

    return 0;
}