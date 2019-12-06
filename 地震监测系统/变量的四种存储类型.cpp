#include <stdio.h>
#include <stdlib.h>
#include <string.h>//malloc();函数头文件

static int o = 30;//全局存在的全局静态变量

int q = 666;

int ai;//定义不用加extern,extern是声明标识,全局变量可以在A.cpp中,也可以到B.cpp文件中
extern int extern_demo;//声明从外面文件过来的全局变量

void 局部静态变量() {
	static int k = 10;//全局存在,但只在此函数活动的局部变量
	k++;
	//q++;//全局变量被改变
	//o++;//全局静态变量被改变
	printf("%d 全局变量:%d 全局静态变量:%d\n ", k,q,o);//指针可以修改并访问
	//此函数消失,静态变量还在
}

void 外部变量extern_demo() {
	extern_demo++;
	printf("外部变量:%d\n", extern_demo);
}

int main(void) {
	//auto int i = 0;//和下面一样,C++会报错,C不会报错
	int i = 0;//自动变量,非静态的局部变量

	while(1){
	//寄存器变量速度超快,属于cpu,不属于内存,所以不能取地址,register
	//C++的register关键字已经优化,如果我们打印地址,编译器会将它变为普通的局部变量
	//寄存器变量不能定义为全局变量.
	register int j = 0;
	break;
	}

	while (1) { 
	static int k = 0;//全局存在,但只在此函数活动的局部变量
	局部静态变量();
	局部静态变量();
	//int q = 888;//如果自动变量和全局变量同名,那么自动变量优先
	printf("%d 全局变量:%d 全局静态变量:%d\n", k,q,o);//指针可以修改并访问
	break;
	}

	外部变量extern_demo();//调用外部变量

	system("pause");
	return 0;
}