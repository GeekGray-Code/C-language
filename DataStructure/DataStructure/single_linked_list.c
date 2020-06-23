#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include"single_linked_list.h"

int nodeCnt = 0;	//����Ľ��������ȫ��

/*�޿�ͷ*/
Node* pHead = NULL;//ͷ���,��ʹPHead��ֵΪNULL����ʾ����Ϊ�յ��������pHead��ָ���κν�㣬�������޽��
Node* pTail = NULL;//ָ��β

/*�п�ͷ*/
Node* pStart = NULL;//ͷָ��
Node* pEnd = NULL;//βָ��




/*���� ���Ժ���*/
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

	/*********************************************�޿�ͷ������***********************************************************/

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
	printf("��ǰ�������޴˽ڵ�\n");
	}

	printf("ָ��λ�ò���ڵ�......\n");
	insertNodeAppon(pHead, 10104, 10105);
	printf("���ָ��λ�ò���!\n");
	scanLinkedList(pHead);

	printf("ͷɾ��...\n");
	deleteLinkedListByHead(pHead);
	printf("���ͷɾ����\n");
	scanLinkedList(pHead);

	printf("βɾ��...\n");
	deleteLinkedListByTail(pHead);
	printf("���βɾ����\n");
	scanLinkedList(pHead);

	printf("ɾ��ָ���ڵ�...\n");
	delectNodeAppon(10101);
	delectNodeAppon(10104);
	printf("���ָ���ڵ�ɾ����\n");
	scanLinkedList(pHead);

	freeLinkedList(pHead);*/
	/*****************************************�޿�ͷ������**************************************************************/



	/******************************************�п�ͷ������*******************************************************/
	
	/*initLinkedList();

	for (int i = 10101; i < 10110; i++)
	{
		addNodeByEnd(i);
		addNodeByStart(i);
	}
	printf("����pStart\n");
	scanNodeList();

	addNodeByStart(10101);
	addNodeAppon(10102,100000);

	deleteLinkedListByStart();
	deleteLinkedListByEnd();

	delectNodeByRandom(10105);

	scanNodeList();

	freeList();*/
	/*******************************************�п�ͷ������*******************************************************/





	/*******************************************�ṹ���װhead��tail ����*******************************************/


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
	printf("����plist\n");
	scanList(plist);


	for (int i = 10101; i < 10106; i++)
	{
		addListNodeByHead(plist1, i);
	}
	printf("\n\n����plist1\n");
	scanList(plist1);

	printf("ָ���ڵ㣺%p\t%d", selectListNodeAppon(plist1, 10101)->next, selectListNodeAppon(plist1, 10101)->value);
	


	printf("\n\nָ��λ�ò���ڵ�plist1\n");
	addListNodeByRandom(plist1,10105,10108);
	scanList(plist1);

	printf("�����Ƿ�Ϊ��1Ϊ�գ�0λ�ǿգ�%d",isNodeListNull(plist1));


	printf("\n\nͷɾ��plist1\n");
	deleteListByHead(plist1);
	scanList(plist1);

	printf("\n\nβɾ��plist1\n");
	deleteListByTail(plist1);
	scanList(plist1);


	printf("\n\nɾ��ָ���ڵ�plist1\n");
	delectListNodeByRandom(plist1,10103);
	scanList(plist1);

	freeNodeList(plist1);*/

	/******************************************�ṹ���װhead��tail ����*******************************************/


}





/************************************************�ṹ���װhead��tail****************************************************/

/*
�����ʼ��
*/
List* initList(PList plist)
{
	plist->tail = plist->head = (PNode)malloc(NODESIZE);//�����ͷ
	plist->head->next = NULL;

	printf("�����ʼ����ɣ�\n");

	return plist;
}


/*
β���
����2��������
*/
void addListNodeByTail(PList plist, int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//����һ���½ڵ�

	if (pNewNode == NULL)
	{
		return;
	}

	/*�ڵ��Ա��ֵ*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*����*/

	plist->tail->next = pNewNode;
	plist->tail = pNewNode;

}


