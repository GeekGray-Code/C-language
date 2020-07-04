/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	��ʽջ
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


/*������Ԫ��elemvalueΪ�µ�ջ��Ԫ��*/
Status LinkStackPush(PLinkStack pLStack,ElemType elemvalue)
{
	PStackNode pNewNode = (PStackNode)malloc(sizeof(StackNode));

	pNewNode->data = elemvalue;
	pNewNode->next = pLStack->pTop;	//�ѵ�ǰջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��

	pLStack->pTop = pNewNode;	//���½�㸳ֵ��ջ��ָ��
	pLStack->count++;

	return OK;
}



/*��ջ��Ϊ�գ�ɾ��ջpLStack��ջ��Ԫ�أ�����elemvalue����*/
Status LinkStackPop(PLinkStack pLStack, ElemType* elemvalue)
{
	if (pLStack->pTop==NULL)
	{
		printf("ջ�գ�\n");
		return ERROR;
	}

	PStackNode pTempNode;

	*elemvalue = pLStack->pTop->data;
	pTempNode = pLStack->pTop;	//��ջ����㸳ֵ��pTempNode
	pLStack->pTop = pLStack->pTop->next;	//ʹջ��ָ�������һλ��ָ����һλ

	free(pTempNode);

	pLStack->count--;

	return OK;
}



/**/
Status LinkStackDestroy(PLinkStack pLStack)
{
	if (pLStack->pTop == NULL)
	{
		printf("ջ�գ�\n");
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