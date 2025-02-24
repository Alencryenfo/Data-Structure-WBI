#include <iostream>
using namespace std;
//封装一个单向链表
struct node {
    int data;//存储数据
    node *next;//单向链表的后继
};
// 创建空链表
void createNullList_seq(node*& head) {
    head = nullptr;  // 初始化为空链表
}

// 插入元素 x 到链表中的位置 p
bool insert_seq(node*& head, int x, int p) {
    node* new_node = new node;
    new_node->data = x;
    if (p == 0) {//处理插入位置为头的情况
        new_node->next = head;
        head = new_node;
        return true;
    }
    node* temp = head;
    for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }//寻找到插入位置的前一个元素
    if (temp == nullptr) {//判断超过链表的长度
        delete new_node;
        return false;  //插入位置无效
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return true;
}

// 删除位置 p 的元素
bool delete_seq(node*& head, int p) {
    if (head == nullptr) return 0; //链表为空的情况
    node* temp = head;
    if (p == 0) {
        head = temp->next;
        delete temp;
        return true;
    }
    for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }//寻找到插入位置的前一个元素
    if (temp == nullptr || temp->next == nullptr) {//前一个和要删除的元素均不可以为空指针
        return false; // 删除位置无效
    }
    node* to_delete = temp->next;
    temp->next = to_delete->next;//直接和删除元素的下一位连接
    delete to_delete;
    return true;
}

// 查找链表中第一个值为 x 的元素位置
int locate_seq(node* head, int x) {
    node* temp = head;
    int pos = 0;
    while (temp != nullptr) {//遍历到最后一个元素
        if (temp->data == x) {
            return pos;
        }
        temp = temp->next;
        ++pos;
    }
    return -1;  // 未找到
}

// 获取链表中位置 p 处的元素值
int retrieve_seq(node* head, int p) {
    node* temp = head;
    for (int i = 0; i < p && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr) return -1;  // 位置无效
    return temp->data;
}

// 获取链表中位置 p 后一个元素的下标
int next_seq(node* head, int p) {
    node* temp = head;
    for (int i = 0; i < p && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return -1;  // 后继不存在
    node* next_node = temp->next;
    int pos = p + 1;
    while (next_node->next != nullptr) {
        next_node = next_node->next;
        ++pos;
    }
    return pos;
}

// 获取链表中位置 p 前一个元素的下标
int previous_seq(node* head, int p) {
    node* temp = head;
    for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return -1;  // 前驱不存在
    return p - 1;
}

// 检查链表是否为空
bool isNullList_seq(node* head) {
    return head == nullptr ? true : false;
}

// 输出链表
void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {//飞空遍历
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;  // 创建一个空链表
    createNullList_seq(head);

    insert_seq(head, 10, 0);
    insert_seq(head, 20, 1);
    insert_seq(head, 30, 2);

    printList(head); // 输出链表内容

    delete_seq(head, 1);
    printList(head); // 输出链表内容

    int pos = locate_seq(head, 20); // 查找值为 20 的元素的位置
    cout << "值为 20 的元素的位置: " << pos << endl; // 输出查找结果

    int value = retrieve_seq(head, 1); // 获取位置 1 的元素值
    cout << "位置 1 的元素值: " << value << endl; // 输出位置 1 的元素值

    pos = next_seq(head, 0); // 获取位置 0 的后继元素的位置
    cout << "位置 0 的后继元素的位置: " << pos << endl; // 输出后继元素位置

    pos = previous_seq(head, 2); // 获取位置 2 的前驱元素的位置
    cout << "位置 2 的前驱元素的位置: " << pos << endl; // 输出前驱元素位置

    cout << "链表是否为空? " << isNullList_seq(head) << endl; // 输出链表是否为空的判断结果

    return 0;
}