/*
ͷ���
*/
void addListNodeByHead(PList plist, int value)
{

	PNode pNewNode = createNewNode(value);//����һ���½ڵ�

	if (pNewNode == NULL)
	{
		return;
	}

	/*����*/
	pNewNode->next = plist->head->next;
	plist->head->next = pNewNode;
}


/*
����ָ���ڵ�
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
����λ����ӽڵ㣬������ֵ�����
����1��plist
����2��ָ�����������ֵ
����3����Ҫ����ڵ��������
*/
void addListNodeByRandom(PList plist, int index, int value)
{
	//�����п�
	if (plist->head->next == NULL)
	{
		printf("������\n");
		return;
	}

	//�ҽڵ�
	PNode pTemp = selectListNodeAppon(plist, index);
	if (pTemp == NULL)
	{
		printf("�޴�λ�ýڵ㣡\n");
		return;
	}

	//�ҵ��ˣ����ӵ�λ��
	PNode pNewNode = createNewNode(value);//�����½ڵ�


	if (pTemp == plist->tail)//�����β���
	{
		addListNodeByTail(plist, value);
	}
	else
	{
		pNewNode->next = pTemp->next;//������
		pTemp->next = pNewNode;//��Ͽ�
	}

}


/*
�������
*/
void scanList(PList plist)
{
	PNode pNewNode = plist->head->next;//��ͷ������һ���ڵ㿪ʼ����

	while (pNewNode != NULL)
	{
		printf("%d\n", pNewNode->value);
		pNewNode = pNewNode->next;//ָ�����
	}

}


/*�����п�*/
int isNodeListNull(PList plist)
{
	//�����п�
	if (plist->head->next == NULL)
	{
		printf("������\n");
		return 1;//Ϊ��
	}

	return 0;//��Ϊ��
}



/*
ͷɾ��
*/
void deleteListByHead(PList plist)
{
	if (isNodeListNull(plist))//�����п�
	{
		return;
	}


	PNode pTemp = plist->head->next;//��¼ͷ
	plist->head->next = plist->head->next->next;//�ı�ͷ
	free(pTemp);//�ͷ�

	printf("ͷ�ڵ�ɾ����ɣ�\n");
}



/*
βɾ��
*/
void deleteListByTail(PList plist)
{
	if (isNodeListNull(plist))//�����п�
	{
		return;
	}


	if (plist->head->next == plist->tail)//��һ���ڵ�
	{
		free(plist->tail);
		plist->head->next = NULL;
		return;
	}
	else
	{
		PNode pCurrent = plist->head;//һ��ʼָ��ǰ�ڵ�

		while (pCurrent->next != NULL)//ѭ���������ҵ�β������һ���ڵ�
		{
			/*if (plist->tail == pTemp->next)
			{
				break;
			}*/

			plist->tail = pCurrent;
			pCurrent = pCurrent->next;
		}

		plist->tail->next = NULL;
		free(pCurrent);// ��ʱ��pCurrent����β���
	}

	printf("β�ڵ�ɾ����ɣ�\n");
}




/*
ɾ������ڵ�
*/
void delectListNodeByRandom(PList plist, int value)
{
	if (isNodeListNull(plist))//�����п�
	{
		return;
	}

	PNode pTemp = selectListNodeAppon(plist, value);//�ҵ�ָ���ڵ�
	if (pTemp == NULL)
	{
		printf("�޴˽ڵ㣡\n");
		return;
	}

	if (pTemp == plist->tail)//һ�����
	{
		deleteListByTail(plist);//�ͷ�β
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

		pMove->next = pTemp->next;//ɾ��
		free(pTemp);//�ͷ�
	}

	printf("����ڵ�ɾ�����!\n");
}


/*
�ͷ�����
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

	printf("�����ͷ���ɣ�\n");
}













/************************************************�п�ͷ���***********************************************************/

