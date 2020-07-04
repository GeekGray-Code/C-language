/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	线性表的顺序存储
 ************************************************************************/

#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define LIST_INIT_SIZE 5	//存储空间初始分配量

typedef int ElemType;	//
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等


void SequenceListTest();

/****************************************StaticList********************************************************/

/*静态数组表示顺序表*/
typedef struct StaticList
{
	ElemType data[LIST_INIT_SIZE];	//数组存储数据元素，
	int length;	            //线性表当前长度
}StaticList,*PStaticList;

/*Operation*/
void StaticListTest();
Status GetElem(StaticList stList, int i, ElemType e);
Status ListInsert(StaticList* pStList, int i, ElemType e);
Status ListDelete(PStaticList pStList, int i, ElemType e);

/****************************************StaticList********************************************************/



/*******************************************DynamicList***************************************************/

/*动态数组表示顺序表*/
typedef struct DynamicList
{
	ElemType* pListHead;	//数组首地址
	unsigned int listsize;  //数组容量
	unsigned int listlength;//当前数组长度

}DynamicList,*PDynamicList;

/*Operation*/
void DynamicListTest();
void InitList(DynamicList* pDyList);
void addElems(PDynamicList pDyList, ElemType elemValue);
void printList(PDynamicList pDyList);
void MidInsert(PDynamicList pDyList, ElemType elemValue, unsigned int position);
void ExpandSize(PDynamicList pDyList);
void TailDeleteElem(PDynamicList pDyList);
void DeleteComplete(PDynamicList pDyList);
void FreeDynamicList(PDynamicList pDyList);
void MidDelete(PDynamicList pDyList, unsigned int position);


/*******************************************DynamicArra***************************************************/


