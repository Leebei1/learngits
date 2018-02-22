#include <iostream>
#include <string.h>
//赋值运算函数
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
	Computer(const Computer &rhs)
		:_brand(new char[strlen(rhs._brand)+1]())
		, _price(rhs._price)
	{
		cout<<"Computer(const Computer&)"<<endl;
		strcpy(_brand,rhs._brand);
	}

	//系统提供的赋值运算符函数
#if 0
	Computer & operator =(const Computer & rhs)
	{
		_brand=rhs._brand;
		_price=rhs._price;
		return *this;
	}
#endif 

	Computer & operator=(const Computer &rhs)
	{
		cout<<"Computer & operator=(const Computer & rhs)"<<endl;
		if(_brand==rhs._brand)//判断是否自复制
		{
			delete [] _brand;//回收操作数指针原来的空间

			this->_brand=new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);
			_price=rhs._price;
		}
		return *this;
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


int test2(void)
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


void test1(void)
{
	int a=3;
	int b=4;
	a=b;
	///a=a
	Computer pc1("Xiaomi",4999);
	pc1.print();
	Computer pc2("Mac",10000);
	pc2.print();
	pc2=pc1;
	pc2.print();
	pc2=pc2;
}

int main(void)
{
	test1();
	return 0;
}