/*
��ͷ��ʼ��
*/
Node* initLinkedList()
{
	pStart = pEnd = (PNode)malloc(NODESIZE);//�����ͷ
	pStart->next = NULL;

	printf("�����ʼ����ɣ�\n");

	return pStart;
}




/*
�����½ڵ�
*/
Node* createNewNode(int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//����һ���½ڵ�
	
	if (pNewNode==NULL)
	{
		printf("�ڵ㴴��ʧ�ܣ�\n");
		return NULL;
	}

	/*�ڵ��Ա��ֵ*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	return pNewNode;
}

/*
β��� 
������������
*/
void addNodeByEnd(int value)
{
	PNode pNewNode = (PNode)malloc(NODESIZE);//����һ���½ڵ�

	if (pNewNode == NULL)
	{
		return;
	}

	/*�ڵ��Ա��ֵ*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*����*/
	
	pEnd->next = pNewNode;
	pEnd = pNewNode;

}



/*
ͷ���
*/
void addNodeByStart(int value)
{

	PNode pNewNode = createNewNode(value);//����һ���½ڵ�

	if (pNewNode==NULL)
	{
		return;
	}

	/*����*/
	pNewNode->next = pStart->next;
	pStart->next = pNewNode;
}


/*
����λ����ӽڵ㣬������ֵ�����
����1��ͷָ��
����2��ָ�����������ֵ
����3����Ҫ����ڵ��������
*/
void addNodeAppon(int index, int value)
{
	//�����п�
	if (pStart->next==NULL)
	{
		printf("������\n");
		return;
	}

	//�ҽڵ�
	PNode pTemp = selectNodeAppon(index);
	if (pTemp==NULL)
	{
		printf("�޴�λ�ýڵ㣡\n");
		return;
	}

	//�ҵ��ˣ����ӵ�λ��
	PNode pNewNode = createNewNode(value);//�����½ڵ�


	if (pTemp==pEnd)//�����β���
	{
		addNodeByEnd(value);
	}
	else
	{
		pNewNode->next = pTemp->next;//������
		pTemp->next = pNewNode;//��Ͽ�
	}

}




/*
�������
*/
void scanNodeList()
{
	PNode pNewNode = pStart->next;//��ͷ������һ���ڵ㿪ʼ����

	while (pNewNode!=NULL)
	{
		printf("%d\n",pNewNode->value);
		pNewNode = pNewNode->next;//ָ�����
	}

}



/*
����ָ���ڵ�
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
ͷɾ��
*/
void deleteLinkedListByStart()
{
	if (isListNull())//�����п�
	{
		return;
	}
	

	PNode pTemp = pStart->next;//��¼ͷ
	pStart->next = pStart->next->next;//�ı�ͷ
	free(pTemp);//�ͷ�

	printf("ͷ�ڵ�ɾ����ɣ�\n");
}




/*
βɾ��
*/
void deleteLinkedListByEnd()
{
	if (isListNull())//�����п�
	{
		return;
	}


	if (pStart->next==pEnd)//��һ���ڵ�
	{
		free(pEnd);
		pStart->next = NULL;
		pEnd = pStart;
	}
	else
	{
		PNode pTemp = pStart->next;

		while (pTemp != NULL)//ѭ���������ҵ�β������һ���ڵ�
		{
			if (pEnd == pTemp->next)
			{
				break;
			}

			pTemp = pTemp->next;
		}

		free(pEnd);// ��ʱ��pTemp����β���ǰһ���ڵ�
		pEnd = pTemp;//�ı���β��
		pEnd->next = NULL;//β����next����
	}

	printf("β�ڵ�ɾ����ɣ�\n");
}




/*
ɾ������ڵ�
*/
void delectNodeByRandom(int value)
{
	if (isListNull())//�����п�
	{
		return;
	}

	PNode pTemp = selectNodeAppon(value);//�ҵ�ָ���ڵ�
	if (pTemp==NULL)
	{
		printf("�޴˽ڵ㣡\n");
		return;
	}

	if (pTemp == pEnd)//һ�����
	{
		deleteLinkedListByEnd();//�ͷ�β
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

		pMove->next = pTemp->next;//ɾ��
		free(pTemp);//�ͷ�
	}

	printf("����ڵ�ɾ�����!\n");
}


/*
�ͷ�����
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

	printf("�����ͷ���ɣ�\n");
}


/*�����п�*/
int isListNull()
{
	//�����п�
	if (pStart->next == NULL)
	{
		printf("������\n");
		return 1;//Ϊ��
	}

	return 0;//��Ϊ��
}


/************************************************�޿�ͷ���***********************************************************/

/*
����һ��������ӽڵ㣩����β�巨��β���,���У�
����:������
����ֵ���˺�������һ��ָ��ֵ����ָ��һ�� Node �������ݣ�ʵ���ϴ���һ��������ʼ��ַ
*/
void addNodeByTail(int value)
{
	PNode pTemp = (PNode)malloc(NODESIZE);
	//pTemp = (Node*)malloc(sizeof(Node));

	pTemp->value = value;
	pTemp->next = NULL;

	//����
	if (pHead == NULL)
	{
		//������
		pHead = pTemp;
		pTail = pTemp;
	}
	else
	{
		pTail->next = pTemp;//����Ϊ�գ�����β���
	}

	pTail = pTemp; //ʹpTailָ�����һ����㣬���ƶ�����β

}



/*
����һ��������ӽڵ㣩����ͷ�巨��ͷ��ӣ�ջ��
����:������
����ֵ���˺�������һ��ָ��ֵ����ָ��һ�� Node �������ݣ�ʵ���ϴ���һ��������ʼ��ַ
*/
Node* addNodeByHead(int value)
{
	Node* pHead;//ͷ���
	Node* pTemp;//�ƶ�ָ��
	Node* pTail;//ָ��β

	pHead = pTail = NULL; //��ʹPHead��ֵΪNULL����ʾ����Ϊ�յ��������pHead��ָ���κν�㣬�������޽��

	pTemp = (PNode)malloc(NODESIZE);
	//pTemp = (Node*)malloc(sizeof(Node));

	pTemp->value = value;	//�ڵ����ݸ�ֵ
	pTemp->next = NULL;

	//����
	if (pHead == NULL)
	{
		//������
		pHead = pTemp;
		pTail = pTemp;
	}
	else
	{
		pTail->next = pHead;//����Ϊ�գ��½ڵ����һ��ָ��ͷ
	}

	pHead = pTemp; //�½ڵ����ͷ

	return pHead;
}


/*
�������/��ӡ
������ͷָ�룬�������ʼ��ַ
*/
void scanLinkedList()
{
	PNode pMove = pHead;						//ʹpNode1 ָ���һ�����

	//if (pHead != NULL)						//���pNode1 ָ��Ĳ���β���
	//{
	//	do
	//	{
	//		printf("%d\n", pMove->value);	//��� pNode1 ��ָ�����ֵ
	//		pMove = pMove->next;			//ʹ pNode1 ָ����һ�����
	//	} while (pMove != NULL);			//��pNode1ָ���βʱ������ѭ��
	//}

	if (pHead != NULL)
	{
		while (pMove)
		{
			printf("%d\n", pMove->value);	//��� pNode1 ��ָ�����ֵ
			pMove = pMove->next;			//ʹ pNode1 ָ����һ�����
		}
	}
}


/*
�����ѯ/��
����1��ͷָ�룬�������ʼ��ַ
����2����ѯ����ֵ
����ֵ�����ؽڵ�ָ��
*/
Node* selectNode(int index)
{
	PNode pMove = pHead;			//ʹpMove ָ���һ�����

	if (pHead != NULL)
	{
		while (pMove != NULL)
		{
			if (pMove->value == index)//����ҵ��ˣ�����
			{
				return pMove;
			}

			pMove = pMove->next;//���û�ҵ���ָ�����
		}

		return NULL;//������ϣ�û�ҵ�����NULL
	}
}


/*
�������
����1��ͷָ��
*/
void freeLinkedList()
{

	PNode pMove = pHead;//��¼ͷ����ֹͷ���޸ģ����ڵ�

	while (pMove != NULL)
	{
		PNode pTemp = pMove;
		pMove = pMove->next;
		free(pTemp);
	}

	/*ͷβ���*/
	pHead = NULL;
	pTail = NULL;
}



/*
��ָ��λ�ò���ڵ�
����1��ͷָ��
����2������λ��
����3��������
*/
void insertNodeAppon(int pos, int value)
{
	if (pHead == NULL)//����Ϊ��
	{
		printf("������");
		return;
	}

	PNode pSearch = selectNode(pos);//�ҵ��ڵ�λ�ã������ؽڵ�ָ��
	if (pSearch == NULL)
	{
		printf("û���ҵ�ָ��λ�ã�\n");
		return;
	}

	PNode pNewNode = (PNode)malloc(NODESIZE);//��ǰ�����д�λ�ã�����һ���½ڵ�

	/*�ڵ��Ա��ֵ*/
	pNewNode->value = value;
	pNewNode->next = NULL;

	/*���ڵ����ӵ�������*/
	if (pSearch = pTail)//��������λ���ڱ�β
	{
		pTail->next = pNewNode;//β�ڵ�nextָ���½ڵ�
		pTail = pNewNode;      //���½ڵ������һ���ڵ㣬��ɱ�β�ڵ�
	}
	else
	{
		pNewNode->next = pSearch->next;//�½ڵ��nextָ��ָ��λ�ýڵ����һ���ڵ�
		pSearch->next = pNewNode;      //ָ��λ�ýڵ��nextָ���½ڵ�
	}
}


/*
ͷɾ������ջ��ͷ���+ͷɾ����
*/
void deleteLinkedListByHead()
{
	if (pHead == NULL)
	{
		printf("������");
		return;
	}

	PNode pTemp = pHead;//�ȼ�ס�ɵ�ͷָ��
	pHead = pHead->next;//ͷ����һ���ڵ����µ�ͷ
	free(pTemp);
}


/*
βɾ���������У�ͷ���+βɾ��/β���+ͷɾ����
*/
void deleteLinkedListByTail()
{
	if (pHead == NULL)
	{
		printf("������");
		return;
	}

	if (pHead == pTail)//ͷβָ�����ͬһ����˵��ֻ��һ���ڵ�
	{
		free(pTail);
		pHead = NULL;
		pTail = NULL;
	}
	else            //����ڵ�
	{
		PNode pMove = pHead;

		/*���������ҵ�β�ڵ��ǰһ���ڵ�*/
		while (pMove->next != pTail)
		{
			pMove = pMove->next;
		}

		free(pTail);//�ͷ�β�ڵ�
		pTail = pMove;
		pTail->next = NULL;
	}
}


/*
ɾ��ָ���ڵ�
������������
*/
void delectNodeAppon(int value)
{
	if (pHead == NULL)
	{
		printf("������");
		return;
	}

	PNode pTemp = selectNode(value);
	if (pTemp == NULL)
	{
		printf("�޴˽ڵ㣡");
		return;
	}

	/*ֻ��һ���ڵ�*/
	if (pHead == pTail)
	{
		free(pTail);
		pHead = NULL;
		pTail = NULL;
	}
	/*��2���ڵ�*/
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
	/*�ж���ڵ�*/
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
		else//ɾ���м�ڵ�
		{
			PNode pMove = pHead;

			/*���������ҵ�ָ���ڵ��ǰһ���ڵ�*/
			while (pMove->next != pTemp)
			{
				pMove = pMove->next;
			}

			pMove->next = pTemp->next;
			free(pTemp);//�ͷ�β�ڵ�
		}
	}
}





