#include "Computer1.h"
//一个函数只定义一次但可以声明多次
//成员函数放在类之外实现，成员函数的定义
//此时，不再是inline函数
//inline

void Computer::print()
{
	cout<<"品牌："<<_brand<<endl;
	cout<<"价格："<<_fprice<<endl;
}

//inline 放在头文件中
//如果分成头文件和实现文件时，不能用内联

void Computer::setBrand(const char * brand)
{
	strcpy(_brand,brand);
}

//inline


void print()
{
	cout<<"print()"<<endl;
}
void Computer::setPrice(float fprice)
{
	_fprice=fprice;
}

int main(void)
{
	Computer com;
	com.setBrand("thinkpad");//.叫成员访问运算符
	com.setPrice(6399);
	com.print();
	print();

	return 0;
}
