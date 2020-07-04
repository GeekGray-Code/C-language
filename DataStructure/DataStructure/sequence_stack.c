/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	˳��ջ
 ************************************************************************/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_stack.h"



/**********************************************���ڶ�̬����ʵ�ֵ�˳��ջ****************************************/
/*��̬����ʵ�ֵ�˳��ջ���Ժ���*/
void SequenceStackTest()
{
	SequenceStack sqStack;
	PSequenceStack pSqStack = &sqStack;

	InitStack(pSqStack);
}


/*��ʼ��ջ������һ����ջpSqStack*/
Status InitStack(PSequenceStack pSqStack)
{
	if (pSqStack==NULL)
	{
		printf("������������\n");
		return ERROR;
	}

	pSqStack->pBase = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);

	if (pSqStack->pBase == NULL)	//�����ڴ�ռ�ʧ��
	{
		exit(EOVERFLOW);
	}

	pSqStack->pTop = pSqStack->pBase;
	pSqStack->stacksize = STACK_INIT_SIZE;

	return OK;
}



/*�ж�ջ��*/
Status StackEmpty(PSequenceStack pSqStack)
{
	if (pSqStack->pBase == pSqStack->pTop)	//��ջ
	{
		printf("��ջ��\n");
		return ERROR;
	}
}



/*��ȡջ��Ԫ��*/
Status GetTop(PSequenceStack pSqStack, ElemType* pElemValue)
{
	if (pSqStack == NULL)
	{
		printf("������������\n");
		return ERROR;
	}

	if (pSqStack->pBase == pSqStack->pTop)	//��ջ
	{
		printf("��ջ��\n");
		return ERROR;
	}

	*pElemValue = *(pSqStack->pTop - 1);	//��ջ��Ϊ�գ���pElemValue����ջ��Ԫ��

	return OK;
}



/*����elemvalueԪ��Ϊջ��Ԫ��*/
Status SequenceStackPush(PSequenceStack pSqStack, ElemType elemvalue)
{
	if (pSqStack == NULL)
	{
		printf("������������\n");
		return ERROR;
	}

	if (pSqStack->pTop - pSqStack->pBase >= pSqStack->stacksize)	//ջ��������
	{
		pSqStack->pBase = (ElemType*)realloc(pSqStack->pBase,(pSqStack->stacksize + STACK_INCREMENT) * sizeof(ElemType));

		if (pSqStack == NULL)
		{
			exit(EOVERFLOW);
		}

		pSqStack->pTop = pSqStack->pBase + pSqStack->stacksize;	//����ȷ��ջ��ָ���λ��
		pSqStack->stacksize += STACK_INCREMENT;	//ȷ����ǰջ���ÿռ��С
	}

	*(pSqStack->pTop++) = elemvalue;	//����ջ��Ԫ�أ�ջ��ָ���1

	return OK;
}



/*ɾ��ջ��Ԫ�أ���pElemValue����*/
Status SequenceStackPop(PSequenceStack pSqStack, ElemType* pElemValue)
{
	StackEmpty(pSqStack);

	*pElemValue = *(--pSqStack->pTop);

	return OK;
}

/**********************************************���ڶ�̬����ʵ�ֵ�˳��ջ****************************************/
