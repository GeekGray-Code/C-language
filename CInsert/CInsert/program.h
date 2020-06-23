#ifndef _PROGRAM_H
#define _PROGRAM_H 

#define STUCOUNT 20	





void programTest();/*编程题 测试函数*/
void codeNoDuplicationThreeDigitsBy1234();	//无重复数字的三位数
void codeFactorial();						//计算阶乘表达式:y=(m!)/(n!)(m-n!)
void codeSequenceSum();						/*求1+1/2+1/4+...+1/50的值，并输出结果*/
void codeStatisticalStudentGrade();			/*从键盘输入20个学生的学号和一门课程成绩，统计计算全班平均成绩，并输出低于平均分的学生学号和成绩*/
void codeDivisible7();						/*韩师 2014-5-1：从键盘输入10个整数，找出第一个能被7整除的数，若找到，打印此数后退出循环：若未找到，打印not exist*/
void codeMaximumAndMinimumOf10Numbers();	/*韩师 2014-5-1：从键盘输入10个整数，求这10个数中的最大值与最小值并输出*/
void codeFormatPrint();						/*韩师-2013-5-1：把从键盘输入的数字按下列对应关系显示*/
void codeSequenceSumForPrac();				/*韩师-2013-5-2：求1+2+3+4+...+n 的值，并输出结果，其中n由用户输入*/
void codeCourseScore();						/*韩师-2010-5-2：有一个班级5位学生，各学4门课程，查找出有一门以上课程不及格的学生，打印出其全部课程的成绩*/
void codeCompareIntegerByPointer();			/*广技师2017-5-1：用指针完成，输入两个整数，按先大后小的顺序输出*/
void codeMyStrcat();						/*广技师2017-5-2：编程完成两个字符串的连接（不使用strcat（）函数）*/
void codeCalcPolynomialValue();				/*计算1-1、2+1/3-1/4+...+1/99-1/100+...，直到最后一项的绝对值小于1e-4为止*/


#endif