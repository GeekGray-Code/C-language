#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include "chapter11_structure.h"




/*chapter11 结构体共用体 测试函数*/
void chapter11StructureTest()
{
	/*代码示例*/
	//structureTest();
	//structureNested();
	//structureAsParameter();
	//unionTest();


	/*课后练习*/
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


/************************************课后习题begin******************************************************/

/*
从键盘输入10个学生的数据，要求输出3门课程总平均成绩，以及最高分的学生的数据（包括学号，姓名，3门课程成绩，平均分数）
*/
void printStuInfo1()
{
	int maxIndex=0;//最高分数的索引
	float sum=0;//总分
	float max=0;//最高分
	float avgScore=0;//平均分
	Student stuArr[STULEN];//学生数组

	//输入数据
	for (int i = 0; i < STULEN; i++)
	{
		printf("请输入第%d个学生的信息：\n", i + 1);

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

	//计算
	for (int i = 0; i < STULEN; i++)
	{
		sum = 0;

		for (int j = 0; j < 3; j++)
		{
			sum += stuArr[i].score[j];//计算第i个学生的总分

		}

		stuArr[i].avgScore = sum / 3.0;//计算第i个学生的平均分
		avgScore += stuArr[i].avgScore;//计算平均分总数

		//计算总分最高分
		if (sum>max)
		{
			max = sum;
			maxIndex = i;//将该学生的下标保存
		}
	}

	avgScore = avgScore/STULEN;//计算平均分的平均分


	//输出
	printStuInfo(stuArr);

	printf("\n总平均分：%f\n",avgScore);
	printf("最高分学生信息：\n");
	printf("\n stuId\tstuName\tscore1\tscore2\tscore3\tavgScore\n");
	printf("\n %s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", stuArr[maxIndex].stuID, stuArr[maxIndex].stuName, stuArr[maxIndex].score[0], stuArr[maxIndex].score[1], stuArr[maxIndex].score[2], stuArr[maxIndex].avgScore);
}






/*
输出一个学生成绩的数组，该数组中含5个学生记录
每个记录包含stuId，stuName，score[3]
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
		printf("请输入第%d个学生的信息：\n",i+1);

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
定义一个结构体变量（包括年月日），计算该日在本年中是第几天，注意闰年问题
*/
void calcDaysByStruct()
{
	Date date;
	int days=0;
	int dayTab[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	printf("请输入年月日，格式（年.月.日）：\n");
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



/************************************课后习题end********************************************************/





/***********************************代码示例begin*******************************************************/
/*访问结构体变量*/
void structureTest()
{
	struct Book book;

	book.title = "《C primer plus》";
	book.author = "xxx";
	book.price = 48.8;
	book.date = 20191221;
	book.publisher = "清华大学出版社";
	
	printf("title：%s\n",book.title);
	printf("author：%s\n", book.author);
	printf("title：%f\n", book.price);
	printf("date：%u\n", book.date);
	printf("publisher：%s\n", book.publisher);

	/*内存对齐*/
	printf("sizeof(book)：%d\n", sizeof(book));
}


/*结构体嵌套*/
void structureNested()
{
	struct Book1 book;

	book.title = "《C primer plus》";
	book.author = "xxx";
	book.price = 48.8;
	book.date.year = 2019;
	book.date.month = 12;
	book.date.day = 21;
	book.publisher = "清华大学出版社";

	printf("title：%s\n", book.title);
	printf("author：%s\n", book.author);
	printf("title：%f\n", book.price);
	printf("date: %d-%d-%d\n", book.date.year,book.date.month,book.date.day);
	printf("publisher：%s\n", book.publisher);
}

/*结构体数组*/
void structureArray()
{
	struct Book1 book[3] = 
	{
		{ "《C primer plus》", "author", 48.8, {2019,12,21},"清华大学出版社" },
		{ "《C primer plus》", "author", 48.8, { 2019, 12, 21 }, "清华大学出版社" },
		{ "《C primer plus》", "author", 48.8, { 2019, 12, 21 }, "清华大学出版社" }
	};
	
}


/*结构体指针*/
void structurePointer()
{
	struct Book1 book;
	struct Book1 *pb;		// 声明结构体指针

	pb = &book;				// 结构体指针赋值

	// 访问结构体成员
	pb->author = "author";	// 指针访问
	(*pb).price = 48.8;		// 解引用访问
}


/*结构体变量作为参数传递以及返回值*/
void getInput(struct Book1 *book);
void printBook(struct Book1 *book);

void structureAsParameter()
{
	struct Book1 book1, book2;

	getInput(&book1);
	printBook(&book1);
}

/*结构体赋值*/
void getInput(struct Book1 *book)
{
	book->title = "《C primer plus》";
	book->author = "author";
	book->price = 48.8;
	book->date.year = 2019;
	book->date.month = 12;
	book->date.day = 21;
	book->publisher = "清华大学出版社";

}

/*打印*/
void printBook(struct Book1 *book)
{
	printf("title：%s\n", book->title);
	printf("author：%s\n", book->author);
	printf("title：%f\n", book->price);
	printf("date: %d-%d-%d\n", book->date.year, book->date.month, book->date.day);
	printf("publisher：%s\n", book->publisher);
}


/*动态申请结构体*/
void mallocStructure()
{
	struct Book1 *b1, *b2;

	b1 = (struct Book1 *)malloc(sizeof(struct Book1));
	b2 = (struct Book1 *)malloc(sizeof(struct Book1));

	if (b1 == NULL || b2 == NULL)
	{
		printf("内存分配失败\n");
		exit(1);
	}
}


/*共用体
  共用体的所有成员共享一个内存地址
  人格分裂，不会同时出现，不断切换
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

	// 地址是一样的
	printf("addr of test.i: %p\n",&test.i);
	printf("addr of test.pi: %p\n", &test.pi);
	printf("addr of test.str: %p\n", &test.str);

	//只有最有一个值是正确的，覆盖
	printf("value of test.i: %d\n", test.i);
	printf("value of test.pi: %f\n", test.pi);
	printf("value of test.str: %s\n", test.str);

	// 用sizeof求一下大小,应该等于最大成员尺寸，内存对齐就不一定等于最大成员尺寸
	printf("sizeof(test): %d",sizeof(test));
}


/*初始化共用体*/
void initUnion()
{
	
	union Test test = { 520 };			// 初始化第一个成员
	union Test test1=test;				// 用一个共用体初始化另一个共用体
	union Test test2 = { .i = 520 };	// c99新增特性，指定初始化成员

}