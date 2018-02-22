#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand,float price)
		: _brand(new char[strlen(brand)+1]())
		, _price(price)
	{
		cout<< "Computer(const char *,float)"<<endl;
		strcpy(_brand,brand);
	}

	//系统提供复制构造函数不再适用
#if 0
	Computer(const Computer &rhs)
		: _brand(rhs._brand)
		, _price(rhs._price)
	{
		cout << "Computer (const Computer&)" <<endl;
	}
#endif 


	Computer(const Computer &rhs)
		:_brand(new char[strlen(rhs._brand)+1]())
		, _price(rhs._price)
	{
		cout<<"Computer(const Computer&)"<<endl;
		strcpy(_brand,rhs._brand);
	}
	~Computer()
	{
		cout<<"~Computer()" <<endl;
		delete [] _brand;
	}
	void print();
private:
	char * _brand;
	float _price;
};

void print()
{
	cout <<"print()"<<endl;
}

void Computer::print()
{
	cout<<"品牌："<<_brand<<endl;
	cout<<"价格："<<_price<<endl;
}


int main(void)
{
	int a=3;
	int b=a;
	char brand[]="Xiaomi";
	Computer com(brand,4999);//栈对象
	com.print();
	Computer com2=com;
	com2.print();

	return 0;
}
