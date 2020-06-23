#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include "chapter11_structure.h"




/*chapter11 �ṹ�干���� ���Ժ���*/
void chapter11StructureTest()
{
	/*����ʾ��*/
	//structureTest();
	//structureNested();
	//structureAsParameter();
	//unionTest();


	/*�κ���ϰ*/
	//calcDaysByStruct();
	//printStuInfoTest();
	//printStuInfo1();

	//test();
}



/****************************************************test************************************************/
void test()
{
	Student stu[2];

	//scanf("%s", stu[0].stuID);
	scanf("%s,%s,%f,%f,%f", stu[0].stuID, stu[0].stuName, &stu[0].score[0], &stu[0].score[1], &stu[0].score[2]);

	printTest(stu);
}

void printTest(Student stu[STULEN])
{
	printf("\nstuId\tstuName\tscore1\tscore2\tscore3\tavgScore\n");

	for (int i = 0; i < 1; i++)
	{
		printf("%s,%s,%f,%f,%f", stu[i].stuID, stu[i].stuName, stu[i].score[0], stu[i].score[1], stu[i].score[2]);

		printf("\n");
	}
}


/************************************�κ�ϰ��begin******************************************************/

/*
�Ӽ�������10��ѧ�������ݣ�Ҫ�����3�ſγ���ƽ���ɼ����Լ���߷ֵ�ѧ�������ݣ�����ѧ�ţ�������3�ſγ̳ɼ���ƽ��������
*/
void printStuInfo1()
{
	int maxIndex=0;//��߷���������
	float sum=0;//�ܷ�
	float max=0;//��߷�
	float avgScore=0;//ƽ����
	Student stuArr[STULEN];//ѧ������

	//��������
	for (int i = 0; i < STULEN; i++)
	{
		printf("�������%d��ѧ������Ϣ��\n", i + 1);

		printf("stuId:");
		scanf("%s", stuArr[i].stuID);

		printf("stuName:");
		scanf("%s", stuArr[i].stuName);

		for (int j = 0; j < 3; j++)
		{
			printf("Score%d:", j + 1);
			scanf("%f", &stuArr[i].score[j]);
		}

		printf("\n");
	}

	//����
	for (int i = 0; i < STULEN; i++)
	{
		sum = 0;

		for (int j = 0; j < 3; j++)
		{
			sum += stuArr[i].score[j];//�����i��ѧ�����ܷ�

		}

		stuArr[i].avgScore = sum / 3.0;//�����i��ѧ����ƽ����
		avgScore += stuArr[i].avgScore;//����ƽ��������

		//�����ܷ���߷�
		if (sum>max)
		{
			max = sum;
			maxIndex = i;//����ѧ�����±걣��
		}
	}

	avgScore = avgScore/STULEN;//����ƽ���ֵ�ƽ����


	//���
	printStuInfo(stuArr);

	printf("\n��ƽ���֣�%f\n",avgScore);
	printf("��߷�ѧ����Ϣ��\n");
	printf("\n stuId\tstuName\tscore1\tscore2\tscore3\tavgScore\n");
	printf("\n %s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", stuArr[maxIndex].stuID, stuArr[maxIndex].stuName, stuArr[maxIndex].score[0], stuArr[maxIndex].score[1], stuArr[maxIndex].score[2], stuArr[maxIndex].avgScore);
}






/*
���һ��ѧ���ɼ������飬�������к�5��ѧ����¼
ÿ����¼����stuId��stuName��score[3]
*/
void printStuInfo(Student* stuArr )
{
	printf("\nstuId\tstuName\tscore1\tscore2\tscore3\tavgScore\n");

	for (int i = 0; i < STULEN; i++)
	{
		printf("%s\t%s\t", stuArr[i].stuID, stuArr[i].stuName);
		for (int j = 0; j < 3; j++)
		{
			printf("%.2f\t", stuArr[i].score[j]);
		}

		printf("%.2f\t", stuArr[i].avgScore);

		printf("\n");
	}
}

void printStuInfoTest()
{
	Student stuArr[5];
	PStu pstu = &stuArr;

	for (int i = 0; i < STULEN; i++)
	{
		printf("�������%d��ѧ������Ϣ��\n",i+1);

		printf("stuId:");
		scanf("%s",stuArr[i].stuID);

		printf("stuName:");
		scanf("%s", stuArr[i].stuName);

		for (int j = 0; j < 3; j++)
		{
			printf("Score%d:",j+1);
			scanf("%f", &stuArr[i].score[j]);
		}

		printf("\n");
	}

	printStuInfo(stuArr);
}




