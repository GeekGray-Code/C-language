#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_list.h"


/*顺序表测试函数*/
void SequenceListTest()
{
	DynamicArrayTest();
}


/*将线性表L中的第i个位置的元素值返回*/
Status GetElem(SqList L, int i, ElemType e)
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}

	e = L.data[i - 1];

	return OK;
}


/*在L中第i个元素前插入新的数据e，L的长度增加1
  如果插入位置不合理，抛出异常
  如果线性表产犊大于等于数组长度，则抛出异常或动态扩容数组
  从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置
  将要插入的元素插入到位置i处
  表长加1
*/
Status ListInsert(SqList* L, int i, ElemType e)
{


	if (L->length == MAXSIZE)	//线性表已满
	{
		return ERROR;
	}

	if (i<1 || i>L->length)	//当索引值i不在范围内时
	{
		return ERROR;
	}

	if (i <= L->length)	//若插入的数据位置不在表尾
	{
		for (int k = L->length; k >= i - 1; k--)	//将插入的位置后的数据元素向后移动一位
		{
			L->data[k + 1] = L->data[k];
		}
	}

	L->data[i - 1] = e;	//若在表尾，将新元素插入
	L->length++;	    //线性表当前长度加1

	return OK;
}


/*删除线性表L的第i个元素，并用e返回其值，L的长度减1*/
Status ListDelete(PSqList L, int i, ElemType e)
{
	if (L->length == 0)	//线性表为空
	{
		return ERROR;
	}

	if (i<1 || i>L->length)	//当索引值i不在范围内时
	{
		return ERROR;
	}

	e = L->data[i - 1];	//	取出该元素

	if (i < L->length)	//如果删除位置不是位于表尾
	{
		for (int k = i; k < L->length; k++)	//将删除位置所有后置元素往前移
		{
			L->data[k - 1] = L->data[k];
		}
	}

	L->length--;

	return OK;
}



/*********************************************动态数组****************************************************/

/*动态数组测试函数*/
void DynamicArrayTest()
{
	DynamicArray dicArr;
	PDynamicArray pDicArr = &dicArr;

	/*初始化*/
	InitArray(pDicArr);

	/*添加元素*/
	addElems(pDicArr, 1);
	addElems(pDicArr, 2);
	addElems(pDicArr, 3);
	addElems(pDicArr, 4);
	addElems(pDicArr, 5);
	addElems(pDicArr, 6);

	/*中间插入*/
	MidInsert(pDicArr, 10, 5);
	MidInsert(pDicArr, 10, 10);

	/*打印数组*/
	printArray(pDicArr);



	free(dicArr.pArrayHead);
}



/*初始化数组*/
void InitArray(DynamicArray* pDicArr)
{
	pDicArr->arraysize = 5;
	pDicArr->pArrayHead = (int*)malloc(sizeof(int) * pDicArr->arraysize);
	pDicArr->arraylength = 0;
}



/*添加函数*/
void addElems(PDynamicArray pDicArr, int elemValue)
{
	/*判断数组是否满容,若是则扩容*/
	ExpandSize(pDicArr);

	/*数组未满，仍有空间*/
	pDicArr->pArrayHead[pDicArr->arraylength] = elemValue;//往原来数组长度尾上装数据
	pDicArr->arraylength++;                               //数组长度加1
}


/*打印输出数组*/
void printArray(PDynamicArray pDicArr)
{
	if (pDicArr == NULL)
	{
		printf("传递参数有误!");
		return;
	}

	printf("数组容量（size）：%u,数组长度（len）：%u\n", pDicArr->arraysize, pDicArr->arraylength);
	printf("当前数组元素如下所示:\n");
	for (unsigned int i = 0; i < pDicArr->arraylength; i++)
	{
		printf("%d,", pDicArr->pArrayHead[i]);
	}
}


/*
中间插入
参数3：插入的下标位置
*/
void MidInsert(PDynamicArray pDicArr, int elemValue, unsigned int position)
{
	/*判断数组是否满容,若是则扩容*/
	ExpandSize(pDicArr);

	/*传递的下标过大*/
	if (position > pDicArr->arraylength)
	{
		position = pDicArr->arraylength;
	}

	/*数组元素往后移动*/
	for (unsigned int i = pDicArr->arraylength; i > position; i--)
	{
		pDicArr->pArrayHead[i] = pDicArr->pArrayHead[i - 1];
	}

	pDicArr->pArrayHead[position] = elemValue;//数据赋值
	pDicArr->arraylength++;                   //长度加1
}


/*数组扩容*/
void ExpandSize(PDynamicArray pDicArr)
{
	if (pDicArr == NULL)
	{
		printf("传递参数有误!");
		return;
	}

	/*判断数组是否满容*/
	if (pDicArr->arraylength == pDicArr->arraysize)
	{
		pDicArr->arraysize += 10;                                   //容量变大
		int* pTemp = (int*)malloc(sizeof(int) * pDicArr->arraysize);//申请空间
		memset(pTemp, 0, sizeof(int) * pDicArr->arraysize);

		/*将原数组复制进新空间*/
		for (unsigned int i = 0; i < pDicArr->arraylength; i++)
		{
			pTemp[i] = pDicArr->pArrayHead[i];
		}

		free(pDicArr->pArrayHead);  //释放原空间
		pDicArr->pArrayHead = pTemp;//将数组头指向新空间
	}
}


/*********************************************动态数组****************************************************/
