/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	线性表的顺序存储
 ************************************************************************/

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"sequence_list.h"


/*顺序表测试函数*/
void SequenceListTest()
{
	StaticListTest();	//静态数组顺序表测试函数

	DynamicListTest();	//动态数组顺序表测试函数
}



/*******************************************静态数组表示顺序表*******************************************/

/*静态数组顺序表测试函数*/
void StaticListTest()
{

}


/*将线性表L中的第i个位置的元素值返回*/
Status GetElem(StaticList stList, int i, ElemType e)
{
	if (stList.length == 0 || i<1 || i>stList.length)
	{
		return ERROR;
	}

	e = stList.data[i - 1];

	return OK;
}


/*在L中第i个元素前插入新的数据e，L的长度增加1
  如果插入位置不合理，抛出异常
  如果线性表产犊大于等于数组长度，则抛出异常或动态扩容数组
  从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置
  将要插入的元素插入到位置i处
  表长加1
*/
Status ListInsert(StaticList* pStList, int i, ElemType e)
{


	if (pStList->length == LIST_INIT_SIZE)	//线性表已满
	{
		return ERROR;
	}

	if (i<1 || i>pStList->length)	//当索引值i不在范围内时
	{
		return ERROR;
	}

	if (i <= pStList->length)	//若插入的数据位置不在表尾
	{
		for (int k = pStList->length; k >= i - 1; k--)	//将插入的位置后的数据元素向后移动一位
		{
			pStList->data[k + 1] = pStList->data[k];
		}
	}

	pStList->data[i - 1] = e;	//若在表尾，将新元素插入
	pStList->length++;	    //线性表当前长度加1

	return OK;
}


/*删除线性表L的第i个元素，并用e返回其值，L的长度减1*/
Status ListDelete(PStaticList pStList, int i, ElemType e)
{
	if (pStList->length == 0)	//线性表为空
	{
		return ERROR;
	}

	if (i<1 || i>pStList->length)	//当索引值i不在范围内时
	{
		return ERROR;
	}

	e = pStList->data[i - 1];	//	取出该元素

	if (i < pStList->length)	//如果删除位置不是位于表尾
	{
		for (int k = i; k < pStList->length; k++)	//将删除位置所有后置元素往前移
		{
			pStList->data[k - 1] = pStList->data[k];
		}
	}

	pStList->length--;

	return OK;
}
/*******************************************静态数组表示顺序表*******************************************/



/*******************************************动态数组表示顺序表*******************************************/
/*动态数组顺序表测试函数*/
void DynamicListTest()
{
	DynamicList dyList;
	PDynamicList pDyList = &dyList;

	/*初始化*/
	InitList(pDyList);

	/*添加元素*/
	addElems(pDyList, 1);
	addElems(pDyList, 2);
	addElems(pDyList, 3);
	addElems(pDyList, 4);
	addElems(pDyList, 5);
	addElems(pDyList, 6);

	/*中间插入*/
	MidInsert(pDyList, 10, 5);
	MidInsert(pDyList, 10, 10);

	/*打印数组*/
	printf("删除元素前的数组：\n");
	printList(pDyList);


	/*删除*/
	MidDelete(pDyList,6);
	//TailDeleteElem(pDyList);
	//FreeDynamicArray(pDyList);

	/*打印数组*/
	printf("\n\n删除元素后的数组：\n");
	printList(pDyList);



	free(pDyList->pListHead);
}



/*初始化顺序表*/
void InitList(DynamicList* pDyList)
{
	pDyList->pListHead = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	pDyList->listsize = LIST_INIT_SIZE;
	pDyList->listlength = 0;
}



/*添加函数*/
void addElems(PDynamicList pDyList, ElemType elemValue)
{
	/*判断数组是否满容,若是则扩容*/
	ExpandSize(pDyList);

	/*数组未满，仍有空间*/
	pDyList->pListHead[pDyList->listlength] = elemValue;//往原来数组长度尾上装数据
	pDyList->listlength++;                               //数组长度加1
}


/*打印输出顺序表*/
void printList(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	printf("数组容量（size）：%u,数组长度（len）：%u\n", pDyList->listsize, pDyList->listlength);
	printf("当前数组元素如下所示:\n");
	for (unsigned int i = 0; i < pDyList->listlength; i++)
	{
		printf("%d,", pDyList->pListHead[i]);
	}
}


/*
中间插入
参数3：插入的下标位置
*/
void MidInsert(PDynamicList pDyList, ElemType elemValue, unsigned int position)
{
	/*判断顺序表是否满容,若是则扩容*/
	ExpandSize(pDyList);

	/*传递的下标过大*/
	if (position > pDyList->listlength)
	{
		position = pDyList->listlength;
	}

	/*表元素往后移动*/
	for (unsigned int i = pDyList->listlength; i > position; i--)
	{
		pDyList->pListHead[i] = pDyList->pListHead[i - 1];
	}

	pDyList->pListHead[position] = elemValue;//数据赋值
	pDyList->listlength++;                   //长度加1
}


/*顺序表扩容*/
void ExpandSize(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	/*判断数组是否满容*/
	if (pDyList->listlength == pDyList->listsize)
	{
		pDyList->listsize += 10;                                   //容量变大
		int* pTemp = (int*)malloc(sizeof(int) * pDyList->listsize);//申请空间
		memset(pTemp, 0, sizeof(int) * pDyList->listsize);

		/*将原数组复制进新空间*/
		for (unsigned int i = 0; i < pDyList->listlength; i++)
		{
			pTemp[i] = pDyList->pListHead[i];
		}

		free(pDyList->pListHead);  //释放原空间
		pDyList->pListHead = pTemp;//将数组头指向新空间
	}
}


/*删除中间*/
void MidDelete(PDynamicList pDyList, unsigned int position)
{
	if (pDyList == NULL || position>pDyList->listlength)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	/*数据从后往前移动*/
	for (unsigned i = position-1; i < pDyList->listlength-1; i++)
	{
		pDyList->pListHead[i] = pDyList->pListHead[i + 1];
	}

	pDyList->listlength--;
}



/*尾删除*/
void TailDeleteElem(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	pDyList->listlength--;//假删除，只是没遍历到最后一个元素，
}


/*删除全部*/
void DeleteComplete(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	pDyList->listlength=0;	
	pDyList->listsize = 0;

	free(pDyList->pListHead);
	pDyList->pListHead = NULL;
}


/*释放动态顺序表*/
void FreeDynamicList(PDynamicList pDyList)
{
	if (pDyList == NULL)
	{
		printf("\n传递参数有误!\n");
		return;
	}

	pDyList->listlength = 0;
	pDyList->listsize = 0;

	free(pDyList->pListHead);
	pDyList->pListHead = NULL;
}






/*******************************************动态数组表示顺序表*******************************************/
