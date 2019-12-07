#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cmath>//求平方速写库,pow(需要计算的数值, 2(多少次方));求平方值(需要计算的数值,多少次方);

using namespace std;

/*
1.问题描述：
使用数据文件中的一组地震检波器测量值确定可能的地震事件的位置。
2. 输入输出描述： 
程序的输入是名为seismic.dat的数据文件和用于计算短时间能量和长时间能量的取样值的数目。
输出是给出关于潜在的地震事件次数的报告。 
seismic.dat 的结构是这样的，第一行包含两个值：
地震检波器能量值的数目和 时间间隔，
从第二行开始就是能量值的数据，以空格分开 
短时间窗口和长时间窗口的值可以由键盘读入 
判定地震事件给定的阀值是 1.5 seismic.dat
中的数据如下： 
 11 0.01 
 1 2 1 1 1 5 4 2 1 1 1

算法设计：
1) 读取文件头并分配内存；
2) 从数据文件读取地震数据，从键盘读取计算能量的短时间和长时间窗口测量值的数目;
3) 计算各个时间点上的短时间窗口和长时间窗口的能量值，打印出可能的地震事件时间，
在这里，因为会涉及到频繁调用短时间窗口和长时间窗口的能量值，
我们可以将计算能量值设计为单独的一个函数
*/

const double Threshold_value = 1.5;//阀值,常量

//计算长时间/短时间窗口能量数据的采样值
//窗口能量平均值(能量数据[],能量数据数组的长度,窗口的长度)
double Energy_value(double Data[],int Data_len, int lenth); 



int main(void) {

	while (1) {
		string filename;//定义一字符串变量
		ifstream fin;//定义一个文件输入输出流,变量

		while (1) {
			cout << "输入地震能量数据文件的名字\n";
			cin >> filename;//地震监测能量数据.txt

			fin.open(filename.c_str());//fin=filename;//打开文件
			if (fin.fail()) {//判断是否打开了文件
				cout << "打开文件出错.\n";
				//exit(-1);//异常的结束
			}
			else {
				int Energy_quantity = 0;//读取文件的能量数量
				double Time_interval = 0;//读取文件的时间间隔
				//输出文件头两个数据到能量数量,时间间隔
				fin >> Energy_quantity >> Time_interval;
				//调试是否打开并读取到了文本
				//cout << Energy_quantity << " " << Time_interval << endl;

				if (Energy_quantity > 0) {//判断文件能量数量是否>0
					double* Energy_data_pointer = NULL;//能量数据指针
					//建(堆空间)放Energy_quantity个能量数据;
					Energy_data_pointer = new double[Energy_quantity];
					for (int i = 0; i < Energy_quantity; i++) {
						//将文本数据读入到动态内存(堆)中
						fin >> Energy_data_pointer[i];
					}


					int Short_time_window = 0;//计算短时间窗口
					int Long_time_window = 0;//计算长时间窗口
					cout << "请输入计算短时间窗口的数据\n";
					cin>>Short_time_window;//如2
					cout << "请输入计算长时间窗口的数据\n";
					cin >> Long_time_window;//如5,输完后下面进行计算
					

					//分析能量数据,找出地震事件
					//i=长时间窗口-1(下标确认);i<能量数据数量;i++
					double Long_sampling_value = 0;//长采样值
					double Short_sampling_value = 0;//短采样值
					double Proportion = 0;//短平均值/长平均值=比例
					for (int i = Long_time_window - 1; i < Energy_quantity; i++) {
						Short_sampling_value = Energy_value(Energy_data_pointer, i, Short_time_window);
						//短采样值=窗口能量平均值(能量数据[],能量数据数组的长度,窗口的长度);
						Long_sampling_value = Energy_value(Energy_data_pointer, i, Long_time_window);
						//比例=短采样值/长采样值;
						Proportion = Short_sampling_value / Long_sampling_value;
						if (Proportion >= Threshold_value) {//如果比例>=阀值
							cout << "在" << Time_interval * i << "震动异常\n";
						}
					}

					delete[] Energy_data_pointer;//计算完了,把堆空间还给内存
				}

				fin.close();//关闭文件
				break;
			}
		}
		break;
	}

	system("pause");
	return 0;
}

//计算长时间/短时间窗口对应能量数据的采样值
//窗口能量平均值(能量数据[],能量数据数组的长度,窗口的长度)
double Energy_value(double Data[], int Data_len, int lenth) {
	double Average = 0;//求到的平均值
	for (int i = 0; i < lenth; i++) {
		//求到的平均值+=求平方值(需要计算的数值,多少次方);
		Average += pow(Data[Data_len - i], 2);
	}
	return Average / lenth;
}

/*
1.问题描述：
使用数据文件中的一组地震检波器测量值确定可能的地震事件的位置。
2. 输入输出描述： 
程序的输入是名为seismic.dat的数据文件和用于计算短时间能量和长时间能量的取样值的数目。
输出是给出关于潜在的地震事件次数的报告。 
seismic.dat 的结构是这样的，第一行包含两个值：
地震检波器能量值的数目和 时间间隔，
从第二行开始就是能量值的数据，以空格分开 
短时间窗口和长时间窗口的值可以由键盘读入 
判定地震事件给定的阀值是 1.5 seismic.dat
中的数据如下： 
11 0.01 
1 2 1 1 1 5 4 2 1 1 1
| | | | | //长时间窗口
	  | | //短时间窗口

算法设计：
1) 读取文件头并分配内存；
2) 从数据文件读取地震数据，从键盘读取计算能量的短时间和长时间窗口测量 值的数目;
3) 计算各个时间点上的短时间窗口和长时间窗口的能量值，打印出可能的地震 事件时间，
在这里，因为会涉及到频繁调用短时间窗口和长时间窗口的能量值，
我们可以将计算能量值设计为单独的一个函数
*/