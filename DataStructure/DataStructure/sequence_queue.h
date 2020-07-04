/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	˳�����
 ************************************************************************/

#pragma once

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int ElemType;
typedef int Status;	    //���������ͣ���ֵ�Ǻ������״̬���룬��OK��

typedef struct SequenceQueue
{
	int queuesize;  //���еĴ�С
	int length;     //���г���
	int head;       //���е�ͷ
	int tail;       //���е�β
	ElemType* pData;//���ݴ洢��
}SequenceQueue,*PSequenceQueue;

#define sequence_queue_is_empty(SequenceQueue) (SequenceQueue->length == 0)
#define sequence_queue_is_full(SequenceQueue)  ((SequenceQueue->length) == (SequenceQueue->queuesize))


SequenceQueue* SequenceQueueInit(int queuesize);