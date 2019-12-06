#include <stdio.h>
#include <stdlib.h>
#include <string.h>//内存拷贝memcpy();函数

/*
 new delete 是运算符比malloc();函数,效率要高,而且还不用分配空间;
1.按需分配,不浪费内存
2.被调用函数之外需要使用被调用函数内部的指针对应的地址空间(函数外调用堆)
3.栈区是有限制的,使用堆可以让栈区突破限制,
  因为堆区和栈区不在同一区哈哈,堆区没释放就相当于静态变量
  windows10里堆的限制是2G,栈的限制为1M
*/

void 动态内存的内存拷贝函数示例() {//按需分配示例
	//这是去年的价格
	int 房间[10] = { 20,22,25,19,18,23,17,28,30,35 };
	//现在员工数量
	int 员工 = 0;
	//现在酒店要给老顾客优惠
	int* 酒店房间 = NULL;

	printf("请输入在职员工数量:\n");
	scanf_s("%d", &员工);

	//这新员工来了要有地方住,所以就租酒店吧
	酒店房间 = new int[员工];//后面新开房的都是18元价格

	/*
	for (int i = 0; i < sizeof(farmer) / sizeof(int); i++) {
		*(salary + i) = farmer[i];//逐个给动态内存赋值
	}
	*/

	//使用内存拷贝函数给动态内存赋值
	//拷贝函数(动态内存,被拷贝的变量,拷贝多少字节数);
	memcpy(酒店房间, 房间, sizeof(房间));

	for (int i = sizeof(房间) / sizeof(int); i < 员工; i++) {
		//salary[i] = 18:
		*(酒店房间 + i) = 18;//这后面所开的房间都以18元定价
	}

	for (int i = 0; i < 员工; i++) {
		printf("第%d个员工所住房间的租金: %d\n", i + 1, 酒店房间[i]);
	}

	delete[] 酒店房间;//释放堆

}

//通过返回动态内存的指针,第一种
int* demo(int count) {
	int* ap = NULL;
	//new delete 是C++的动态内存分配操作符
	//下列是C语言的malloc();动态内存分配操作符
	//ap=(转类型)malloc(字节数*外面传过来的数量);
	//malloc(参数:所需内存的字节数);
	ap = (int*)malloc(sizeof(int) * count);//ap=new int[count];

	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;//赋值
	}
	for (int i = 0; i < count; i++) {//打印
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
	return ap;//返回ap指针地址
}

//通过二级指针来保存,第二种
void demol(int count, int** pointer_p) {
	int* ap = NULL;
	*pointer_p = (int*)malloc(sizeof(int) * count);
	ap = *pointer_p;//ap指针指向堆空间的首地址
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;//给堆空间赋值
	}
	for (int i = 0; i < count;i++) {//将堆空间打印
		printf("*(ap+%d) = %d\n",i, *(ap + i));
	}
}

int main(void) {
	//动态内存的内存拷贝函数示例();

	//两种方式获取被调用函数内部的内存
	int* pointer = NULL;
	int count = 10;
	//第一种，通过返回动态内存的指针
	//pointer = demo (count);//pointer接收函数返回的地址,指向同堆的地址

	//第二种，通过二级指针来保存
	demol (count, &pointer) ;
	for (int i = 0; i < 10; i++) {
		printf("*(pointer+%d) = %d\n", i, *(pointer + i));
	}
	//用完了，要记得释放
	free(pointer);//C语言中的释放内存函数,相当于C++的delete;


	system("pause");
	return 0;
}