/******************************************************̷��ǿC**********************************************************/
/*��̬����*/
void staticLinkedList()
{
	Node nodeA, nodeB, nodeC;			// ���������ṹ��node����
	PNode pHead, pNext;					// Node*

	nodeA.value = 10101;
	nodeB.value = 10102;
	nodeC.value = 10103;				//�Խ���value��ֵ

	pHead = &nodeA;						//���ڵ�nodeA����ʼ��ַ��ֵ��ͷָ��pHead��pHeadֻ��ָ����û����Ϣ��
	nodeA.next = &nodeB;				//���ڵ�nodeB����ʼ��ַ��ֵ��nodeA����next��Ա
	nodeB.next = &nodeC;				//���ڵ�nodeC����ʼ��ַ��ֵ��nodeB����next��Ա
	nodeC.next = NULL;					//ʹ�ڵ�nodeC��next��Ա������κ���������ַ������β
	pNext = pHead;						//ʹpNextָ��ָ��nodeA��㣬pNextָ��������ǲ���ָ�������е���һ����㣬���ڱ����������

	// �������
	do
	{
		printf("%d\n", pNext->value);	//���pNextָ���������
		pNext = pNext->next;			//ʹpNextָ����һ���
	} while (pNext != NULL);			//��������������һ��������ݺ�pNext��ֵΪNULL
}



