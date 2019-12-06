#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 分配动态内存基础类型() {
	while (1) {//分配基础类型
		int* p1 = new int;//分配动态内存不执行初始化
		*p1 = 100;

		int* p2 = new int(100);//分配动态内存且初始化为100,和上相当

		//malloc 返回值是void*(要开辟多少个,就*(乘)多少个)
		int* p3 = (int*)malloc(sizeof(int));//开辟int的空间

		free(p1);//基础类型可以混搭如: new free();
		delete p3;//基础类型可以混搭如: malloc() delete;
		delete[] p2;
		break;
	}
}

void 分配数组动态内存变量() {
	while (1) {//分配数组动态内存变量,分配的同时不能初始化如:int* p2 = new int[10]{1,2,3,4};
		int* p2 = new int[10];//和上面一样
		int* p1 = (int*)malloc(sizeof(int) * 10);//p1[0]~p1[9]   *(p1+9)
		*p2 = 100;//给首个动态内存一个值.其它的为NULL.

		delete[] p1;//free(p1); 混搭没有问题
		free(p2);//delete[] p2; 混搭在vs2019中会告警,但没影响
		break;
	}

}


int main(void) {
	分配动态内存基础类型();
	分配数组动态内存变量();
	system("pause");
	return 0;
}