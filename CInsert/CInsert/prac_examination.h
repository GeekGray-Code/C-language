#ifndef _PRAC_EXAMINATION_H
#define _PRAC_EXAMINATION_H 




#define s(m,n) m/n							//某选择题
#define N 20								//韩师2017-4.阅读程序-3
#define MCRA(m) 3*m							//韩师2016-3.阅读程序-1
#define MCRB(n,m) 4*MCRA(n)+m				//韩师2016-3.阅读程序-1
#define STUCOUNT 20							//韩师2016-5-2 编程题
#define N1 3								//韩师2015-4.阅读程序或程序段-1
#define M1 3								//韩师2015-4.阅读程序或程序段-1
#define f(x) x*x							//韩师2014-2.选择-14


void pracExaminationTest();					//习题 测试函数
void categoryOutput();						//求输出值型题
void categoryOperationResult();				//运行结果类
void categoryReadProgram();					//阅读程序段类型
void pracTest();//日常习题测试

#endif