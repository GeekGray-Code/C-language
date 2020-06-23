#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


/*data*/
#define MAXSIZE 20	//存储空间初始分配量

typedef int ElemType;	//
typedef int Status;	    //函数的类型，其值是函数结果状态代码，如OK等

typedef struct SqList
{
	ElemType data[MAXSIZE];	//数组存储数据元素，最大值为 MAXSIZE
	int length;	            //线性表当前长度
}SqList,*PSqList;


typedef struct DynamicArray
{
	int* pArrayHead;	//数组首地址
	unsigned int arraysize;//数组容量
	unsigned int arraylength;//当前数组长度

}DynamicArray,*PDynamicArray;



/*DynamicArray*/
void SequenceListTest();
void DynamicArrayTest();
void InitArray(DynamicArray* pDicArr);
void addElems(PDynamicArray pDicArr, int elemValue);
void printArray(PDynamicArray pDicArr);
void MidInsert(PDynamicArray pDicArr, int elemValue, unsigned int position);
void ExpandSize(PDynamicArray pDicArr);


/*Operation*/
Status GetElem(SqList L,int i,ElemType e);
Status ListInsert(SqList* L, int i, ElemType e);
Status ListDelete(PSqList L, int i, ElemType e);