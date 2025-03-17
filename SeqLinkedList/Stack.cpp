#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int ElemType;
#define MAXNUM  100
typedef struct  SeqStack
{
	ElemType  	s[MAXNUM];
	int  		top; // 栈顶指针
}SeqStack, *PSeqStack;

PSeqStack  createEmptyStack_seq( void );
int  isEmptyStack_seq ( PSeqStack pastack );
void  push_seq ( PSeqStack pastack, ElemType x );
ElemType  pop_seq( PSeqStack pastack );
ElemType  stackTop_seq( PSeqStack pastack );
void destroyStack_seq( PSeqStack pastack );

PSeqStack  createEmptyStack_seq( void )
{
  	PSeqStack pastack;
      	pastack = (PSeqStack)malloc(sizeof(SeqStack));
	if (pastack==NULL)
		printf("空间不足 \n"); // 空间分配失败
	else
		pastack->top=-1; // 初始化栈顶指针
	 return  pastack;
   }

int  isEmptyStack_seq ( PSeqStack pastack )
{
	return ( pastack->top == -1 ); // 栈顶指针为 -1 时，栈为空
}

void  push_seq ( PSeqStack pastack, ElemType x )
/* 入栈操作 */
{
  	if ( pastack->top >= MAXNUM - 1  )
      		printf( "栈溢出 \n" ); // 栈满时，打印溢出信息
  	else
	{
	  	pastack->top++;
	  	pastack->s[pastack->top] = x;
	 }
}

ElemType  pop_seq( PSeqStack pastack )
/* 出栈操作，返回栈顶元素 */
{
 	ElemType	temp = -1; // 默认返回值，表示栈为空
	if ( isEmptyStack_seq( pastack ) )
		printf( "栈为\n" ); // 栈为空时，打印下溢信息
    	else
	{
		temp = pastack->s[pastack->top];
		pastack->top--;
	}
	return temp; // 返回栈顶元素，栈空时返回 -1
}

ElemType stackTop_seq( PSeqStack pastack )
/* 获取栈顶元素，但不删除 */
{
    ElemType temp = -1; // 默认返回值，表示栈为空
    if ( isEmptyStack_seq( pastack ) )
        printf("栈为空，无法获取栈顶元素!\n"); // 栈为空时，打印信息
    else
    {
        temp = pastack->s[pastack->top];
    }
    return temp; // 返回栈顶元素，栈空时返回 -1
}

void destroyStack_seq( PSeqStack pastack )
/* 销毁栈，释放内存 */
{
    if (pastack != NULL) {
        free(pastack); // 释放内存
        pastack = NULL;
    }
}

int main() {
    PSeqStack stack = createEmptyStack_seq(); // 创建栈
    if (stack == NULL) {
        return 1;
    }

    printf("栈是否为空? %d (1=是, 0=否)\n", isEmptyStack_seq(stack));

    push_seq(stack, 10);
    push_seq(stack, 20);
    push_seq(stack, 30);

    printf("栈是否为空? %d (1=是, 0=否)\n", isEmptyStack_seq(stack));

    printf("栈顶元素: %d\n", stackTop_seq(stack));

    printf("弹出元素: %d\n", pop_seq(stack));
    printf("弹出元素: %d\n", pop_seq(stack));
    printf("弹出元素: %d\n", pop_seq(stack));
    printf("弹出元素: %d\n", pop_seq(stack)); // 尝试从空栈弹出

    destroyStack_seq(stack);

    return 0;
}