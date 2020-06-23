#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_list.h"


/*˳�����Ժ���*/
void SequenceListTest()
{
	DynamicArrayTest();
}


/*�����Ա�L�еĵ�i��λ�õ�Ԫ��ֵ����*/
Status GetElem(SqList L, int i, ElemType e)
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}

	e = L.data[i - 1];

	return OK;
}


/*��L�е�i��Ԫ��ǰ�����µ�����e��L�ĳ�������1
  �������λ�ò������׳��쳣
  ������Ա�������ڵ������鳤�ȣ����׳��쳣��̬��������
  �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��
  ��Ҫ�����Ԫ�ز��뵽λ��i��
  ����1
*/
Status ListInsert(SqList* L, int i, ElemType e)
{


	if (L->length == MAXSIZE)	//���Ա�����
	{
		return ERROR;
	}

	if (i<1 || i>L->length)	//������ֵi���ڷ�Χ��ʱ
	{
		return ERROR;
	}

	if (i <= L->length)	//�����������λ�ò��ڱ�β
	{
		for (int k = L->length; k >= i - 1; k--)	//�������λ�ú������Ԫ������ƶ�һλ
		{
			L->data[k + 1] = L->data[k];
		}
	}

	L->data[i - 1] = e;	//���ڱ�β������Ԫ�ز���
	L->length++;	    //���Ա�ǰ���ȼ�1

	return OK;
}


/*ɾ�����Ա�L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
Status ListDelete(PSqList L, int i, ElemType e)
{
	if (L->length == 0)	//���Ա�Ϊ��
	{
		return ERROR;
	}

	if (i<1 || i>L->length)	//������ֵi���ڷ�Χ��ʱ
	{
		return ERROR;
	}

	e = L->data[i - 1];	//	ȡ����Ԫ��

	if (i < L->length)	//���ɾ��λ�ò���λ�ڱ�β
	{
		for (int k = i; k < L->length; k++)	//��ɾ��λ�����к���Ԫ����ǰ��
		{
			L->data[k - 1] = L->data[k];
		}
	}

	L->length--;

	return OK;
}



/*********************************************��̬����****************************************************/

/*��̬������Ժ���*/
void DynamicArrayTest()
{
	DynamicArray dicArr;
	PDynamicArray pDicArr = &dicArr;

	/*��ʼ��*/
	InitArray(pDicArr);

	/*���Ԫ��*/
	addElems(pDicArr, 1);
	addElems(pDicArr, 2);
	addElems(pDicArr, 3);
	addElems(pDicArr, 4);
	addElems(pDicArr, 5);
	addElems(pDicArr, 6);

	/*�м����*/
	MidInsert(pDicArr, 10, 5);
	MidInsert(pDicArr, 10, 10);

	/*��ӡ����*/
	printArray(pDicArr);



	free(dicArr.pArrayHead);
}



/*��ʼ������*/
void InitArray(DynamicArray* pDicArr)
{
	pDicArr->arraysize = 5;
	pDicArr->pArrayHead = (int*)malloc(sizeof(int) * pDicArr->arraysize);
	pDicArr->arraylength = 0;
}



/*��Ӻ���*/
void addElems(PDynamicArray pDicArr, int elemValue)
{
	/*�ж������Ƿ�����,����������*/
	ExpandSize(pDicArr);

	/*����δ�������пռ�*/
	pDicArr->pArrayHead[pDicArr->arraylength] = elemValue;//��ԭ�����鳤��β��װ����
	pDicArr->arraylength++;                               //���鳤�ȼ�1
}


/*��ӡ�������*/
void printArray(PDynamicArray pDicArr)
{
	if (pDicArr == NULL)
	{
		printf("���ݲ�������!");
		return;
	}

	printf("����������size����%u,���鳤�ȣ�len����%u\n", pDicArr->arraysize, pDicArr->arraylength);
	printf("��ǰ����Ԫ��������ʾ:\n");
	for (unsigned int i = 0; i < pDicArr->arraylength; i++)
	{
		printf("%d,", pDicArr->pArrayHead[i]);
	}
}


/*
�м����
����3��������±�λ��
*/
void MidInsert(PDynamicArray pDicArr, int elemValue, unsigned int position)
{
	/*�ж������Ƿ�����,����������*/
	ExpandSize(pDicArr);

	/*���ݵ��±����*/
	if (position > pDicArr->arraylength)
	{
		position = pDicArr->arraylength;
	}

	/*����Ԫ�������ƶ�*/
	for (unsigned int i = pDicArr->arraylength; i > position; i--)
	{
		pDicArr->pArrayHead[i] = pDicArr->pArrayHead[i - 1];
	}

	pDicArr->pArrayHead[position] = elemValue;//���ݸ�ֵ
	pDicArr->arraylength++;                   //���ȼ�1
}


/*��������*/
void ExpandSize(PDynamicArray pDicArr)
{
	if (pDicArr == NULL)
	{
		printf("���ݲ�������!");
		return;
	}

	/*�ж������Ƿ�����*/
	if (pDicArr->arraylength == pDicArr->arraysize)
	{
		pDicArr->arraysize += 10;                                   //�������
		int* pTemp = (int*)malloc(sizeof(int) * pDicArr->arraysize);//����ռ�
		memset(pTemp, 0, sizeof(int) * pDicArr->arraysize);

		/*��ԭ���鸴�ƽ��¿ռ�*/
		for (unsigned int i = 0; i < pDicArr->arraylength; i++)
		{
			pTemp[i] = pDicArr->pArrayHead[i];
		}

		free(pDicArr->pArrayHead);  //�ͷ�ԭ�ռ�
		pDicArr->pArrayHead = pTemp;//������ͷָ���¿ռ�
	}
}


/*********************************************��̬����****************************************************/
