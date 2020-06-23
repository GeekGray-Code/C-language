#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter4_sequential_structure.h"



/*chapter4 顺序结构 测试函数*/
void chapter4SequentialStructureTest()
{
	//calcTriangleArea();
	//calcCaseConversion();
	//calcRootOfEquation();
	//calcCircleArea();
}

/*求三角形面积*/
void calcTriangleArea()
{
	float side,side1, side2, side3, area;						//定义三边变量及面积变量

	printf("请输入三角形三边，格式（边长1，边长2，边长3）\n");
	scanf("%f,%f,%f",&side1,&side2,&side3);

	side = (side1+side2+side3) / 2;								//三边关系
	area = sqrt(side*(side-side1*(side-side2)*(side-side3)));	//面积关系,sqrt:求平方根函数

	printf("side1=%7.2f\nside2=%7.2f\nside3=%7.2f\nside=%7.2f\narea=%7.2f\n",side1,side2,side3,side,area);
}


/*大小写转换*/
void calcCaseConversion()
{
	char c1, c2;

	c1 = getchar();
	printf("%c,%d\n",c1,c1);

	c2 = c1 + 32;
	printf("%c,%d\n",c2,c2);
}


/*求一元二次方程的根*/
void calcRootOfEquation()
{
	float a, b, c, disc, x1, x2, p, q;	//系数，根，对称轴

	printf("请输入一元二次方程的3个系数：格式（a，b，c）\n");
	scanf("%f,%f,%f",&a,&b,&c);

	disc = b*b - 4 * a*c;				//判别式
	p = -b / (2 * a);					//对称轴
	q = sqrt(disc)/(2*a);

	if (q>=0)
	{
		x1 = (p+q);
		x2 = p - q;

		printf("方程：%fx^2+%fx+%f 的解为\n",a,b,c);
		printf("x1= %f\nx2= %f",x1,x2);
	}
	else
	{
		printf("该方程有一对共轭复根！\n");
	}
}


/*求圆的面积及相关参数*/
void calcCircleArea()
{
	float r = 1.5;				//圆半径
	float h = 3;				//圆柱体的高
	float circlePerimeter;		//圆周长
	float circleArea;			//圆面积
	float sphereSurfaceArea;	//圆球表面积
	float sphereVolume;			//球体体积
	float cylinderVolume;		//圆柱体体积

	circlePerimeter = 2 * PI*r;
	circleArea = PI*r*r;
	sphereSurfaceArea = 4 * PI*r*r;
	sphereVolume = 4 * PI*r*r*r;
	cylinderVolume = PI*r*r*h;

	printf("圆半径：%f\n",r);
	printf("圆柱体的高：%f\n", h);
	printf("圆周长：%f\n", circlePerimeter);
	printf("圆面积：%f\n", circleArea);
	printf("圆球表面积：%f\n", sphereSurfaceArea);
	printf("球体体积：%f\n", sphereVolume);
	printf("圆柱体体积：%f\n", cylinderVolume);
}