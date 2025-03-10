#include <iostream>

using namespace std;
//面向对象三大特性：封装，继承，多态

/*
* 封装的语法
* class 类型
* {
*	访问权限：
*		属性（成员变量）;
*		行为（成员函数）;
* };
*/

enum obj
{
	WARRIOR = 1 << 0,
	SUPPORT = 1 << 1,
	MAGE = 1 << 2,
	ASSASSIN = 1<<3,
	TANK = 1<<4
};


class Hero {
public:
	int m_ID;
	int m_HP;

	//行为

	Hero(int id, int hp)
	{
		m_ID = id;
		m_HP = hp;
	}

	void addHP(int hp)
	{
		m_HP += hp;
	}

	void subHP(int hp)
	{
		if (m_HP <= hp)
		{
			m_HP = 0;
		}
		else {
			m_HP -= hp;
		}
	}

	void PrintHero()
	{
		cout << "英雄的ID是" << m_ID << ",血量是" << m_HP << endl;
	}
};

void OB_Demo01()
{
	Hero h1(0b010, 1200);
	cout << "英雄的ID是" << h1.m_ID << ",血量是" << h1.m_HP << endl;
	h1.addHP(452);
	cout << "英雄的ID是" << h1.m_ID << ",血量是" << h1.m_HP << endl;
}

//访问权限，共有，私有，保护

class House {

public:
	int name;
};

//构造和析构
class Dog {
private:
	int m_Age;
	int m_Name;
public:
	//默认构造函数
    Dog()
	{
		m_Age = 0;
		m_Name = 0;
	}
	//带参构造函数
	Dog(int age, int name)
	{
		m_Age = age;
		m_Name = name;
	}
	//拷贝构造函数
	//拷贝构造函数的调用时机
	/*
	* 用已经创建的对象来初始化对象
	* 函数的传承
	* 函数的返回值
	*/
	Dog(const Dog& dog)
	{
		m_Age = dog.m_Age;
		m_Name = dog.m_Name;
		cout<<"拷贝构造函数"<<endl;
	}
	//析构函数
    ~Dog()
	{
		cout << "析构函数" << endl;
	}
};

void funDemo00(Dog d)
{
	//情况2，函数的传参调用拷贝构造函数
}

void OB_Demo02(int* p,int size)
{
	Dog d1(10, 20);
	//情况1
	Dog d2(d1);

}

Dog funDemo01()
{
	Dog d1(10, 20);
	//情况3
	return d1;
}

void OB_Demo03()
{
	//情况4
	Dog d2 = funDemo01();//在关掉rvo优化后，此处是拷贝构造函数，在本程序中属性-》C/C++-》命令行中输入 /Zc:nrvo-
}

//初始化列表
/*
* 初始化列表语法
* 类名(参数1，参数2，参数3，。。。) :成员变量1(初始值1)，成员变量2(初始值2)，成员变量3(初始值3)。。。
* {
*	
* }
*/
class Dog2 {
public:
	int m_Age;
	int m_Name;
	Dog2(int age ,int name):m_Age(age),m_Name(name){}
};

//类的静态成员变量 
//在类中添加static关键字
//使用前需要初始化，数据类型 类名::变量名 = xx;
//也可以直接用类名调用
class Dog3 {
public:
	static int m_Age;
	static int m_Name;
	Dog3(int age, int name) {
		m_Age = age;
		m_Name = name;
	}
};
int Dog3::m_Age = 0;
int Dog3::m_Name = 0;

void OB_Demo04()
{
	Dog3 d1(10, 20);
	cout << "Dog3的静态成员变量m_Age的值是" << d1.m_Age << endl;
	cout << "Dog3的静态成员变量m_Name的值是" << d1.m_Name << endl;
	cout<<"Dog3的静态成员变量m_Age的值是" << Dog3::m_Age << endl;
    cout << "Dog3的静态成员变量m_Name的值是" << Dog3::m_Name << endl;
}

//静态成员函数
//静态成员函数不能访问非静态成员变量和成员函数
class Dog4 {
public:
	static int m_Age;
	static int m_Name;
	int m_Age2;
	static void PrintDog()
	{
		cout << "Dog4的静态成员函数" << endl;
		cout << "Dog4的静态成员变量m_Age的值是" << m_Age << endl;
		cout << "Dog4的静态成员变量m_Name的值是" << m_Name << endl;
		//cout << "Dog4的非静态成员变量m_Age2的值是" << m_Age2 << endl;//报错，静态成员函数不能访问非静态成员变量和成员函数
		//PrintDog2();//报错，静态成员函数不能访问非静态成员变量和成员函数
	}

	Dog4(int age, int name,int age2) {
		m_Age = age;
		m_Name = name;
		m_Age2 = age2;
	}
	void PrintDog2()
	{
		cout << "Dog4的成员函数" << endl;
		cout << "Dog4的静态成员变量m_Age的值是" << m_Age << endl;
		cout << "Dog4的静态成员变量m_Name的值是" << m_Name << endl;
	}
}; 

void OB_Demo05()
{
	Dog4 d1(10, 20,30);
	d1.PrintDog();
	Dog4::PrintDog();//静态成员函数直接调用
}

int main()
{
	OB_Demo04();
	return 0;
}