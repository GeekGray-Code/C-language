#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"chapter13_file_operation.h"

struct Date
{
	int year;
	int month;
	int day;
};

struct Book2
{
	char *title;
	char *author;
	float price;
	struct Date date;
	char *publisher;
};


struct Student
{
	char name[20];
	int num;
	float score;
}stuArr[NUM],stu;


/*chapter13 文件操作 测试函数*/
void chapter13FileOperationTest()
{
	//fileSwitch();
	//fileReadAndWrite();
	//fileReadString();
	//fileFormatReadAndWrite();
	//fileBinaryFilesReadAndWrite();
	//fileRandomReadAndWrite();
	//fileRandomReadAndWriteStudent();

}

/*打开和关闭文件*/
void fileSwitch()
{
	FILE *fp;
	int ch;

	if ((fp = fopen("./TestData/hello.txt", "r")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	// 读取文件内容
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}

	fclose(fp);
}


/*文件读写*/
void fileReadAndWrite()
{
	FILE *fp;
	FILE *fp1;
	int ch;

	if ((fp = fopen("./TestData/hello.txt", "r")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}
	if ((fp1 = fopen("./TestData/hello1.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	// 读写文件内容
	while ((ch = getc(fp)) != EOF)
	{
		fputc(ch,fp1);
	}

	if ((fp1 = fopen("./TestData/hello1.txt", "r"))  !=NULL)
	{
		printf("文件写入成功！\n");
	}

	fclose(fp);
    fclose(fp1);
}


/*从指定文件中读取字符串*/
void fileReadString()
{
	FILE *fp;
	FILE *fp1;
	int ch;

	if ((fp = fopen("./TestData/lines.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fputs("line one: hello world\n",fp);
	fputs("line two: hello world2\n", fp);
	fputs("line three: hello world3\n", fp);	//会打印2行同样的

	fclose(fp);

	if ((fp = fopen("./TestData/lines.txt", "r")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	char buffer[MAX];
	while (!feof(fp))
	{
		fgets(buffer,MAX,fp);
		printf("%s\n",buffer);
	}

	fclose(fp);
}


/*格式化读写*/
void fileFormatReadAndWrite()
{
	FILE * fp;
	struct tm *pt;
	time_t t;

	time(&pt);
	pt = localtime(&pt);
	
	if ((fp = fopen("./TestData/date.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp,"%d-%d-%d",1900+pt->tm_year,1+pt->tm_mon,pt->tm_mday);

	fclose(fp);

	int year, month, day;

	if ((fp = fopen("./TestData/date.txt", "r")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp,"%d-%d-%d",&year,&month,&day);
	printf("%d-%d-%d", year, month, day);

	fclose(fp);
}

void printBook2(struct Book2 * book);
/*二进制文件读写*/
void fileBinaryFilesReadAndWrite()
{
	FILE * fp;
	struct Book2 *bookForWrite,*bookForRead;

	bookForWrite = (struct Book2 *)malloc(sizeof(struct Book2));
	bookForRead = (struct Book2 *)malloc(sizeof(struct Book2));

	bookForWrite->title = "《C prime Plus》";
	bookForWrite->author = "author";
	bookForWrite->publisher = "清华大学出版社";
	bookForWrite->price = 19.8;
	bookForWrite->date.year = 2019;
	bookForWrite->date.month = 12;
	bookForWrite->date.day = 21;
	
	
	if ((fp = fopen("./TestData/binary.txt", "wb+")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fwrite(bookForWrite, sizeof(struct Book2), 1, fp);
	fclose(fp);

	if ((fp = fopen("./TestData/binary.txt", "r")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fread(bookForWrite, sizeof(struct Book2), 1, fp);
	fclose(fp);

	printBook2(bookForRead);
	

}

/*打印*/
void printBook2(struct Book2 * book)
{
	printf("title：%s\n", book->title);
	printf("author：%s\n", book->author);
	printf("title：%f\n", book->price);
	printf("date: %d-%d-%d\n", book->date.year, book->date.month, book->date.day);
	printf("publisher：%s\n", book->publisher);
}


/*随机读写*/
void fileRandomReadAndWrite()
{
	FILE *fp;

	if ((fp = fopen("./TestData/hello.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	printf("%ld\n",ftell(fp));	//0
	fputc('F',fp);
	printf("%ld\n", ftell(fp));	//1
	fputs("ishC.com\n", fp);	
	printf("%ld\n", ftell(fp));//11

	rewind(fp);
	fputs("\n", fp);
	printf("%ld\n", ftell(fp));//2

	rewind(fp);
	fputs("baidu.com", fp);
	printf("%ld\n", ftell(fp));//9

	printf("sizeof(fp): %d\n", sizeof(fp));

	fclose(fp);
}


/*随机读写结构体*/
void fileRandomReadAndWriteStudent()
{
	FILE *fp;
	int i;

	if ((fp = fopen("./TestData/score.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}


	printf("请开始录入成绩（格式：姓名 学号 成绩）\n");
	for ( i = 0; i < NUM; i++)
	{
		scanf("%s %d %f", stuArr[i].name, &stuArr[i].num, &stuArr[i].score);
	}

	/*stuArr[0].name = "lihua";
	stuArr[0].num = 1;
	stuArr[0].score = 90;
	stuArr[1].name = "lihua1";
	stuArr[1].num = 2;
	stuArr[1].score = 90.2;
	stuArr[2].name = "lihua2";
	stuArr[2].num = 3;
	stuArr[2].score = 98.5;
	stuArr[3].name = "lihua3";
	stuArr[3].num = 4;
	stuArr[3].score = 100;*/


	fwrite(stuArr, sizeof(struct Student), NUM, fp);
	fclose(fp);

	if ((fp = fopen("./TestData/score.txt", "rb")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(EXIT_FAILURE);
	}

	fseek(fp,sizeof(struct Student),SEEK_SET);
	fread(&stu, sizeof(struct Student), 1, fp);
	printf("%s(%d)的成绩是： %.2f\n",stu.name,stu.num,stu.score);
}
