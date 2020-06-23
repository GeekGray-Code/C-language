#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include"single_linked_list.h"

int nodeCnt = 0;	//链表的结点数量，全局

/*无空头*/
Node* pHead = NULL;//头结点,先使PHead的值为NULL，表示链表为空的情况，即pHead不指向任何结点，链表中无结点
Node* pTail = NULL;//指向尾

/*有空头*/
Node* pStart = NULL;//头指针
Node* pEnd = NULL;//尾指针




/*链表 测试函数*/
void pracLinkedListTest()
{
	//staticLinkedList();

	//createLinkedList();
	//printLinkedList(createLinkedList());
	//removeNode(createLinkedList(),10103);
	//printLinkedList(removeNode(createLinkedList(), 10103));

	/*PNode newNode = createNewNode(10101);
	printLinkedList(insertNode(createLinkedList(),createNewNode(10105)));*/

	//printLinkedList(addNodeByTail(10101));

	/*********************************************无空头结点测试***********************************************************/

	/*for (int i = 10101; i < 10105; i++)
	{
		addNodeByTail(i);
	}

	scanLinkedList(pHead);

	PNode pSelect = selectNode(pHead, 10101);
	if (pSelect != NULL)
	{
	printf("selectNode:\n");
	printf("value\tnext\n");
	printf("%d\t", pSelect->value);
	printf("%p\t\n\n\n", pSelect->next);
	}
	else
	{
	printf("当前链表中无此节点\n");
	}

	printf("指定位置插入节点......\n");
	insertNodeAppon(pHead, 10104, 10105);
	printf("完成指定位置插入!\n");
	scanLinkedList(pHead);

	printf("头删除...\n");
	deleteLinkedListByHead(pHead);
	printf("完成头删除！\n");
	scanLinkedList(pHead);

	printf("尾删除...\n");
	deleteLinkedListByTail(pHead);
	printf("完成尾删除！\n");
	scanLinkedList(pHead);

	printf("删除指定节点...\n");
	delectNodeAppon(10101);
	delectNodeAppon(10104);
	printf("完成指定节点删除！\n");
	scanLinkedList(pHead);

	freeLinkedList(pHead);*/
	/*****************************************无空头结点测试**************************************************************/



	/******************************************有空头结点测试*******************************************************/
	
	/*initLinkedList();

	for (int i = 10101; i < 10110; i++)
	{
		addNodeByEnd(i);
		addNodeByStart(i);
	}
	printf("遍历pStart\n");
	scanNodeList();

	addNodeByStart(10101);
	addNodeAppon(10102,100000);

	deleteLinkedListByStart();
	deleteLinkedListByEnd();

	delectNodeByRandom(10105);

	scanNodeList();

	freeList();*/
	/*******************************************有空头结点测试*******************************************************/





	/*******************************************结构体封装head，tail 测试*******************************************/


	/*List list,list1;
	PList plist = NULL;
	PList plist1 = NULL;

	list.head = list.tail = NULL;
	list1.head = list1.tail = NULL;

	plist = initList(&list);
	plist1 = initList(&list1);

	for (int i = 10101; i < 10106; i++)
	{
		addListNodeByTail(plist, i);
	}
	printf("遍历plist\n");
	scanList(plist);


	for (int i = 10101; i < 10106; i++)
	{
		addListNodeByHead(plist1, i);
	}
	printf("\n\n遍历plist1\n");
	scanList(plist1);

	printf("指定节点：%p\t%d", selectListNodeAppon(plist1, 10101)->next, selectListNodeAppon(plist1, 10101)->value);
	


	printf("\n\n指定位置插入节点plist1\n");
	addListNodeByRandom(plist1,10105,10108);
	scanList(plist1);

	printf("链表是否为空1为空，0位非空：%d",isNodeListNull(plist1));


	printf("\n\n头删除plist1\n");
	deleteListByHead(plist1);
	scanList(plist1);

	printf("\n\n尾删除plist1\n");
	deleteListByTail(plist1);
	scanList(plist1);


	printf("\n\n删除指定节点plist1\n");
	delectListNodeByRandom(plist1,10103);
	scanList(plist1);

	freeNodeList(plist1);*/

	/******************************************结构体封装head，tail 测试*******************************************/


}





