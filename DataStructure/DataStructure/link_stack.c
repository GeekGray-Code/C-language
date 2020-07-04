/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	链式栈
 ************************************************************************/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"link_stack.h"



/**/
LinkStack* LinkStackCreate()
{
	PLinkStack pLStack = NULL;

	pLStack = (PLinkStack)malloc(sizeof(LinkStack));

	if (pLStack == NULL)
	{
		return ERROR;
	}

	pLStack->pTop->next = NULL;
	 
	return pLStack;
}


/*插入新元素elemvalue为新的栈顶元素*/
Status LinkStackPush(PLinkStack pLStack,ElemType elemvalue)
{
	PStackNode pNewNode = (PStackNode)malloc(sizeof(StackNode));

	pNewNode->data = elemvalue;
	pNewNode->next = pLStack->pTop;	//把当前栈顶元素赋值给新结点的直接后继

	pLStack->pTop = pNewNode;	//将新结点赋值给栈顶指针
	pLStack->count++;

	return OK;
}



/*若栈不为空，删除栈pLStack的栈顶元素，并用elemvalue返回*/
Status LinkStackPop(PLinkStack pLStack, ElemType* elemvalue)
{
	if (pLStack->pTop==NULL)
	{
		printf("栈空！\n");
		return ERROR;
	}

	PStackNode pTempNode;

	*elemvalue = pLStack->pTop->data;
	pTempNode = pLStack->pTop;	//将栈顶结点赋值给pTempNode
	pLStack->pTop = pLStack->pTop->next;	//使栈顶指针向后移一位，指向下一位

	free(pTempNode);

	pLStack->count--;

	return OK;
}



/**/
Status LinkStackDestroy(PLinkStack pLStack)
{
	if (pLStack->pTop == NULL)
	{
		printf("栈空！\n");
		return ERROR;
	}

	PStackNode pTempNode;

	while (!pLStack->pTop)
	{
		pTempNode = pLStack->pTop;
		pLStack->pTop = pLStack->pTop->next;

		free(pTempNode);
		pLStack->count--;

	}

	free(pLStack);

	return OK;
}