/*����һ������̬�����˺�������һ��ָ��ֵ����ָ��һ�� Node �������ݣ�ʵ���ϴ���һ��������ʼ��ַ*/
Node* createLinkedList()
{
	PNode pHead, pNode1, pNode2;


	printf("����һ���������������valueֵ������0��ʾ�����ʼ��������\n");
	pNode1 = pNode2 = (PNode)malloc(NODESIZE);	//����һ���µ�Ԫ
	pHead = NULL;	 							//��ʹPHead��ֵΪNULL����ʾ����Ϊ�յ��������pHead��ָ���κν�㣬�������޽��

	scanf("%d", &pNode1->value);				//����һ��valueֵ
	while (pNode1->value != 0)					//Լ�� value ��ֵ��Ϊ0��������Ϊ0���ʾ��������Ĺ������
	{
		nodeCnt = nodeCnt + 1;					//��������pNode1->value������0����������ǵ�һ���������,��ʱ���������1

		if (nodeCnt == 1)						//����ǵ�һ����㣬
		{
			pHead = pNode1;						//ʹpHeadҲָ���¿��ٵĽ�㣬pNode1��ָ����¿��ٵĽ��ͳ�Ϊ�����е�һ�����
		}
		else                                    //nodeCnt��=1�����ǵ�һ���
		{
			pNode2->next = pNode1;				//��ʱpNode2 ָ���һ����㣨���ǰ�pNode1��ָ�Ľ�����ӵ�pNode2��ָ���ĺ��棩��
			                                    //�����½ڵ�ĵ�ַ��ֵ����һ��next��Ա��ʹ��һ������next��Աָ��ڶ������
		}

		pNode2 = pNode1;						//ʹpNode2ָ�����һ����㣬���ƶ�����β
		pNode1 = (PNode)malloc(NODESIZE);		//�ٿ���һ���½�㣨��Ԫ����ʹpNode1ָ����
		scanf("%d", &pNode1->value);			//��������������
	}

	pNode2->next = NULL;						//����pNode1->value ��ֵΪ0������ִ��ѭ�����˽�㲻Ӧ�����ӵ������У���ʱ����β����ָ�������NULL

	if (nodeCnt != 0)
	{
		printf("��ʼ���˽�����Ϊ %d �ĵ�������\n", nodeCnt);
	}
	else
	{
		printf("��ʼ����һ��������\n");
	}

	printf("��ǰ������������%d\n", nodeCnt);
	return pHead;								//����createNode�����󣬺�����ֵ������������ĵ�һ�����ĵ�ַ���������ͷ��ַ
}



