#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ���䶯̬�ڴ��������() {
	while (1) {//�����������
		int* p1 = new int;//���䶯̬�ڴ治ִ�г�ʼ��
		*p1 = 100;

		int* p2 = new int(100);//���䶯̬�ڴ��ҳ�ʼ��Ϊ100,�����൱

		//malloc ����ֵ��void*(Ҫ���ٶ��ٸ�,��*(��)���ٸ�)
		int* p3 = (int*)malloc(sizeof(int));//����int�Ŀռ�

		free(p1);//�������Ϳ��Ի����: new free();
		delete p3;//�������Ϳ��Ի����: malloc() delete;
		delete[] p2;
		break;
	}
}

void �������鶯̬�ڴ����() {
	while (1) {//�������鶯̬�ڴ����,�����ͬʱ���ܳ�ʼ����:int* p2 = new int[10]{1,2,3,4};
		int* p2 = new int[10];//������һ��
		int* p1 = (int*)malloc(sizeof(int) * 10);//p1[0]~p1[9]   *(p1+9)
		*p2 = 100;//���׸���̬�ڴ�һ��ֵ.������ΪNULL.

		delete[] p1;//free(p1); ���û������
		free(p2);//delete[] p2; �����vs2019�л�澯,��ûӰ��
		break;
	}

}


int main(void) {
	���䶯̬�ڴ��������();
	�������鶯̬�ڴ����();
	system("pause");
	return 0;
}