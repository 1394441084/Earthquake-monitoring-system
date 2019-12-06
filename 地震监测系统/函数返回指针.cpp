#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//函数返回值(普通)
int arr(int a,int b) {
	int sun = a + b;
	return sun;
}

//函数返回指针(特殊)
int* arrl(int x, int y) {
	int* sun = NULL;//空指针
	sun =new int;//借个空间
	*sun = x + y;//首个堆空间=x+y;
	return sun;//返回sun指针
}

//函数返回值(特殊错误,错误示范)
int *arr2(int a, int b) {
	int sun = a + b;
	return &sun;
}

int main(void) {
	int a = 3, b = 5;
	printf("%d\n", arr(a, b));//函数返回值(普通)

	while (1) {//函数返回指针(特殊)
	//这样的话里面的堆空间无法释放,有问题!!!
	//最好用指针来接
	//cout << *(arrl(a, b)) << endl;
	int* sun = NULL;//空指针
	sun = arrl(a, b);//将地址接过来
	cout << *sun << endl;
	delete[] sun;//通过指针指向堆空间,把堆空间还给内存
	break;
	}

	while (1) { 
	int *sun1 = NULL;
	sun1 = arr2(a, b);//指针指向的是栈空间的局部变量的地址
	//由于函数使用完,这栈空间会还回内存(除静态变量,全局变量,堆)
	//所以此时指针指向的地址里空,一旦此地址被占用,那么使用指针的话,很危险
	//如下示例
	arrl(9, 9);//看错误就使用此函数
	cout << *sun1 << endl;
	break;
	}

	system("pause");
	return 0;
}