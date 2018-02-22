#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public://该类对外提供的服务 -->接口
	//如果再类内部实现的成员函数，他们都是inline函数
	void print();

	void setBrand(const char * brand)
	{
		strcpy(_brand,brand);
		setPrice(5000);//在类内部访问私有成员函数
	}

	void setPrice(float fprice)
	{
		_fprice = fprice;
	}
private://私有成员只能再类内部进行访问，体现类封装的特性
	char _brand[20];//数据成员
	float _fprice;
};
