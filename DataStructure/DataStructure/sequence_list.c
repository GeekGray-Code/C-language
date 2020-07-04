/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	���Ա��˳��洢
 ************************************************************************/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_list.h"


/*˳�����Ժ���*/
void SequenceListTest()
{
	StaticListTest();	//��̬����˳�����Ժ���

	DynamicListTest();	//��̬����˳�����Ժ���
}



/*******************************************��̬�����ʾ˳���*******************************************/

/*��̬����˳�����Ժ���*/
void StaticListTest()
{

}


/*�����Ա�L�еĵ�i��λ�õ�Ԫ��ֵ����*/
Status GetElem(StaticList stList, int i, ElemType e)
{
	if (stList.length == 0 || i<1 || i>stList.length)
	{
		return ERROR;
	}

	e = stList.data[i - 1];

	return OK;
}


/*��L�е�i��Ԫ��ǰ�����µ�����e��L�ĳ�������1
  �������λ�ò������׳��쳣
  ������Ա�������ڵ������鳤�ȣ����׳��쳣��̬��������
  �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��
  ��Ҫ�����Ԫ�ز��뵽λ��i��
  ����1
*/
Status ListInsert(StaticList* pStList, int i, ElemType e)
{


	if (pStList->length == LIST_INIT_SIZE)	//���Ա�����
	{
		return ERROR;
	}

	if (i<1 || i>pStList->length)	//������ֵi���ڷ�Χ��ʱ
	{
		return ERROR;
	}

	if (i <= pStList->length)	//�����������λ�ò��ڱ�β
	{
		for (int k = pStList->length; k >= i - 1; k--)	//�������λ�ú������Ԫ������ƶ�һλ
		{
			pStList->data[k + 1] = pStList->data[k];
		}
	}

	pStList->data[i - 1] = e;	//���ڱ�β������Ԫ�ز���
	pStList->length++;	    //���Ա�ǰ���ȼ�1

	return OK;
}


/*ɾ�����Ա�L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
Status ListDelete(PStaticList pStList, int i, ElemType e)
{
	if (pStList->length == 0)	//���Ա�Ϊ��
	{
		return ERROR;
	}

	if (i<1 || i>pStList->length)	//������ֵi���ڷ�Χ��ʱ
	{
		return ERROR;
	}

	e = pStList->data[i - 1];	//	ȡ����Ԫ��

	if (i < pStList->length)	//���ɾ��λ�ò���λ�ڱ�β
	{
		for (int k = i; k < pStList->length; k++)	//��ɾ��λ�����к���Ԫ����ǰ��
		{
			pStList->data[k - 1] = pStList->data[k];
		}
	}

	pStList->length--;

	return OK;
}
/*******************************************��̬�����ʾ˳���*******************************************/



/*******************************************��̬�����ʾ˳���*******************************************/
/*��̬����˳�����Ժ���*/
void DynamicListTest()
{
	DynamicList dyList;
	PDynamicList pDyList = &dyList;

	/*��ʼ��*/
	InitList(pDyList);

	/*���Ԫ��*/
	addElems(pDyList, 1);
	addElems(pDyList, 2);
	addElems(pDyList, 3);
	addElems(pDyList, 4);
	addElems(pDyList, 5);
	addElems(pDyList, 6);

	/*�м����*/
	MidInsert(pDyList, 10, 5);
	MidInsert(pDyList, 10, 10);

	/*��ӡ����*/
	printf("ɾ��Ԫ��ǰ�����飺\n");
	printList(pDyList);


	/*ɾ��*/
	MidDelete(pDyList,6);
	//TailDeleteElem(pDyList);
	//FreeDynamicArray(pDyList);

	/*��ӡ����*/
	printf("\n\nɾ��Ԫ�غ�����飺\n");
	printList(pDyList);



	free(pDyList->pListHead);
}



/*��ʼ��˳���*/
void InitList(DynamicList* pDyList)
{
	pDyList->pListHead = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	pDyList->listsize = LIST_INIT_SIZE;
	pDyList->listlength = 0;
}



/*��Ӻ���*/
void addElems(PDynamicList pDyList, ElemType elemValue)
{
	/*�ж������Ƿ�����,����������*/
	ExpandSize(pDyList);

	/*����δ�������пռ�*/
	pDyList->pListHead[pDyList->listlength] = elemValue;//��ԭ�����鳤��β��װ����
	pDyList->listlength++;                               //���鳤�ȼ�1
}


/*��ӡ���˳���*/
void printList(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	printf("����������size����%u,���鳤�ȣ�len����%u\n", pDyList->listsize, pDyList->listlength);
	printf("��ǰ����Ԫ��������ʾ:\n");
	for (unsigned int i = 0; i < pDyList->listlength; i++)
	{
		printf("%d,", pDyList->pListHead[i]);
	}
}


/*
�м����
����3��������±�λ��
*/
void MidInsert(PDynamicList pDyList, ElemType elemValue, unsigned int position)
{
	/*�ж�˳����Ƿ�����,����������*/
	ExpandSize(pDyList);

	/*���ݵ��±����*/
	if (position > pDyList->listlength)
	{
		position = pDyList->listlength;
	}

	/*��Ԫ�������ƶ�*/
	for (unsigned int i = pDyList->listlength; i > position; i--)
	{
		pDyList->pListHead[i] = pDyList->pListHead[i - 1];
	}

	pDyList->pListHead[position] = elemValue;//���ݸ�ֵ
	pDyList->listlength++;                   //���ȼ�1
}


/*˳�������*/
void ExpandSize(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	/*�ж������Ƿ�����*/
	if (pDyList->listlength == pDyList->listsize)
	{
		pDyList->listsize += 10;                                   //�������
		int* pTemp = (int*)malloc(sizeof(int) * pDyList->listsize);//����ռ�
		memset(pTemp, 0, sizeof(int) * pDyList->listsize);

		/*��ԭ���鸴�ƽ��¿ռ�*/
		for (unsigned int i = 0; i < pDyList->listlength; i++)
		{
			pTemp[i] = pDyList->pListHead[i];
		}

		free(pDyList->pListHead);  //�ͷ�ԭ�ռ�
		pDyList->pListHead = pTemp;//������ͷָ���¿ռ�
	}
}


/*ɾ���м�*/
void MidDelete(PDynamicList pDyList, unsigned int position)
{
	if (pDyList == NULL || position>pDyList->listlength)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	/*���ݴӺ���ǰ�ƶ�*/
	for (unsigned i = position-1; i < pDyList->listlength-1; i++)
	{
		pDyList->pListHead[i] = pDyList->pListHead[i + 1];
	}

	pDyList->listlength--;
}



/*βɾ��*/
void TailDeleteElem(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	pDyList->listlength--;//��ɾ����ֻ��û���������һ��Ԫ�أ�
}


/*ɾ��ȫ��*/
void DeleteComplete(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	pDyList->listlength=0;	
	pDyList->listsize = 0;

	free(pDyList->pListHead);
	pDyList->pListHead = NULL;
}


/*�ͷŶ�̬˳���*/
void FreeDynamicList(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n���ݲ�������!\n");
		return;
	}

	pDyList->listlength = 0;
	pDyList->listsize = 0;

	free(pDyList->pListHead);
	pDyList->pListHead = NULL;
}






/*******************************************��̬�����ʾ˳���*******************************************/
