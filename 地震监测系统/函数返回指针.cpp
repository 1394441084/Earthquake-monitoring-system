#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//��������ֵ(��ͨ)
int arr(int a,int b) {
	int sun = a + b;
	return sun;
}

//��������ָ��(����)
int* arrl(int x, int y) {
	int* sun = NULL;//��ָ��
	sun =new int;//����ռ�
	*sun = x + y;//�׸��ѿռ�=x+y;
	return sun;//����sunָ��
}

//��������ֵ(�������,����ʾ��)
int *arr2(int a, int b) {
	int sun = a + b;
	return &sun;
}

int main(void) {
	int a = 3, b = 5;
	printf("%d\n", arr(a, b));//��������ֵ(��ͨ)

	while (1) {//��������ָ��(����)
	//�����Ļ�����Ķѿռ��޷��ͷ�,������!!!
	//�����ָ������
	//cout << *(arrl(a, b)) << endl;
	int* sun = NULL;//��ָ��
	sun = arrl(a, b);//����ַ�ӹ���
	cout << *sun << endl;
	delete[] sun;//ͨ��ָ��ָ��ѿռ�,�Ѷѿռ仹���ڴ�
	break;
	}

	while (1) { 
	int *sun1 = NULL;
	sun1 = arr2(a, b);//ָ��ָ�����ջ�ռ�ľֲ������ĵ�ַ
	//���ں���ʹ����,��ջ�ռ�ỹ���ڴ�(����̬����,ȫ�ֱ���,��)
	//���Դ�ʱָ��ָ��ĵ�ַ���,һ���˵�ַ��ռ��,��ôʹ��ָ��Ļ�,��Σ��
	//����ʾ��
	arrl(9, 9);//�������ʹ�ô˺���
	cout << *sun1 << endl;
	break;
	}

	system("pause");
	return 0;
}