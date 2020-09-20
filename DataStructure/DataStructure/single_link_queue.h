/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-05
 > Desc:	单链队列
 ************************************************************************/

#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等


typedef struct SingleLinkQueueNode
{
	ElemType data;
	struct SingleLinkQueueNode* next;
}SingleLinkQueueNode,*PSingleLinkQueueNode;


typedef struct SingleLinkQueue
{
	PSingleLinkQueueNode front;	//队头指针
	PSingleLinkQueueNode rear;	//队尾指针
}SingleLinkQueue, * PSingleLinkQueue;


Status InitSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status DestroySingleLinkQueue(PSingleLinkQueue pSLQueue);
Status ClearSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status EmptySingleLinkQueue(PSingleLinkQueue pSLQueue);
int LengthSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status EnterSingleLinkQueue(PSingleLinkQueue pSLQueue,ElemType elemvalue);
Status DeleteSingleLinkQueue(PSingleLinkQueue pSLQueue,ElemType* pElemValue);
Status GetFrontSingleLinkQueue(PSingleLinkQueue pSLQueue, ElemType* pElemValue);