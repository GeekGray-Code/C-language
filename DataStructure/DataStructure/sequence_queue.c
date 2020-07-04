/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	˳�����
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sequence_queue.h"


 /**/
SequenceQueue* SequenceQueueInit(int queuesize)
{
	PSequenceQueue pSqQueue = NULL;

	pSqQueue = (PSequenceQueue)malloc(sizeof(SequenceQueue));
	if (pSqQueue == NULL)
	{
		printf("�ڴ�ռ��������\n");

		return NULL;
	}

	pSqQueue->pData = (ElemType*)malloc(sizeof(ElemType) * queuesize);
	if (pSqQueue->pData == NULL)
	{
		free(pSqQueue);
		return NULL;
	}

	pSqQueue->queuesize = queuesize;
	pSqQueue->head = 0;
	pSqQueue->tail = 0;
	pSqQueue->length = 0;

	return pSqQueue;
}



/**/
Status  SequenceQueueDelete(PSequenceQueue pSqQueue)
{
	if (pSqQueue == NULL)
	{
		printf("������������\n");
		return ERROR;
	}

	if (pSqQueue->pData != NULL)
	{
		free(pSqQueue->pData);
	}

	free(pSqQueue);

	return OK;
}