#ifndef _PRAC_LINKED_LIST_H
#define _PRAC_LINKED_LIST_H 


#define NODESIZE sizeof(Node)//结构体Node的大小



/*定义一个Node的结构体*/
typedef struct node
{
	int value;
	struct node * next;
}Node, *PNode;

/*封装头尾指针，*/
typedef struct List
{
	Node* head;
	Node* tail;
}List, *PList;


extern int nodeCnt;	//结点个数

/*有空头*/
extern Node* pStart;//头指针
extern Node* pEnd;  //尾指针

/*无空头*/
extern Node* pHead;//全局头结点
extern Node* pTail;//全局尾结点



void pracLinkedListTest();								   //链表 测试函数


/*结构体封装*/
List* initList(PList plist);                                //链表初始化
void addListNodeByTail(PList plist, int value);             //尾添加
void addListNodeByHead(PList plist, int value);             //头添加
void scanList(PList plist);                                 //链表遍历
Node* selectListNodeAppon(PList plist, int value);          //查找指定节点
void addListNodeByRandom(PList plist, int index, int value);//任意位置添加节点
int isNodeListNull(PList plist);                            //链表判空
void deleteListByHead(PList plist);                         //头删除
void deleteListByTail(PList plist);                         //尾删除
void delectListNodeByRandom(PList plist, int value);        //删除任意节点
void freeNodeList(PList plist);                             //释放链表



/*有空头*/
int isListNull();                     //链表判空
Node* initLinkedList();               //链表初始化
Node* createNewNode(int value);       //创建新节点
void addNodeByEnd(int value);         //尾添加
void addNodeByStart(int value);       //头添加
void addNodeAppon(int pos, int value);//任意位置添加节点
void scanNodeList();                  //链表遍历
Node* selectNodeAppon(int value);     //查找指定节点
void deleteLinkedListByStart();       //头删除
void deleteLinkedListByEnd();         //尾删除
void delectNodeByRandom(int value);   //删除指定节点
void freeList();                      //释放链表


/*无空头*/
void addNodeByTail(int value);                        //尾插法（尾添加,队列）
Node* addNodeByHead(int value);                       //头插法（头添加，栈）
void scanLinkedList();                                //链表遍历/打印
Node* selectNode(int index);                          //链表查询/该
void freeLinkedList();                                //链表清空
void insertNodeAppon(int pos, int value);             //在指定位置插入节点
void deleteLinkedListByHead();                        //头删除：（栈：头添加+头删除）
void deleteLinkedListByTail();                        //尾删除：（队列：头添加 + 尾删除 / 尾添加 + 头删除）
void delectNodeAppon(int value);                      //删除指定节点


/*谭浩强C*/
void staticLinkedList();							//静态链表
Node* createLinkedList();							//创建一个单向动态链表
Node* removeNode(PNode pHead, long index);			//对链表的删除操作
Node* insertNode(PNode pHead, PNode newNode);		//对链表的插入操作
void printLinkedList(PNode pHead);					//输出链表

#endif