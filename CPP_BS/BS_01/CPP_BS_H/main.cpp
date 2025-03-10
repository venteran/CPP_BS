#include <iostream>
#include "main.h"

using namespace std;

//�������Ӧ�ó���
struct SchoolInfo
{
	char _name[20];//����
	int _role = 0b00;//��ɫ���ԣ���ʦ����ͬѧ0b0x ���еĻ���Ů��0bx0
	union {
		int _class;//ѧ��ʹ�ã��༶
		char course[20];//��ʦʹ�ã�����ѧ��
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
			cout << a[i]._name << "��һλ��ʦ"<<",��"<<a[i]._cc.course;
		}
		else
		{
			cout << a[i]._name << "��һ��ѧ��" << "���༶��" << a[i]._cc._class;
		}
		if(a[i]._role&0b10)
		{
			cout << "\t�����е�"<<endl;
		}
		else {
			cout << "\t����Ů��" << endl;
		}
	}
}

//���� 
//�����ڴ���ͷ��ڴ�
//malloc	free
//new		delete
//new �������Ϊ��������ڴ棬�����ö���Ĺ��캯�����г�ʼ����
//delete ���������ö��������������Ȼ���ͷŶ���ռ�õ��ڴ档
//malloc �� free��malloc ���� void* ���͵�ָ�룬�� C++ ����Ҫ��ʽת��Ϊ�����ָ�����ͣ�ȱ�����ͼ�飬�����������Ͳ�ƥ��Ĵ���
//new �� delete��new ���Զ����ݶ������ͷ�����Ӧ��С���ڴ棬���ص�ָ���������������һ�£�������ʽת�������Ͱ�ȫ�Ը��ߡ�
//

int* getInt(int v)
{
	int* a = new int(v);//����int* a ��ջ�ϵı�������aָ��ĵ�ַ��ֵ���ڶ��ϡ��������ص�ʱ��ջ�ϵ�a������ϵͳ�ͷŵ�������aָ����ڴ��ڶ��ϣ���û�б��ͷš�
	cout << a << endl;
	return a;
}

void C_Test00()
{
	int* p = getInt(23);//����Ҳ��ָ��Ķ����ڴ�
	cout << *p << endl;
	cout << p << endl;
}

//���������ͷ�
int* getGapList(int* arr, int size)
{
	//����һ�������ڴ�ռ䣬���ڴ�Ž���������ĺ�һ��Ԫ�غ�ǰһ��Ԫ�صĲ�ֵ
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

//����
//�����ʼ��  ��ʼ�����޷��޸�
//���õĵײ����һ��+ ָ�볣��

//������Ϊ��������
int funDemo00(int arr[], int size, int target, int& count)
{
	//���������е�Ŀ�����ֵĸ���
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

//������Ϊ��������ֵ
 //ע�⣬Ҫ���ⷵ�ؾֲ�����������
int& funDemo01(int* arr,int index)
{
	return arr[index];//���ڴ˴���ָ�룬�������������ڲ��ھֲ������Է�������
}

void CPP_Demo01()
{
	int a[] = { 1,5,3,8,2,6,2,4,9,5,2,7,8,5,6,1 };
	cout << funDemo01(a, 11) << endl;

	//������Ϊ����ֵ��������ֵ�������ֵ
	funDemo01(a, 2) = 999;
	cout << funDemo01(a, 2) << endl;//999
}

//��������
//const ��������& ������ = ���ö���;

void CPP_Demo02()
{
	int a = 0;
	const int& b = a;
	//�൱�ڳ���ָ�볣�� const int* const b = a;
	//һ����Ϊ�������Σ����⺯���ڲ��޸Ĳ�������
}

 //ָ������
//*&
//

void funDemo03(int*& a,int size) 
{
	//�ڽ��ж�̬�ڴ����ʱ������Ҫ�ں����ڲ��޸�ָ����ָ���·�����ڴ棬ʹ��ָ�����û�ܷ��㡣
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
	//funDemo03(a, 10);//�˴���a��һ��ָ��ֵ��������ָ��������������û����
	// //����int*& a �������һ��ָ������á�����ζ��������󶨵�һ���Ѿ����ڵ�ָ������ϣ�������ֱ�Ӱ󶨵�һ��ָ��ֵ
	// a�����������ڴ��ݸ�����ʱ���˻�Ϊһ����ʱ��int*���͵�ָ��ֵ��
	// ��int*& a Ҫ��󶨵�һ��������ָ����������ܰ󶨵���ʱֵ��
	// ��Ϊ���ñ���󶨵�һ����ֵ������ȡ��ַ�Ķ��󣩣�����ʱֵ����ֵ������ȡ��ַ����
	funDemo04(a, 10);
}



int main()
{
	CPP_Demo01();
	return 0;
}


