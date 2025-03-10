#include <iostream>
#include "main.h"

using namespace std;

//联合体的应用场景
struct SchoolInfo
{
	char _name[20];//姓名
	int _role = 0b00;//角色属性：老师还是同学0b0x 是男的还是女的0bx0
	union {
		int _class;//学生使用，班级
		char course[20];//老师使用，所教学科
	}_cc;

	SchoolInfo(const char name[20], int a, int b, const char c[20])
	{
		strcpy_s(_name, name);
		_role = a;
		if(b>0) _cc._class = b;
		if(strlen(c)>0) strcpy_s(_cc.course, c);
	}
};

void U_Test01()
{
	SchoolInfo a[4] = {
		SchoolInfo("1111",0b01,0,"C++"),
		SchoolInfo("2222",0b10,66,""),
		SchoolInfo("3333",0b11,0,"C#"),
		SchoolInfo("4444",0b00,100,"")
	};

	for (int i = 0; i < 4; ++i)
	{
		if (a[i]._role&0b01)
		{
			cout << a[i]._name << "是一位老师"<<",教"<<a[i]._cc.course;
		}
		else
		{
			cout << a[i]._name << "是一名学生" << "，班级是" << a[i]._cc._class;
		}
		if(a[i]._role&0b10)
		{
			cout << "\t他是男的"<<endl;
		}
		else {
			cout << "\t她是女的" << endl;
		}
	}
}

//堆区 
//申请内存和释放内存
//malloc	free
//new		delete
//new 运算符会为对象分配内存，并调用对象的构造函数进行初始化。
//delete 运算符会调用对象的析构函数，然后释放对象占用的内存。
//malloc 和 free：malloc 返回 void* 类型的指针，在 C++ 里需要显式转换为所需的指针类型，缺乏类型检查，容易引发类型不匹配的错误。
//new 和 delete：new 会自动根据对象类型分配相应大小的内存，返回的指针类型与对象类型一致，无需显式转换，类型安全性更高。
//

int* getInt(int v)
{
	int* a = new int(v);//其中int* a 是栈上的变量，而a指向的地址的值是在堆上。函数返回的时候，栈上的a被操作系统释放掉，但是a指向的内存在堆上，还没有被释放。
	cout << a << endl;
	return a;
}

void C_Test00()
{
	int* p = getInt(23);//这里也是指向的堆上内存
	cout << *p << endl;
	cout << p << endl;
}

//数组申请释放
int* getGapList(int* arr, int size)
{
	//申请一个数组内存空间，用于存放进来的数组的后一个元素和前一个元素的差值
	int* p = new int[size - 1];
	for (int i = 0; i < size - 1; ++i)
	{
		p[i] = arr[i + 1] - arr[i];
	}
	return p;
}

void C_Test01()
{
	int a[] = { 1,5,8,6,4,9,7,5,1,4};
	int* p = getGapList(a, 10);
	for (int i = 0; i < 9; ++i)
	{
		cout << *(p + i)<<" ";
	}
	cout << endl;

	delete[] p;
	p = NULL;

}

//引用
//必须初始化  初始化后无法修改
//引用的底层就是一个+ 指针常量

//引用作为函数参数
int funDemo00(int arr[], int size, int target, int& count)
{
	//计算数组中的目标数字的个数
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == target)
		{
			count++;
			sum += arr[i];
		}
	}
	return sum;
}

void CPP_Demo00()
{
	int a[] = { 1,5,3,8,2,6,2,4,9,5,2,7,8,5,6,1 };
	int c = 0;
	int s = funDemo00(a, 16, 2, c);
	cout << s << "  " << c << endl;
}

//引用作为函数返回值
 //注意，要避免返回局部变量的引用
int& funDemo01(int* arr,int index)
{
	return arr[index];//由于此处的指针，所以其生命周期不在局部，可以返回引用
}

void CPP_Demo01()
{
	int a[] = { 1,5,3,8,2,6,2,4,9,5,2,7,8,5,6,1 };
	cout << funDemo01(a, 11) << endl;

	//引用作为返回值可以做赋值运算的左值
	funDemo01(a, 2) = 999;
	cout << funDemo01(a, 2) << endl;//999
}

//常量引用
//const 数据类型& 变量名 = 引用对象;

void CPP_Demo02()
{
	int a = 0;
	const int& b = a;
	//相当于常量指针常量 const int* const b = a;
	//一般作为函数传参，避免函数内部修改参数内容
}

 //指针引用
//*&
//

void funDemo03(int*& a,int size) 
{
	//在进行动态内存分配时，若需要在函数内部修改指针以指向新分配的内存，使用指针引用会很方便。
	a = new int[size];
	for (int i = 0; i < size; ++i)
	{
		a[i] = i;
	}
}

void funDemo04(int* a, int size)
{
	a = new int(12);
	
}

void CPP_Demo02()
{
	int a[] = { 1,5,6,9,7,2,3,1,5,8 };
	int* p = nullptr;
	funDemo03(p, 10);
	//funDemo03(a, 10);//此处的a是一个指针值，而不是指针变量，所以引用会出错
	// //报错，int*& a 代表的是一个指针的引用。这意味着它必须绑定到一个已经存在的指针变量上，而不是直接绑定到一个指针值
	// a是数组名，在传递给函数时它退化为一个临时的int*类型的指针值。
	// 而int*& a 要求绑定到一个真正的指针变量，不能绑定到临时值。
	// 因为引用必须绑定到一个左值（可以取地址的对象），而临时值是右值（不能取地址）。
	funDemo04(a, 10);
}



int main()
{
	CPP_Demo01();
	return 0;
}


