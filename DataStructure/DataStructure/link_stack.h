/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	链式栈
 ************************************************************************/

#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;	//
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等



typedef struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode,*PStackNode;


typedef struct LinkStack
{
	PStackNode pTop;
	int count;
}LinkStack,*PLinkStack;


LinkStack* LinkStackCreate(PLinkStack pLStack);
Status LinkStackPush(PLinkStack pLStack, ElemType elemvalue);
Status LinkStackPop(PLinkStack pLStack, ElemType* elemvalue);
Status LinkStackDestroy(PLinkStack pLStack);