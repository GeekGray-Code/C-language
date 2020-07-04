/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	顺序队列
 ************************************************************************/

#pragma once

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等

typedef struct SequenceQueue
{
	int queuesize;  //队列的大小
	int length;     //队列长度
	int head;       //队列的头
	int tail;       //队列的尾
	ElemType* pData;//数据存储区
}SequenceQueue,*PSequenceQueue;

#define sequence_queue_is_empty(SequenceQueue) (SequenceQueue->length == 0)
#define sequence_queue_is_full(SequenceQueue)  ((SequenceQueue->length) == (SequenceQueue->queuesize))


SequenceQueue* SequenceQueueInit(int queuesize);