#ifndef _CHAPTER11_STRUCTURE_H
#define _CHAPTER11_STRUCTURE_H 

#define STULEN 5


/*定义结构体*/
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

struct Book
{
	char *title;
	char *author;
	float price;
	unsigned int date;
	char *publisher;
};

struct Book1
{
	char *title;
	char *author;
	float price;
	struct Date date;
	char *publisher;
};


typedef struct Student
{
	char stuID[6];
	char stuName[20];
	float score[4];
	float avgScore;
}Student,*PStu;
/****************************************************************************************************/




void test();
void printTest(Student stu[STULEN]);

/*代码示例*/
void chapter11StructureTest();		//
void structureTest();				//访问结构体变量
void structureNested();				//结构体嵌套
void structureAsParameter();		//结构体变量作为参数传递以及返回值
void unionTest();					//共用体
void printBook(struct Book1 *book);	// 打印结构体信息


/*课后习题*/
void calcDaysByStruct();//
void printStuInfoTest();//
void printStuInfo(Student* stuArr);//
void printStuInfo1();//



#endif