/*
����һ���ṹ����������������գ�����������ڱ������ǵڼ��죬ע����������
*/
void calcDaysByStruct()
{
	Date date;
	int days=0;
	int dayTab[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	printf("�����������գ���ʽ����.��.�գ���\n");
	scanf("%d.%d.%d",&date.year,&date.month,&date.day);

	for (int i = 0; i < date.month; i++)
	{
		days = days + dayTab[i];
	}

	days = days + date.day;

	if ((date.year%4==0 && date.year%100!=0 || date.year%400==0) && date.month>=3)
	{
		days += 1;
	}

	printf("%d.%d.%d is the %dth day in %d.\n", date.year, date.month, date.day, days, date.year);
}



/************************************�κ�ϰ��end********************************************************/





/***********************************����ʾ��begin*******************************************************/
/*���ʽṹ�����*/
void structureTest()
{
	struct Book book;

	book.title = "��C primer plus��";
	book.author = "xxx";
	book.price = 48.8;
	book.date = 20191221;
	book.publisher = "�廪��ѧ������";
	
	printf("title��%s\n",book.title);
	printf("author��%s\n", book.author);
	printf("title��%f\n", book.price);
	printf("date��%u\n", book.date);
	printf("publisher��%s\n", book.publisher);

	/*�ڴ����*/
	printf("sizeof(book)��%d\n", sizeof(book));
}


/*�ṹ��Ƕ��*/
void structureNested()
{
	struct Book1 book;

	book.title = "��C primer plus��";
	book.author = "xxx";
	book.price = 48.8;
	book.date.year = 2019;
	book.date.month = 12;
	book.date.day = 21;
	book.publisher = "�廪��ѧ������";

	printf("title��%s\n", book.title);
	printf("author��%s\n", book.author);
	printf("title��%f\n", book.price);
	printf("date: %d-%d-%d\n", book.date.year,book.date.month,book.date.day);
	printf("publisher��%s\n", book.publisher);
}

/*�ṹ������*/
void structureArray()
{
	struct Book1 book[3] = 
	{
		{ "��C primer plus��", "author", 48.8, {2019,12,21},"�廪��ѧ������" },
		{ "��C primer plus��", "author", 48.8, { 2019, 12, 21 }, "�廪��ѧ������" },
		{ "��C primer plus��", "author", 48.8, { 2019, 12, 21 }, "�廪��ѧ������" }
	};
	
}


/*�ṹ��ָ��*/
void structurePointer()
{
	struct Book1 book;
	struct Book1 *pb;		// �����ṹ��ָ��

	pb = &book;				// �ṹ��ָ�븳ֵ

	// ���ʽṹ���Ա
	pb->author = "author";	// ָ�����
	(*pb).price = 48.8;		// �����÷���
}


/*�ṹ�������Ϊ���������Լ�����ֵ*/
void getInput(struct Book1 *book);
void printBook(struct Book1 *book);

void structureAsParameter()
{
	struct Book1 book1, book2;

	getInput(&book1);
	printBook(&book1);
}

/*�ṹ�帳ֵ*/
void getInput(struct Book1 *book)
{
	book->title = "��C primer plus��";
	book->author = "author";
	book->price = 48.8;
	book->date.year = 2019;
	book->date.month = 12;
	book->date.day = 21;
	book->publisher = "�廪��ѧ������";

}

/*��ӡ*/
void printBook(struct Book1 *book)
{
	printf("title��%s\n", book->title);
	printf("author��%s\n", book->author);
	printf("title��%f\n", book->price);
	printf("date: %d-%d-%d\n", book->date.year, book->date.month, book->date.day);
	printf("publisher��%s\n", book->publisher);
}


/*��̬����ṹ��*/
void mallocStructure()
{
	struct Book1 *b1, *b2;

	b1 = (struct Book1 *)malloc(sizeof(struct Book1));
	b2 = (struct Book1 *)malloc(sizeof(struct Book1));

	if (b1 == NULL || b2 == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
}


/*������
  ����������г�Ա����һ���ڴ��ַ
  �˸���ѣ�����ͬʱ���֣������л�
*/

union Test
{
	int i;
	double pi;
	char*str;
};

void unionTest()
{
	union Test test;

	test.i = 520;
	test.pi = 3.14;
	test.str = "unionTest";
	//strcpy_s(test.str,"unionTest");

	// ��ַ��һ����
	printf("addr of test.i: %p\n",&test.i);
	printf("addr of test.pi: %p\n", &test.pi);
	printf("addr of test.str: %p\n", &test.str);

	//ֻ������һ��ֵ����ȷ�ģ�����
	printf("value of test.i: %d\n", test.i);
	printf("value of test.pi: %f\n", test.pi);
	printf("value of test.str: %s\n", test.str);

	// ��sizeof��һ�´�С,Ӧ�õ�������Ա�ߴ磬�ڴ����Ͳ�һ����������Ա�ߴ�
	printf("sizeof(test): %d",sizeof(test));
}


/*��ʼ��������*/
void initUnion()
{
	
	union Test test = { 520 };			// ��ʼ����һ����Ա
	union Test test1=test;				// ��һ���������ʼ����һ��������
	union Test test2 = { .i = 520 };	// c99�������ԣ�ָ����ʼ����Ա

}