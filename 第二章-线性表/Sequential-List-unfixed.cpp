#include <iostream>
#include <cassert>
#include <cstdlib>  // 包含malloc, realloc等函数的声明
using namespace std;
#define InitSize 100
#define FALSE 0
#define TRUE 1
#define SPECIAL ((1<<31)-1)

typedef int DataType; // 保留一种类型定义即可
typedef DataType ElemType; // 定义元素类型为DataType

typedef struct SeqList {
    DataType *elem; /* 存储元素连续空间的地址*/
    int length; /* 表中元素的个数*/
    int size; /* 表的大小 */
} SeqList, *PSeqList; //合并写法

void InitList(PSeqList pList) {
    pList->elem = (ElemType *) malloc(InitSize * sizeof(ElemType));
    assert(pList->elem != NULL);

    pList->size = InitSize;
    pList->length = 0;
}

int InsertElem(PSeqList pList, int i, ElemType elem) {
    int j;
    ElemType *newList;
    if (i < 0 || i > pList->length) {
        cout << "插入位置非法，拒绝插入" << endl;
        return FALSE;
    }
    if (pList->length + 1 > pList->size) {
        // 定义增量大小
        int Increment = InitSize / 2;
        newList = (ElemType *) realloc(pList->elem,
                                       (pList->size + Increment) * sizeof(ElemType));
        assert(newList != NULL);
        pList->elem = newList;
        pList->size += Increment;
    }

    // 从后往前移动元素，为新元素腾出位置
    for (j = pList->length; j > i; j--) {
        pList->elem[j] = pList->elem[j - 1];
    }

    // 在位置i插入新元素
    pList->elem[i] = elem;
    pList->length++;

    return TRUE;
}

int DeleteElem(PSeqList pList, int i) {
    int j;
    if (i < 0 || i >= pList->length) {
        cout << "删除位置非法，拒绝删除" << endl;
        return FALSE;
    }
    for (j = i; j < pList->length - 1; j++)
        pList->elem[j] = pList->elem[j + 1];
    --pList->length;
    return TRUE;
}
