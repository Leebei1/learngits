#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand,float price)
		//: _brand(brand) //浅拷贝
		: _brand(new char[strlen(brand)+1]())//深拷贝
		, _price(price)
	{
		cout<<"Computer(const char *,float)"<<endl;
		strcpy(_brand,brand);
	}
//用来做清理工作的
~Computer()
{
	cout<<"~Computer()"<<endl;
	delete [] _brand;
	_brand =NULL;
}

void print();
void setBrand(const char *brand);
void setPrice(float price);

private:
char * _brand;
float _price;
};



void print()
{
	cout<<"print()"<<endl;
}

void Computer::print()
{
	cout<<"品牌："<<_brand<<endl;
	cout<<"价格："<<_price<<endl;
}

void Computer::setBrand(const char * brand)
{
	strcpy(_brand,brand);
}

void Computer::setPrice(float price)
{
	_price=price;
}

//全局变量

Computer pc2("Thinkpad",6666);

int main(void)
{
	Computer com("mac",10000);
	com.setBrand("xiaomi");
	com.setPrice(4999);
	com.print();
	return 0;
}
