#include <iostream>
using namespace std;
#define MAXNUM 100
#define FALSE 0
#define TRUE 1
#define SPECIAL (2>>31-1)
typedef int DataType;

struct SeqList {
    //结构体声明
    DataType element[MAXNUM];
    int length;
};

typedef SeqList SeqList, *PSeqList; //变量别名声明

int insert_seq(PSeqList palist, DataType x, int p) {
    if (palist->length == MAXNUM) // 溢出
    {
        printf("插入元素后将会超过最大长度，拒绝插入\n");
        return FALSE;
    }
    if (p < 0 || p > palist->length) // 不存在下标为 p 的元素
    {
        printf("未寻找到需要插入的位置，拒绝插入\n");
        return FALSE;
    }
    for (int q = palist->length - 1; q >= p; q--) //人类可见的从 1 开始编号，但实际上存储从 0 开始
        palist->element[q + 1] = palist->element[q]; //从最后一个元素开始，向后移动一位
    palist->element[p] = x; // 在p下标位置上放元素 x
    palist->length = palist->length + 1; // 元素个数加１
    return TRUE;
}

// 在palist所指顺序表中删除下标为p的元素
int delete_seq(PSeqList palist, int p)
{
    int q;
    if (p < 0 || p > palist->length - 1) // 不存在下标为p的元素
    {
        printf("未寻找到需要删除的位置，拒绝删除\n ");
        return FALSE;
    }
    //将p以后的元素前移一个位置
    for (q = p; q < palist->length - 1; q++)
        palist->element[q] = palist->element[q + 1];
    palist->length = palist->length - 1; // 元素个数减1
    return TRUE;
}

int first_seq(PSeqList palist) {
    //返回第一个元素下标、判断空与否
    if (palist->length == 0)return -1;
    else return 0;
}

int locate_seq(PSeqList palist, DataType x) {
    //遍历查找某一个元素，时间复杂度为O(n)
    for (int q = 0; q < palist->length; q++)
        if (palist->element[q] == x)
            return q;
    return -1;
}

//求palist所指顺序表中第p个（即下标为p-1）的元素的值
DataType retrieve_seq(PSeqList palist, int p)
{
    // 存在下标为p-1的元素
    if (p > 0 && p <= palist->length)
        return (palist->element[p - 1]);
    printf("不存在这个下标为 %d 的元素\n", p);
    return -1;
}
