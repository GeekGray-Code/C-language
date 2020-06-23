#ifndef _PRAC_LINKED_LIST_H
#define _PRAC_LINKED_LIST_H 


#define NODESIZE sizeof(Node)//�ṹ��Node�Ĵ�С



/*����һ��Node�Ľṹ��*/
typedef struct node
{
	int value;
	struct node * next;
}Node, *PNode;

/*��װͷβָ�룬*/
typedef struct List
{
	Node* head;
	Node* tail;
}List, *PList;


extern int nodeCnt;	//������

/*�п�ͷ*/
extern Node* pStart;//ͷָ��
extern Node* pEnd;  //βָ��

/*�޿�ͷ*/
extern Node* pHead;//ȫ��ͷ���
extern Node* pTail;//ȫ��β���



void pracLinkedListTest();								   //���� ���Ժ���


/*�ṹ���װ*/
List* initList(PList plist);                                //�����ʼ��
void addListNodeByTail(PList plist, int value);             //β���
void addListNodeByHead(PList plist, int value);             //ͷ���
void scanList(PList plist);                                 //�������
Node* selectListNodeAppon(PList plist, int value);          //����ָ���ڵ�
void addListNodeByRandom(PList plist, int index, int value);//����λ����ӽڵ�
int isNodeListNull(PList plist);                            //�����п�
void deleteListByHead(PList plist);                         //ͷɾ��
void deleteListByTail(PList plist);                         //βɾ��
void delectListNodeByRandom(PList plist, int value);        //ɾ������ڵ�
void freeNodeList(PList plist);                             //�ͷ�����



/*�п�ͷ*/
int isListNull();                     //�����п�
Node* initLinkedList();               //�����ʼ��
Node* createNewNode(int value);       //�����½ڵ�
void addNodeByEnd(int value);         //β���
void addNodeByStart(int value);       //ͷ���
void addNodeAppon(int pos, int value);//����λ����ӽڵ�
void scanNodeList();                  //�������
Node* selectNodeAppon(int value);     //����ָ���ڵ�
void deleteLinkedListByStart();       //ͷɾ��
void deleteLinkedListByEnd();         //βɾ��
void delectNodeByRandom(int value);   //ɾ��ָ���ڵ�
void freeList();                      //�ͷ�����


/*�޿�ͷ*/
void addNodeByTail(int value);                        //β�巨��β���,���У�
Node* addNodeByHead(int value);                       //ͷ�巨��ͷ��ӣ�ջ��
void scanLinkedList();                                //�������/��ӡ
Node* selectNode(int index);                          //�����ѯ/��
void freeLinkedList();                                //�������
void insertNodeAppon(int pos, int value);             //��ָ��λ�ò���ڵ�
void deleteLinkedListByHead();                        //ͷɾ������ջ��ͷ���+ͷɾ����
void deleteLinkedListByTail();                        //βɾ���������У�ͷ��� + βɾ�� / β��� + ͷɾ����
void delectNodeAppon(int value);                      //ɾ��ָ���ڵ�


/*̷��ǿC*/
void staticLinkedList();							//��̬����
Node* createLinkedList();							//����һ������̬����
Node* removeNode(PNode pHead, long index);			//�������ɾ������
Node* insertNode(PNode pHead, PNode newNode);		//������Ĳ������
void printLinkedList(PNode pHead);					//�������

#endif