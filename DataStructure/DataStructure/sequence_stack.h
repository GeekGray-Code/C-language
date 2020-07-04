/*************************************************************************
 > Author:  GeekGray
 > Mail:    GeekGray@163.com
 > Time:    2020-07-04
 > Desc:	˳��ջ
 ************************************************************************/

#pragma once



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 50	//˳��ջ�洢�ռ��ʼ������
#define STACK_INCREMENT 10	//˳��ջ�洢�ռ��������

typedef int ElemType;	//
typedef int Status;	    //���������ͣ���ֵ�Ǻ������״̬���룬��OK��


/**********************************************���ڶ�̬����ʵ�ֵ�˳��ջ****************************************/

typedef struct SequenceStack
{
	ElemType* pBase;	//ջ��ָ��
	ElemType* pTop;		//ջ��ָ��
	int stacksize;		//ջ��ǰ��ʹ�õ��������
}SequenceStack,*PSequenceStack;

/*Operation*/
void SequenceStackTest();
Status InitStack(PSequenceStack pSqStack);	                    //��ʼ��һ����ջ
Status StackEmpty(PSequenceStack pSqStack);
Status DestroyStack(PSequenceStack pSqStack);	                //����ջ
Status ClearStack(PSequenceStack pSqStack);	                    //�ÿ�ջ
Status StackEmpty(PSequenceStack pSqStack);	                    //�жϿ�ջ
int StackLength(PSequenceStack pSqStack);	                    //ջ�ĳ���
Status GetTop(PSequenceStack pSqStack,ElemType* pElemValue);	//ջ��Ԫ��
Status SequenceStackPush(PSequenceStack pSqStack, ElemType elemvalue);	    //����elemvalueԪ��Ϊջ��Ԫ��
Status SequenceStackPop(PSequenceStack pSqStack, ElemType* pElemValue);	    //ɾ��ջ��Ԫ�أ���pElemValue����

/**********************************************���ڶ�̬����ʵ�ֵ�˳��ջ****************************************/