/************************************************结构体封装head，tail****************************************************/

/*
链表初始化
*/
List* initList(PList plist)
{
	plist->tail = plist->head = (PNode)malloc(NODESIZE);//链表空头
	plist->head->next = NULL;

	printf("链表初始化完成！\n");

	return plist;
}


/*
尾添加
参数2：数据项
*/
void addListNodeByTail(PList plist, int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//创建一个新节点

	if (pNewNode == NULL)
	{
		return;
	}

	/*节点成员赋值*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*链接*/

	plist->tail->next = pNewNode;
	plist->tail = pNewNode;

}


/*
头添加
*/
void addListNodeByHead(PList plist, int value)
{

	PNode pNewNode = createNewNode(value);//创建一个新节点

	if (pNewNode == NULL)
	{
		return;
	}

	/*链接*/
	pNewNode->next = plist->head->next;
	plist->head->next = pNewNode;
}


/*
查找指定节点
*/
Node* selectListNodeAppon(PList plist, int value)
{
	PNode pNewNode = plist->head->next;
	//PNode pNewNode = (*pStart).next;

	while (pNewNode != NULL)
	{
		if (pNewNode->value == value)
		{
			return pNewNode;
		}

		pNewNode = pNewNode->next;
	}

	return NULL;
}



/*
任意位置添加节点，在索引值后插入
参数1：plist
参数2：指定插入的索引值
参数3：需要插入节点的数据项
*/
void addListNodeByRandom(PList plist, int index, int value)
{
	//链表判空
	if (plist->head->next == NULL)
	{
		printf("空链表！\n");
		return;
	}

	//找节点
	PNode pTemp = selectListNodeAppon(plist, index);
	if (pTemp == NULL)
	{
		printf("无此位置节点！\n");
		return;
	}

	//找到了，链接到位置
	PNode pNewNode = createNewNode(value);//创建新节点


	if (pTemp == plist->tail)//如果是尾结点
	{
		addListNodeByTail(plist, value);
	}
	else
	{
		pNewNode->next = pTemp->next;//先链接
		pTemp->next = pNewNode;//后断开
	}

}


/*
链表遍历
*/
void scanList(PList plist)
{
	PNode pNewNode = plist->head->next;//从头结点的下一个节点开始遍历

	while (pNewNode != NULL)
	{
		printf("%d\n", pNewNode->value);
		pNewNode = pNewNode->next;//指针后移
	}

}


/*链表判空*/
int isNodeListNull(PList plist)
{
	//链表判空
	if (plist->head->next == NULL)
	{
		printf("空链表！\n");
		return 1;//为空
	}

	return 0;//不为空
}



/*
头删除
*/
void deleteListByHead(PList plist)
{
	if (isNodeListNull(plist))//链表判空
	{
		return;
	}


	PNode pTemp = plist->head->next;//记录头
	plist->head->next = plist->head->next->next;//改变头
	free(pTemp);//释放

	printf("头节点删除完成！\n");
}



/*
尾删除
*/
void deleteListByTail(PList plist)
{
	if (isNodeListNull(plist))//链表判空
	{
		return;
	}


	if (plist->head->next == plist->tail)//有一个节点
	{
		free(plist->tail);
		plist->head->next = NULL;
		return;
	}
	else
	{
		PNode pCurrent = plist->head;//一开始指向当前节点

		while (pCurrent->next != NULL)//循环遍历，找到尾结点的上一个节点
		{
			/*if (plist->tail == pTemp->next)
			{
				break;
			}*/

			plist->tail = pCurrent;
			pCurrent = pCurrent->next;
		}

		plist->tail->next = NULL;
		free(pCurrent);// 此时，pCurrent就是尾结点
	}

	printf("尾节点删除完成！\n");
}




