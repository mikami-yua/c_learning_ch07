#include <iostream>
using namespace std;
#include <fstream>
#include<string>
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

			配合使用时使用|
		读取方式：
			
	4.写数据
		ofs<<"load"
	5.关闭文件
		ofs.close()

*/

//文本文件写操作
void test01() {
	//1.包含头文件

	//2.创建流对象
	ofstream ofs;
	//3.打开文件
	ofs.open("test01.txt", ios::out);
	//4.写数据
	ofs << "name:zhangsan" << endl;
	ofs << "sex:male" << endl;
	//5.关闭文件
	ofs.close();
}
//读文件
void test02() {
	ifstream ifs;
	//判断是否打开成功
	ifs.open("test01.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "open file error" << endl;
		return;
	}
	//读文件的四种读取方式
	//1
	/*
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//2
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//3
	/*string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}*/
	//4---不推荐
	char c;
	while ((c = ifs.get())!=EOF) {//end of file
		cout << c;
	}


	ifs.close();
}
//二进制形式对文件操作
//写文件
class Person {
public:
	char name[64];
	int age;
};

void test03() {
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "zhangsan",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}
//读文件
void test04() {
	ifstream ifs;
	ifs.open("person.txt",ios::in|ios::binary);
	if (!ifs.is_open()) {
		cout << "open file error" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << p.name << " " << p.age << endl;
	ifs.close();
}


int main() {
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	
	return 0;
}