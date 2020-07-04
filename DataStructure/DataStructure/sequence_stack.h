/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	顺序栈
 ************************************************************************/

#pragma once



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 50	//顺序栈存储空间初始分配量
#define STACK_INCREMENT 10	//顺序栈存储空间分配增量

typedef int ElemType;	//
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等


/**********************************************基于动态数组实现的顺序栈****************************************/

typedef struct SequenceStack
{
	ElemType* pBase;	//栈底指针
	ElemType* pTop;		//栈顶指针
	int stacksize;		//栈当前可使用的最大容量
}SequenceStack,*PSequenceStack;

/*Operation*/
void SequenceStackTest();
Status InitStack(PSequenceStack pSqStack);	                    //初始化一个空栈
Status StackEmpty(PSequenceStack pSqStack);
Status DestroyStack(PSequenceStack pSqStack);	                //销毁栈
Status ClearStack(PSequenceStack pSqStack);	                    //置空栈
Status StackEmpty(PSequenceStack pSqStack);	                    //判断空栈
int StackLength(PSequenceStack pSqStack);	                    //栈的长度
Status GetTop(PSequenceStack pSqStack,ElemType* pElemValue);	//栈顶元素
Status SequenceStackPush(PSequenceStack pSqStack, ElemType elemvalue);	    //插入elemvalue元素为栈顶元素
Status SequenceStackPop(PSequenceStack pSqStack, ElemType* pElemValue);	    //删除栈顶元素，用pElemValue返回

/**********************************************基于动态数组实现的顺序栈****************************************/
