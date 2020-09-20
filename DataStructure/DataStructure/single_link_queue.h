/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-05
 > Desc:	��������
 ************************************************************************/

#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef int Status;	    //���������ͣ���ֵ�Ǻ������״̬���룬��OK��


typedef struct SingleLinkQueueNode
{
	ElemType data;
	struct SingleLinkQueueNode* next;
}SingleLinkQueueNode,*PSingleLinkQueueNode;


typedef struct SingleLinkQueue
{
	PSingleLinkQueueNode front;	//��ͷָ��
	PSingleLinkQueueNode rear;	//��βָ��
}SingleLinkQueue, * PSingleLinkQueue;


Status InitSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status DestroySingleLinkQueue(PSingleLinkQueue pSLQueue);
Status ClearSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status EmptySingleLinkQueue(PSingleLinkQueue pSLQueue);
int LengthSingleLinkQueue(PSingleLinkQueue pSLQueue);
Status EnterSingleLinkQueue(PSingleLinkQueue pSLQueue,ElemType elemvalue);
Status DeleteSingleLinkQueue(PSingleLinkQueue pSLQueue,ElemType* pElemValue);
Status GetFrontSingleLinkQueue(PSingleLinkQueue pSLQueue, ElemType* pElemValue);