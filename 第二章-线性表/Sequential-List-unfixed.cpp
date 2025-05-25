#include <iostream>
#include <cassert>
using namespace std;
#define InitSize 100
#define FALSE 0
#define TRUE 1
#define SPECIAL (2>>31-1)

typedef int DataType;
typedef int ElemType;
typedef struct SeqList
{
    DataType *elem; /* 存储元素连续空间的地址*/
    int  length;	/* 表中元素的个数*/
    int  size;	/* 表的大小 */
}SeqList, *PSeqList;//合并写法

void InitList(PSeqList pList)
{
    pList->elem = (ElemType *)malloc(InitSize*sizeof(ElemType));
    assert(pList->elem != NULL);

    pList->size  = InitSize;
    pList->length= 0;
}
int InsertElem(PSeqList pList, int i, ElemType elem) {
    int		j, pos;
    ElemType   *newList;
    if(i < 0 || i > pList->length) {
        printf("Insert position error!\n");
        return FALSE;
    }
    if (pList->length + 1 > pList->size) {
        newList = (DataType *)realloc(pList->elem,
            (pList->size+Increment)*sizeof(DataType));
        assert(newList != NULL);
        pList->element = newList;
        pList->size+= Increment;
    }
}