/*
删除任意节点
*/
void delectListNodeByRandom(PList plist, int value)
{
	if (isNodeListNull(plist))//链表判空
	{
		return;
	}

	PNode pTemp = selectListNodeAppon(plist, value);//找到指定节点
	if (pTemp == NULL)
	{
		printf("无此节点！\n");
		return;
	}

	if (pTemp == plist->tail)//一个结点
	{
		deleteListByTail(plist);//释放尾
	}
	else
	{
		PNode pMove = plist->head;

		while (pMove != NULL)
		{
			if (pTemp == pMove->next)
			{
				break;
			}

			pMove = pMove->next;
		}

		pMove->next = pTemp->next;//删除
		free(pTemp);//释放
	}

	printf("随机节点删除完成!\n");
}


/*
释放链表
*/
void freeNodeList(PList plist)
{
	PNode pTemp = plist->head;

	while (pTemp != NULL)
	{
		PNode pMove = pTemp;
		pTemp = pTemp->next;
		free(pMove);
	}

	plist->head = plist->tail = NULL;

	printf("链表释放完成！\n");
}













/************************************************有空头结点***********************************************************/

/*
空头初始化
*/
Node* initLinkedList()
{
	pStart = pEnd = (PNode)malloc(NODESIZE);//链表空头
	pStart->next = NULL;

	printf("链表初始化完成！\n");

	return pStart;
}




