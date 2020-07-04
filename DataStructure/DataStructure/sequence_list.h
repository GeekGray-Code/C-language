/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	���Ա��˳��洢
 ************************************************************************/

#pragma once


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define LIST_INIT_SIZE 5	//�洢�ռ��ʼ������

typedef int ElemType;	//
typedef int Status;	    //���������ͣ���ֵ�Ǻ������״̬���룬��OK��


void SequenceListTest();

/****************************************StaticList********************************************************/

/*��̬�����ʾ˳���*/
typedef struct StaticList
{
	ElemType data[LIST_INIT_SIZE];	//����洢����Ԫ�أ�
	int length;	            //���Ա�ǰ����
}StaticList,*PStaticList;

/*Operation*/
void StaticListTest();
Status GetElem(StaticList stList, int i, ElemType e);
Status ListInsert(StaticList* pStList, int i, ElemType e);
Status ListDelete(PStaticList pStList, int i, ElemType e);

/****************************************StaticList********************************************************/



/*******************************************DynamicList***************************************************/

/*��̬�����ʾ˳���*/
typedef struct DynamicList
{
	ElemType* pListHead;	//�����׵�ַ
	unsigned int listsize;  //��������
	unsigned int listlength;//��ǰ���鳤��

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