/*
�������
������Node*����ʵ�δ��������������е������ͷָ�봫�������õĺ���
��printNodeList�����д�head��ָ�ĵ�һ��������˳������������
*/
void printLinkedList(PNode pHead)
{
	PNode pNode1;

	printf("����%d����¼���£�\n", nodeCnt);

	pNode1 = pHead;							//ʹpNode1 ָ���һ�����
	if (pHead != NULL)						//���pNode1 ָ��Ĳ���β���
	{
		do
		{
			printf("%d\n", pNode1->value);	//��� pNode1 ��ָ�����ֵ
			pNode1 = pNode1->next;			//ʹ pNode1 ָ����һ�����
		} while (pNode1 != NULL);			//��pNode1ָ���βʱ������ѭ��
	}

	printf("��ǰ������������%d\n", nodeCnt);
}





/*
�������ɾ������
����1��Node* ���ͣ��������ͷָ��
����2����������������߱�ʶ������ѧ�ŵ�
����ֵ������һ���������ͷָ��
*/
Node* removeNode(PNode pHead, long index)
{
	PNode pNode1, pNode2;

	if (pHead == NULL)										//�ձ�����
	{
		printf("�ձ�!\n");
	}

	pNode2 = pNode1 = pHead;

	while (index != pNode1->value && pNode1->next != NULL)	//pNode1 ָ��Ĳ�����Ҫ�ҵĽ�㣬���Һ��滹���������
	{
		pNode2 = pNode1;
		pNode1 = pNode1->next;								//pNode1 ����һ�����
	}

	if (index == pNode1->value)								//������Ҫ�ɵ����Ǹ����
	{
		if (pNode1 == pHead)									//��pNode1 ָ�����ͷ��㣬
		{
			pHead = pNode1->next;							//�ѵڶ������ĵ�ַ����pHead,ɾ��ͷ���
		}
		else
		{
			pNode2->next = pNode1->next;					//������һ����ַ����ǰһ����ַ����ɾ��һ�����
		}

		printf("remove Node: %ld\n", index);					//�Ƴ�Ŀ����
		nodeCnt = nodeCnt - 1;								//�������-1
	}
	else
	{
		printf("�޷��ҵ�����Ϊ��%ld�Ľ��", index);				//Ŀ���㲻����
	}

	printf("��ǰ������������%d\n", nodeCnt);
	return pHead;
}