/*
创建新节点
*/
Node* createNewNode(int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//创建一个新节点
	
	if (pNewNode==NULL)
	{
		printf("节点创建失败！\n");
		return NULL;
	}

	/*节点成员赋值*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	return pNewNode;
}

/*
尾添加 
参数：数据项
*/
void addNodeByEnd(int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//创建一个新节点

	if (pNewNode == NULL)
	{
		return;
	}

	/*节点成员赋值*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*链接*/
	
	pEnd->next = pNewNode;
	pEnd = pNewNode;

}



/*
头添加
*/
void addNodeByStart(int value)
{

	PNode pNewNode = createNewNode(value);//创建一个新节点

	if (pNewNode==NULL)
	{
		return;
	}

	/*链接*/
	pNewNode->next = pStart->next;
	pStart->next = pNewNode;
}


/*
任意位置添加节点，在索引值后插入
参数1：头指针
参数2：指定插入的索引值
参数3：需要插入节点的数据项
*/
void addNodeAppon(int index, int value)
{
	//链表判空
	if (pStart->next==NULL)
	{
		printf("空链表！\n");
		return;
	}

	//找节点
	PNode pTemp = selectNodeAppon(index);
	if (pTemp==NULL)
	{
		printf("无此位置节点！\n");
		return;
	}

	//找到了，链接到位置
	PNode pNewNode = createNewNode(value);//创建新节点


	if (pTemp==pEnd)//如果是尾结点
	{
		addNodeByEnd(value);
	}
	else
	{
		pNewNode->next = pTemp->next;//先链接
		pTemp->next = pNewNode;//后断开
	}

}




/*
链表遍历
*/
void scanNodeList()
{
	PNode pNewNode = pStart->next;//从头结点的下一个节点开始遍历

	while (pNewNode!=NULL)
	{
		printf("%d\n",pNewNode->value);
		pNewNode = pNewNode->next;//指针后移
	}

}



/*
查找指定节点
*/
Node* selectNodeAppon(int value)
{
	PNode pNewNode = pStart->next;
	//PNode pNewNode = (*pStart).next;

	while (pNewNode!=NULL)
	{
		if (pNewNode->value==value)
		{
			return pNewNode;
		}

		pNewNode = pNewNode->next;
	}

	return NULL;
}


/*
头删除
*/
void deleteLinkedListByStart()
{
	if (isListNull())//链表判空
	{
		return;
	}
	

	PNode pTemp = pStart->next;//记录头
	pStart->next = pStart->next->next;//改变头
	free(pTemp);//释放

	printf("头节点删除完成！\n");
}




/*
尾删除
*/
void deleteLinkedListByEnd()
{
	if (isListNull())//链表判空
	{
		return;
	}


	if (pStart->next==pEnd)//有一个节点
	{
		free(pEnd);
		pStart->next = NULL;
		pEnd = pStart;
	}
	else
	{
		PNode pTemp = pStart->next;

		while (pTemp != NULL)//循环遍历，找到尾结点的上一个节点
		{
			if (pEnd == pTemp->next)
			{
				break;
			}

			pTemp = pTemp->next;
		}

		free(pEnd);// 此时，pTemp就是尾结点前一个节点
		pEnd = pTemp;//改变新尾巴
		pEnd->next = NULL;//尾结点的next赋空
	}

	printf("尾节点删除完成！\n");
}




/*
删除任意节点
*/
void delectNodeByRandom(int value)
{
	if (isListNull())//链表判空
	{
		return;
	}

	PNode pTemp = selectNodeAppon(value);//找到指定节点
	if (pTemp==NULL)
	{
		printf("无此节点！\n");
		return;
	}

	if (pTemp == pEnd)//一个结点
	{
		deleteLinkedListByEnd();//释放尾
	}
	else
	{
		PNode pMove = pStart;

		while (pMove != NULL)
		{
			if (pTemp == pMove->next)
			{
				break;
			}

			pMove = pMove->next;
		}

		pMove->next = pTemp->next;//删除
		free(pTemp);//释放
	}

	printf("随机节点删除完成!\n");
}


/*
释放链表
*/
void freeList()
{
	PNode pTemp = pStart;

	while (pTemp!=NULL)
	{
		PNode pMove = pTemp;
		pTemp = pTemp->next;
		free(pMove);
	}

	pStart = pEnd = NULL;

	printf("链表释放完成！\n");
}


/*链表判空*/
int isListNull()
{
	//链表判空
	if (pStart->next == NULL)
	{
		printf("空链表！\n");
		return 1;//为空
	}

	return 0;//不为空
}


/************************************************无空头结点***********************************************************/

/*
创建一个链表（添加节点）——尾插法（尾添加,队列）
参数:数据域
返回值：此函数带回一个指针值，它指向一个 Node 类型数据，实际上带回一个链表起始地址
*/
void addNodeByTail(int value)
{
	PNode pTemp = (PNode)malloc(NODESIZE);
	//pTemp = (Node*)malloc(sizeof(Node));

	pTemp->value = value;
	pTemp->next = NULL;

	//链接
	if (pHead == NULL)
	{
		//空链表
		pHead = pTemp;
		pTail = pTemp;
	}
	else
	{
		pTail->next = pTemp;//链表不为空，往链尾添加
	}

	pTail = pTemp; //使pTail指向最后一个结点，即移动到表尾

}



/*
创建一个链表（添加节点）——头插法（头添加，栈）
参数:数据域
返回值：此函数带回一个指针值，它指向一个 Node 类型数据，实际上带回一个链表起始地址
*/
Node* addNodeByHead(int value)
{
	Node* pHead;//头结点
	Node* pTemp;//移动指针
	Node* pTail;//指向尾

	pHead = pTail = NULL; //先使PHead的值为NULL，表示链表为空的情况，即pHead不指向任何结点，链表中无结点

	pTemp = (PNode)malloc(NODESIZE);
	//pTemp = (Node*)malloc(sizeof(Node));

	pTemp->value = value;	//节点数据赋值
	pTemp->next = NULL;

	//链接
	if (pHead == NULL)
	{
		//空链表
		pHead = pTemp;
		pTail = pTemp;
	}
	else
	{
		pTail->next = pHead;//链表不为空，新节点的下一个指向头
	}

	pHead = pTemp; //新节点就是头

	return pHead;
}


/*
链表遍历/打印
参数：头指针，链表的起始地址
*/
void scanLinkedList()
{
	PNode pMove = pHead;						//使pNode1 指向第一个结点

	//if (pHead != NULL)						//如果pNode1 指向的不是尾结点
	//{
	//	do
	//	{
	//		printf("%d\n", pMove->value);	//输出 pNode1 所指向结点的值
	//		pMove = pMove->next;			//使 pNode1 指向下一个结点
	//	} while (pMove != NULL);			//当pNode1指向表尾时，跳出循环
	//}

	if (pHead != NULL)
	{
		while (pMove)
		{
			printf("%d\n", pMove->value);	//输出 pNode1 所指向结点的值
			pMove = pMove->next;			//使 pNode1 指向下一个结点
		}
	}
}


/*
链表查询/改
参数1：头指针，链表的起始地址
参数2：查询索引值
返回值：返回节点指针
*/
Node* selectNode(int index)
{
	PNode pMove = pHead;			//使pMove 指向第一个结点

	if (pHead != NULL)
	{
		while (pMove != NULL)
		{
			if (pMove->value == index)//如果找到了，返回
			{
				return pMove;
			}

			pMove = pMove->next;//如果没找到，指针后移
		}

		return NULL;//遍历完毕，没找到返回NULL
	}
}


/*
链表清空
参数1：头指针
*/
void freeLinkedList()
{

	PNode pMove = pHead;//记录头，防止头被修改，丢节点

	while (pMove != NULL)
	{
		PNode pTemp = pMove;
		pMove = pMove->next;
		free(pTemp);
	}

	/*头尾清空*/
	pHead = NULL;
	pTail = NULL;
}



/*
在指定位置插入节点
参数1：头指针
参数2：插入位置
参数3：数据项
*/
void insertNodeAppon(int pos, int value)
{
	if (pHead == NULL)//链表为空
	{
		printf("空链表");
		return;
	}

	PNode pSearch = selectNode(pos);//找到节点位置，并返回节点指针
	if (pSearch == NULL)
	{
		printf("没有找到指定位置！\n");
		return;
	}

	PNode pNewNode = (PNode)malloc(NODESIZE);//当前链表有此位置，创建一个新节点

	/*节点成员赋值*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*将节点链接到链表上*/
	if (pSearch = pTail)//如果插入的位置在表尾
	{
		pTail->next = pNewNode;//尾节点next指向新节点
		pTail = pNewNode;      //新新节点是最后一个节点，变成表尾节点
	}
	else
	{
		pNewNode->next = pSearch->next;//新节点的next指向指定位置节点的下一个节点
		pSearch->next = pNewNode;      //指定位置节点的next指向新节点
	}
}


/*
头删除：（栈：头添加+头删除）
*/
void deleteLinkedListByHead()
{
	if (pHead == NULL)
	{
		printf("空链表！");
		return;
	}

	PNode pTemp = pHead;//先记住旧的头指针
	pHead = pHead->next;//头的下一个节点变成新的头
	free(pTemp);
}


/*
尾删除：（队列：头添加+尾删除/尾添加+头删除）
*/
void deleteLinkedListByTail()
{
	if (pHead == NULL)
	{
		printf("空链表！");
		return;
	}

	if (pHead == pTail)//头尾指向的是同一个，说明只有一个节点
	{
		free(pTail);
		pHead = NULL;
		pTail = NULL;
	}
	else            //多个节点
	{
		PNode pMove = pHead;

		/*遍历链表，找到尾节点的前一个节点*/
		while (pMove->next != pTail)
		{
			pMove = pMove->next;
		}

		free(pTail);//释放尾节点
		pTail = pMove;
		pTail->next = NULL;
	}
}


/*
删除指定节点
参数：数据项
*/
void delectNodeAppon(int value)
{
	if (pHead == NULL)
	{
		printf("空链表！");
		return;
	}

	PNode pTemp = selectNode(value);
	if (pTemp == NULL)
	{
		printf("无此节点！");
		return;
	}

	/*只有一个节点*/
	if (pHead == pTail)
	{
		free(pTail);
		pHead = NULL;
		pTail = NULL;
	}
	/*有2个节点*/
	else if (pHead->next == pTail)
	{
		if (pHead == pTemp)
		{
			deleteLinkedListByHead();
		}
		else
		{
			deleteLinkedListByTail();
		}
	}
	/*有多个节点*/
	else
	{
		if (pHead == pTemp)
		{
			deleteLinkedListByHead();
		}
		else if (pTail == pTemp)
		{
			deleteLinkedListByTail();
		}
		else//删除中间节点
		{
			PNode pMove = pHead;

			/*遍历链表，找到指定节点的前一个节点*/
			while (pMove->next != pTemp)
			{
				pMove = pMove->next;
			}

			pMove->next = pTemp->next;
			free(pTemp);//释放尾节点
		}
	}
}





/******************************************************谭浩强C**********************************************************/
/*静态链表*/
void staticLinkedList()
{
	Node nodeA, nodeB, nodeC;			// 定义三个结构体node变量
	PNode pHead, pNext;					// Node*

	nodeA.value = 10101;
	nodeB.value = 10102;
	nodeC.value = 10103;				//对结点的value赋值

	pHead = &nodeA;						//将节点nodeA的起始地址赋值给头指针pHead，pHead只有指针域，没有信息域
	nodeA.next = &nodeB;				//将节点nodeB的起始地址赋值给nodeA结点的next成员
	nodeB.next = &nodeC;				//将节点nodeC的起始地址赋值给nodeB结点的next成员
	nodeC.next = NULL;					//使节点nodeC的next成员不存放任何其他结点地址，即表尾
	pNext = pHead;						//使pNext指针指向nodeA结点，pNext指针的作用是不断指向链表中的下一个结点，用于遍历输出链表

	// 输出链表
	do
	{
		printf("%d\n", pNext->value);	//输出pNext指向结点的数据
		pNext = pNext->next;			//使pNext指向下一结点
	} while (pNext != NULL);			//输出完链表中最后一个结点数据后，pNext的值为NULL
}



/*创建一个单向动态链表，此函数带回一个指针值，它指向一个 Node 类型数据，实际上带回一个链表起始地址*/
Node* createLinkedList()
{
	PNode pHead, pNode1, pNode2;


	printf("创建一个新链表，请输结点的value值，输入0表示链表初始化结束：\n");
	pNode1 = pNode2 = (PNode)malloc(NODESIZE);	//开辟一个新单元
	pHead = NULL;	 							//先使PHead的值为NULL，表示链表为空的情况，即pHead不指向任何结点，链表中无结点

	scanf("%d", &pNode1->value);				//输入一个value值
	while (pNode1->value != 0)					//约定 value 的值不为0，若输入为0则表示建立链表的过程完成
	{
		nodeCnt = nodeCnt + 1;					//如果输入的pNode1->value不等于0，则输入的是第一个结点数据,此时结点数量加1

		if (nodeCnt == 1)						//如果是第一个结点，
		{
			pHead = pNode1;						//使pHead也指向新开辟的结点，pNode1所指向的新开辟的结点就成为链表中第一个结点
		}
		else                                    //nodeCnt！=1，不是第一结点
		{
			pNode2->next = pNode1;				//此时pNode2 指向第一个结点（就是把pNode1所指的结点连接到pNode2所指结点的后面），
			                                    //将新新节点的地址赋值给第一个next成员，使第一个结点的next成员指向第二个结点
		}

		pNode2 = pNode1;						//使pNode2指向最后一个结点，即移动到表尾
		pNode1 = (PNode)malloc(NODESIZE);		//再开辟一个新结点（单元），使pNode1指向它
		scanf("%d", &pNode1->value);			//接着输入结点数据
	}

	pNode2->next = NULL;						//由于pNode1->value 的值为0，不再执行循环，此结点不应被连接到链表中，此时将表尾结点的指针变量置NULL

	if (nodeCnt != 0)
	{
		printf("初始化了结点个数为 %d 的单向链表\n", nodeCnt);
	}
	else
	{
		printf("初始化了一个空链表\n");
	}

	printf("当前链表结点数量：%d\n", nodeCnt);
	return pHead;								//调用createNode函数后，函数的值是所建立链表的第一个结点的地址，即链表的头地址
}



/*
输出链表
参数：Node*，由实参传过来，即将已有的链表的头指针传给被调用的函数
在printNodeList函数中从head所指的第一个结点出发顺序输出各个结点
*/
void printLinkedList(PNode pHead)
{
	PNode pNode1;

	printf("链表%d条记录如下：\n", nodeCnt);

	pNode1 = pHead;							//使pNode1 指向第一个结点
	if (pHead != NULL)						//如果pNode1 指向的不是尾结点
	{
		do
		{
			printf("%d\n", pNode1->value);	//输出 pNode1 所指向结点的值
			pNode1 = pNode1->next;			//使 pNode1 指向下一个结点
		} while (pNode1 != NULL);			//当pNode1指向表尾时，跳出循环
	}

	printf("当前链表结点数量：%d\n", nodeCnt);
}





/*
对链表的删除操作
参数1：Node* 类型，即链表的头指针
参数2：链表结点的索引或者标识，比如学号等
返回值：返回一个新链表的头指针
*/
Node* removeNode(PNode pHead, long index)
{
	PNode pNode1, pNode2;

	if (pHead == NULL)										//空表的情况
	{
		printf("空表!\n");
	}

	pNode2 = pNode1 = pHead;

	while (index != pNode1->value && pNode1->next != NULL)	//pNode1 指向的不是所要找的结点，并且后面还有其他结点
	{
		pNode2 = pNode1;
		pNode1 = pNode1->next;								//pNode1 后移一个结点
	}

	if (index == pNode1->value)								//找着了要干掉的那个结点
	{
		if (pNode1 == pHead)									//若pNode1 指向的是头结点，
		{
			pHead = pNode1->next;							//把第二个结点的地址赋予pHead,删除头结点
		}
		else
		{
			pNode2->next = pNode1->next;					//否则将下一结点地址赋给前一结点地址，即删除一个结点
		}

		printf("remove Node: %ld\n", index);					//移除目标结点
		nodeCnt = nodeCnt - 1;								//结点数量-1
	}
	else
	{
		printf("无法找到索引为：%ld的结点", index);				//目标结点不存在
	}

	printf("当前链表结点数量：%d\n", nodeCnt);
	return pHead;
}


/*
对链表的插入操作
参数1：已存在的链表头指针
参数2：需要的插入的新结点
*/
Node* insertNode(PNode pHead, PNode newNode)
{
	PNode pNode0, pNode1, pNode2;

	pNode2 = pNode1 = pHead;			//使pNode1 指向第一个结点
	pNode0 = newNode;					//使pNode0 指向要插入的新结点

	if (pHead == NULL)					//若来存在的链表是空链表
	{
		pHead = pNode0;					//使pNode0 指向的结点（newNode）作为头结点
		pNode0->next = NULL;			//表尾置空
		printf("插入头结点：%ld\n", newNode->value);
	}
	else
	{
		while ((pNode0->value > pNode1->value) && (pNode1->next != NULL))//pNode0->value > pNode1->value 且 pNode1 所指的不是表尾结点
		{
			pNode2 = pNode1;			//使pNode2 指向刚才pNode1指向的结点
			pNode1 = pNode1->next;		//pNode1 后移一个结点
		}

		if (pNode0->value <= pNode1->value)
		{
			if (pHead == pNode1)			//若pNode1 指向的是头结点
			{
				pHead = pNode0;			//插入到表头之前
				printf("插入头结点：%ld\n", newNode->value);
			}
			else
			{
				pNode2->next = pNode0;	//若pNode1 指向的不是头结点，插入到pNode2指向的结点之后（即插入到中间）
				printf("插入中间结点：%ld\n", newNode->value);
			}

			pNode0->next = pNode1;
		}
		else
		{
			pNode1->next = pNode0;
			pNode0->next = NULL;		//插入到最后的结点（表尾）之后
			printf("插入尾结点：%ld\n", newNode->value);
		}
	}

	nodeCnt++;							//结点数量加1
	printf("当前链表结点数量：%d\n", nodeCnt);

	return pHead;
}

