//
// Created by 26444 on 25-2-24.
//
#include <iostream>
using namespace std;

// 链表节点定义
// 每一节点存储一个小数点后的数字，这样可以无限延长至500位
struct node {
    int data; // 存储 0-9 的数字
    node *next;
};

// 打印链表表示的小数
// Debug
void printDecimalLinkedList(node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    node* temp = head;
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
}

// 链表加法 (decimal1 + decimal2)，返回新的链表
node* addDecimalLinkedList(node* decimal1, node* decimal2) {
    node* resultHead = nullptr;
    node* resultCurrent = nullptr;
    int carry = 0;

    // 反转链表，方便从低位到高位计算
    auto reverseList = [](node* head) {
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    };

    node* reversedDecimal1 = reverseList(decimal1);
    node* reversedDecimal2 = reverseList(decimal2);

    node* temp1 = reversedDecimal1;
    node* temp2 = reversedDecimal2;

    while (temp1 || temp2 || carry) {
        int sum = carry;
        if (temp1) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        node* newNode = new node(digit);
        if (!resultHead) {
            resultHead = newNode;
            resultCurrent = resultHead;
        } else {
            resultCurrent->next = newNode;
            resultCurrent = newNode;
        }
    }

    // 再次反转链表，恢复正序
    return reverseList(resultHead);
}