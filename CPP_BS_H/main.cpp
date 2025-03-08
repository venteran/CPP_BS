#include <iostream>
#include "main.h"

using namespace std;

//联合体的内存分配
union U_Data
{
	int a;
	float b;
	char c[8];
};

int main()
{

	cout << "Hello World!!" << endl;
	return 0;
}

void func1()
{
	return;

}
