#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public://该类对外提供的服务 -->接口
	void print();
	void setBrand(const char * brand);
	void setPrice(float fprice);
private://私有成员只能再类内部进行访问，体现类封装的特性
	char _brand[20];//数据成员
	float _fprice;
};
