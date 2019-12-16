#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;


int main(void) {

	//练习一
	while (1) { 
	//初始版
	while (0) { 
	char a[] = { '4','5','6','9','8','7','9','5','4','1'};
	char a1[] = { '5','1','5','7','8','9','5','6','4','3','4'};
	int len = sizeof(a)+sizeof(a1);//堆的大小
	char* a2 = NULL;
	a2 = new char[len];
	memcpy(a2, a, sizeof(a));//把a拷贝到a2堆的前一段
	//for (int i = 0; i < sizeof(a);i++) {
		//*(a2 + i) = a[i];
   // }
	for (int i = 0; i < sizeof(a); i++) {
		cout << *(a2 + i) << " ";
	}
	cout << "\n";
	for (int i = sizeof(a); i < len; i += 1) {
		*(a2+i) = a1[i-sizeof(a)];
	}
	for (int i = 0; i < len; i++) {
		cout << *(a2+i) << " ";
	}
	cout << "\n";
	delete[] a2;
	break;
	}

	//这是改进
	while (0) { //用堆连接两个字符串
	string b;//一个字符四个字节
	string b1;
	cout << "请输入两字符串连接起来\n";
	cin >> b >> b1;
	string* b2=NULL;
	int len1 = b.length()+b1.length();
	b2 = new string[len1];//cout << sizeof(b) << endl;//一个字符四个字节,后面会自动包含'\0'

	for (int i = 0; i < (b.length());i++) {
	  *(b2 + i) = b[i];
	 }//cout << "\n"<<sizeof(b2);//一个string空间4个字节

	for (int i = (b.length()); i < len1; i++) {
		*(b2 + i) = b1[i-b.length()];
	}

	for (int i = 0; i < len1; i++) {
		cout << *(b2 + i);
	}
	cout << "\n";

	delete[] b2;
	break;
	}
	break;
	}

	//练习二
	while (0) {
		string c1;
		string* c[3] = { NULL };
		int len[3] = {0};
		cout << "请输入三行字符串进来:\n";
		for (int j = 0; j < 3;j++) {
			cin >> c1;
			//cout << sizeof(c1) << endl;//中文字符为2个sting空间
			//string* c = NULL; 
			c[j] = new string[c1.length()];
			for (int i = 0; i < c1.length(); i++) {c[j][i] = c1[i];}
			len[j] = c1.length();
			//delete[] c;
		}
		for(int j=0;j<3;j++){
		for (int i = 0; i < len[j]; i++) {
			cout << c[j][i];
		}
		}
		cout << "到\n";
		delete[] c[0];
		delete[] c[1];
		delete[] c[2];
		//cout << "到\n";
		break; 
	}

	//练习三
	while (1) { 
		int* p=NULL; 
		int row, col; 
		int i, j, k = 1; 
		cout << "Input number of row : \n"; 
		cin >> row; 
		cout << "Input number of column\n";
		cin >> col; 
		p = new int[row*col]; 
		if(row==0 || col==0) { 
		cout << "Not allocate memory!\n"; 
		exit(1); 
		}
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) 
			p[k-1] = k++;
			//根据行列下标，计算下表值 
		}
		//cout << k << "k\n";
		for(i=0;i<row;i++){ 
			for (j = 0; j < col; j++)
				cout << p[(k++)-(row*col+1)] << "\t";
			//根据行列下标，计算下表值 
			cout<<endl; 
		}
		delete [] p;
		break; }

	system("pause");
	return 0;
}