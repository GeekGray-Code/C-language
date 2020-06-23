#ifndef _CHAPTER11_STRUCTURE_H
#define _CHAPTER11_STRUCTURE_H 

#define STULEN 5


/*����ṹ��*/
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

/*����ʾ��*/
void chapter11StructureTest();		//
void structureTest();				//���ʽṹ�����
void structureNested();				//�ṹ��Ƕ��
void structureAsParameter();		//�ṹ�������Ϊ���������Լ�����ֵ
void unionTest();					//������
void printBook(struct Book1 *book);	// ��ӡ�ṹ����Ϣ


/*�κ�ϰ��*/
void calcDaysByStruct();//
void printStuInfoTest();//
void printStuInfo(Student* stuArr);//
void printStuInfo1();//



#endif