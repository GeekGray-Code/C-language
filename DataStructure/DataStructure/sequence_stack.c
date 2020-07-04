/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	顺序栈
 ************************************************************************/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_stack.h"



/**********************************************基于动态数组实现的顺序栈****************************************/
/*动态数组实现的顺序栈测试函数*/
void SequenceStackTest()
{
	SequenceStack sqStack;
	PSequenceStack pSqStack = &sqStack;

	InitStack(pSqStack);
}


/*初始化栈，构造一个空栈pSqStack*/
Status InitStack(PSequenceStack pSqStack)
{
	if (pSqStack==NULL)
	{
		printf("参数传递有误！\n");
		return ERROR;
	}

	pSqStack->pBase = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);

	if (pSqStack->pBase == NULL)	//分配内存空间失败
	{
		exit(EOVERFLOW);
	}

	pSqStack->pTop = pSqStack->pBase;
	pSqStack->stacksize = STACK_INIT_SIZE;

	return OK;
}



/*判断栈空*/
Status StackEmpty(PSequenceStack pSqStack)
{
	if (pSqStack->pBase == pSqStack->pTop)	//空栈
	{
		printf("空栈！\n");
		return ERROR;
	}
}



/*获取栈顶元素*/
Status GetTop(PSequenceStack pSqStack, ElemType* pElemValue)
{
	if (pSqStack == NULL)
	{
		printf("参数传递有误！\n");
		return ERROR;
	}

	if (pSqStack->pBase == pSqStack->pTop)	//空栈
	{
		printf("空栈！\n");
		return ERROR;
	}

	*pElemValue = *(pSqStack->pTop - 1);	//若栈不为空，用pElemValue返回栈顶元素

	return OK;
}



/*插入elemvalue元素为栈顶元素*/
Status SequenceStackPush(PSequenceStack pSqStack, ElemType elemvalue)
{
	if (pSqStack == NULL)
	{
		printf("参数传递有误！\n");
		return ERROR;
	}

	if (pSqStack->pTop - pSqStack->pBase >= pSqStack->stacksize)	//栈满，扩容
	{
		pSqStack->pBase = (ElemType*)realloc(pSqStack->pBase,(pSqStack->stacksize + STACK_INCREMENT) * sizeof(ElemType));

		if (pSqStack == NULL)
		{
			exit(EOVERFLOW);
		}

		pSqStack->pTop = pSqStack->pBase + pSqStack->stacksize;	//重新确定栈顶指针的位置
		pSqStack->stacksize += STACK_INCREMENT;	//确定当前栈可用空间大小
	}

	*(pSqStack->pTop++) = elemvalue;	//插入栈顶元素，栈顶指针加1

	return OK;
}



/*删除栈顶元素，用pElemValue返回*/
Status SequenceStackPop(PSequenceStack pSqStack, ElemType* pElemValue)
{
	StackEmpty(pSqStack);

	*pElemValue = *(--pSqStack->pTop);

	return OK;
}

/**********************************************基于动态数组实现的顺序栈****************************************/