/*
������Ĳ������
����1���Ѵ��ڵ�����ͷָ��
����2����Ҫ�Ĳ�����½��
*/
Node* insertNode(PNode pHead, PNode newNode)
{
	PNode pNode0, pNode1, pNode2;

	pNode2 = pNode1 = pHead;			//ʹpNode1 ָ���һ�����
	pNode0 = newNode;					//ʹpNode0 ָ��Ҫ������½��

	if (pHead == NULL)					//�������ڵ������ǿ�����
	{
		pHead = pNode0;					//ʹpNode0 ָ��Ľ�㣨newNode����Ϊͷ���
		pNode0->next = NULL;			//��β�ÿ�
		printf("����ͷ��㣺%ld\n", newNode->value);
	}
	else
	{
		while ((pNode0->value > pNode1->value) && (pNode1->next != NULL))//pNode0->value > pNode1->value �� pNode1 ��ָ�Ĳ��Ǳ�β���
		{
			pNode2 = pNode1;			//ʹpNode2 ָ��ղ�pNode1ָ��Ľ��
			pNode1 = pNode1->next;		//pNode1 ����һ�����
		}

		if (pNode0->value <= pNode1->value)
		{
			if (pHead == pNode1)			//��pNode1 ָ�����ͷ���
			{
				pHead = pNode0;			//���뵽��ͷ֮ǰ
				printf("����ͷ��㣺%ld\n", newNode->value);
			}
			else
			{
				pNode2->next = pNode0;	//��pNode1 ָ��Ĳ���ͷ��㣬���뵽pNode2ָ��Ľ��֮�󣨼����뵽�м䣩
				printf("�����м��㣺%ld\n", newNode->value);
			}

			pNode0->next = pNode1;
		}
		else
		{
			pNode1->next = pNode0;
			pNode0->next = NULL;		//���뵽���Ľ�㣨��β��֮��
			printf("����β��㣺%ld\n", newNode->value);
		}
	}

	nodeCnt++;							//���������1
	printf("��ǰ������������%d\n", nodeCnt);

	return pHead;
}

