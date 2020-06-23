#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


/*data*/
#define MAXSIZE 20	//�洢�ռ��ʼ������

typedef int ElemType;	//
typedef int Status;	    //���������ͣ���ֵ�Ǻ������״̬���룬��OK��

typedef struct SqList
{
	ElemType data[MAXSIZE];	//����洢����Ԫ�أ����ֵΪ MAXSIZE
	int length;	            //���Ա�ǰ����
}SqList,*PSqList;


typedef struct DynamicArray
{
	int* pArrayHead;	//�����׵�ַ
	unsigned int arraysize;//��������
	unsigned int arraylength;//��ǰ���鳤��

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