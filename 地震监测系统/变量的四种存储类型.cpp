#include <stdio.h>
#include <stdlib.h>
#include <string.h>//malloc();����ͷ�ļ�

static int o = 30;//ȫ�ִ��ڵ�ȫ�־�̬����

int q = 666;

int ai;//���岻�ü�extern,extern��������ʶ,ȫ�ֱ���������A.cpp��,Ҳ���Ե�B.cpp�ļ���
extern int extern_demo;//�����������ļ�������ȫ�ֱ���

void �ֲ���̬����() {
	static int k = 10;//ȫ�ִ���,��ֻ�ڴ˺�����ľֲ�����
	k++;
	//q++;//ȫ�ֱ������ı�
	//o++;//ȫ�־�̬�������ı�
	printf("%d ȫ�ֱ���:%d ȫ�־�̬����:%d\n ", k,q,o);//ָ������޸Ĳ�����
	//�˺�����ʧ,��̬��������
}

void �ⲿ����extern_demo() {
	extern_demo++;
	printf("�ⲿ����:%d\n", extern_demo);
}

int main(void) {
	//auto int i = 0;//������һ��,C++�ᱨ��,C���ᱨ��
	int i = 0;//�Զ�����,�Ǿ�̬�ľֲ�����

	while(1){
	//�Ĵ��������ٶȳ���,����cpu,�������ڴ�,���Բ���ȡ��ַ,register
	//C++��register�ؼ����Ѿ��Ż�,������Ǵ�ӡ��ַ,�������Ὣ����Ϊ��ͨ�ľֲ�����
	//�Ĵ����������ܶ���Ϊȫ�ֱ���.
	register int j = 0;
	break;
	}

	while (1) { 
	static int k = 0;//ȫ�ִ���,��ֻ�ڴ˺�����ľֲ�����
	�ֲ���̬����();
	�ֲ���̬����();
	//int q = 888;//����Զ�������ȫ�ֱ���ͬ��,��ô�Զ���������
	printf("%d ȫ�ֱ���:%d ȫ�־�̬����:%d\n", k,q,o);//ָ������޸Ĳ�����
	break;
	}

	�ⲿ����extern_demo();//�����ⲿ����

	system("pause");
	return 0;
}