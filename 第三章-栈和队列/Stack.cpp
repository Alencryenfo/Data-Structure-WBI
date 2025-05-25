#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElemType; 	/* 定义栈元素的数据类型，
这里定义为整型 */
#define MAXNUM  100  	/* 栈中能达到的最大容量，
这里设为100 */
typedef struct  SeqStack	/* 顺序栈类型定义 */
{
    ElemType  	s[MAXNUM];
    int  		top; /* 栈顶指针 */
}SeqStack, *PSeqStack;
PSeqStack  createEmptyStack_seq( void )
{
    PSeqStack pastack;

    pastack = (PSeqStack)malloc(sizeof(SeqStack));
    if (pastack==NULL)
        printf("Out space!! \n");
    else
        pastack->top=-1;
    return  pastack;
}

int  isEmptyStack_seq ( PSeqStack pastack )
{
    return ( pastack->top == -1 );
}
void  push_seq ( PSeqStack pastack, ElemType x )
/* 在栈中压入一元素x */
{
    if ( pastack->top >= MAXNUM - 1  )
        printf( "overflow! \n" );
    else
    {
        pastack->top = pastack->top + 1;
        pastack->s[pastack->top] = x;
    }
}
ElemType  pop_seq( PSeqStack pastack )
/* 删除栈顶元素 */
{
    if ( isEmptyStack_seq( pastack ) )
    {
        printf( "Underflow!\n" );
        return (ElemType)0; /* 栈为空时返回默认值 */
    }
    else
    {
        ElemType temp = pastack->s[pastack->top];
        pastack->top = pastack->top - 1;
    return temp;
}
}
ElemType top_seq( PSeqStack pastack )
/* 当pastack所指的栈不为空栈时，求栈顶元素的值 */
{
    if (isEmptyStack_seq(pastack))
    {
        printf("Error: Empty Stack!\n");
        return (ElemType)0; /* 栈为空时返回默认值 */
    }
    else
    {
        return pastack->s[pastack->top];
}
}
