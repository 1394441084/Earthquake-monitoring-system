#include <stdio.h>
#include <stdlib.h>
#include <string.h>//�ڴ濽��memcpy();����

/*
 new delete ���������malloc();����,Ч��Ҫ��,���һ����÷���ռ�;
1.�������,���˷��ڴ�
2.�����ú���֮����Ҫʹ�ñ����ú����ڲ���ָ���Ӧ�ĵ�ַ�ռ�(��������ö�)
3.ջ���������Ƶ�,ʹ�öѿ�����ջ��ͻ������,
  ��Ϊ������ջ������ͬһ������,����û�ͷž��൱�ھ�̬����
  windows10��ѵ�������2G,ջ������Ϊ1M
*/

void ��̬�ڴ���ڴ濽������ʾ��() {//�������ʾ��
	//����ȥ��ļ۸�
	int ����[10] = { 20,22,25,19,18,23,17,28,30,35 };
	//����Ա������
	int Ա�� = 0;
	//���ھƵ�Ҫ���Ϲ˿��Ż�
	int* �Ƶ귿�� = NULL;

	printf("��������ְԱ������:\n");
	scanf_s("%d", &Ա��);

	//����Ա������Ҫ�еط�ס,���Ծ���Ƶ��
	�Ƶ귿�� = new int[Ա��];//�����¿����Ķ���18Ԫ�۸�

	/*
	for (int i = 0; i < sizeof(farmer) / sizeof(int); i++) {
		*(salary + i) = farmer[i];//�������̬�ڴ渳ֵ
	}
	*/

	//ʹ���ڴ濽����������̬�ڴ渳ֵ
	//��������(��̬�ڴ�,�������ı���,���������ֽ���);
	memcpy(�Ƶ귿��, ����, sizeof(����));

	for (int i = sizeof(����) / sizeof(int); i < Ա��; i++) {
		//salary[i] = 18:
		*(�Ƶ귿�� + i) = 18;//����������ķ��䶼��18Ԫ����
	}

	for (int i = 0; i < Ա��; i++) {
		printf("��%d��Ա����ס��������: %d\n", i + 1, �Ƶ귿��[i]);
	}

	delete[] �Ƶ귿��;//�ͷŶ�

}

//ͨ�����ض�̬�ڴ��ָ��,��һ��
int* demo(int count) {
	int* ap = NULL;
	//new delete ��C++�Ķ�̬�ڴ���������
	//������C���Ե�malloc();��̬�ڴ���������
	//ap=(ת����)malloc(�ֽ���*���洫����������);
	//malloc(����:�����ڴ���ֽ���);
	ap = (int*)malloc(sizeof(int) * count);//ap=new int[count];

	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;//��ֵ
	}
	for (int i = 0; i < count; i++) {//��ӡ
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
	return ap;//����apָ���ַ
}

//ͨ������ָ��������,�ڶ���
void demol(int count, int** pointer_p) {
	int* ap = NULL;
	*pointer_p = (int*)malloc(sizeof(int) * count);
	ap = *pointer_p;//apָ��ָ��ѿռ���׵�ַ
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;//���ѿռ丳ֵ
	}
	for (int i = 0; i < count;i++) {//���ѿռ��ӡ
		printf("*(ap+%d) = %d\n",i, *(ap + i));
	}
}

int main(void) {
	//��̬�ڴ���ڴ濽������ʾ��();

	//���ַ�ʽ��ȡ�����ú����ڲ����ڴ�
	int* pointer = NULL;
	int count = 10;
	//��һ�֣�ͨ�����ض�̬�ڴ��ָ��
	//pointer = demo (count);//pointer���պ������صĵ�ַ,ָ��ͬ�ѵĵ�ַ

	//�ڶ��֣�ͨ������ָ��������
	demol (count, &pointer) ;
	for (int i = 0; i < 10; i++) {
		printf("*(pointer+%d) = %d\n", i, *(pointer + i));
	}
	//�����ˣ�Ҫ�ǵ��ͷ�
	free(pointer);//C�����е��ͷ��ڴ溯��,�൱��C++��delete;


	system("pause");
	return 0;
}