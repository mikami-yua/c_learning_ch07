#include <iostream>
using namespace std;
#include <fstream>

/*
c++对文件的操作需要包含头文件《fstream》
文件分为两种：
	文本文件
		以文本的ASCII码存储在计算机中
	二进制文件
		0、1形式

操作文件流三大类：
	ofstrean：写
	ifstream：读
	fstream：读写

写文件的三大步骤
	1.包含头文件
		#include <fstream>
	2.创建流对象
		ofstream ofs;
	3.打开文件
		ofs.open("path",)
		打开方式：
			ios::in为了读文件打开
			ios：：out为了写文件打开
			ios：：ate初始位置文件末尾
			ios：：app以追加的方式写文件
			ios：：trunc如果文件存在先删除再创建
			ios：：binary二进制方式
	4.写数据
		ofs<<"load"
	5.关闭文件
		ofs.close()

*/


int main() {

	system("pause");
	return 0;
}