#include <iostream>

using namespace std;
//��������������ԣ���װ���̳У���̬

/*
* ��װ���﷨
* class ����
* {
*	����Ȩ�ޣ�
*		���ԣ���Ա������;
*		��Ϊ����Ա������;
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

	//��Ϊ

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
		cout << "Ӣ�۵�ID��" << m_ID << ",Ѫ����" << m_HP << endl;
	}
};

void OB_Demo01()
{
	Hero h1(0b010, 1200);
	cout << "Ӣ�۵�ID��" << h1.m_ID << ",Ѫ����" << h1.m_HP << endl;
	h1.addHP(452);
	cout << "Ӣ�۵�ID��" << h1.m_ID << ",Ѫ����" << h1.m_HP << endl;
}

//����Ȩ�ޣ����У�˽�У�����

class House {

public:
	int name;
};

//���������
class Dog {
private:
	int m_Age;
	int m_Name;
public:
	//Ĭ�Ϲ��캯��
    Dog()
	{
		m_Age = 0;
		m_Name = 0;
	}
	//���ι��캯��
	Dog(int age, int name)
	{
		m_Age = age;
		m_Name = name;
	}
	//�������캯��
	//�������캯���ĵ���ʱ��
	/*
	* ���Ѿ������Ķ�������ʼ������
	* �����Ĵ���
	* �����ķ���ֵ
	*/
	Dog(const Dog& dog)
	{
		m_Age = dog.m_Age;
		m_Name = dog.m_Name;
		cout<<"�������캯��"<<endl;
	}
	//��������
    ~Dog()
	{
		cout << "��������" << endl;
	}
};

void funDemo00(Dog d)
{
	//���2�������Ĵ��ε��ÿ������캯��
}

void OB_Demo02(int* p,int size)
{
	Dog d1(10, 20);
	//���1
	Dog d2(d1);

}

Dog funDemo01()
{
	Dog d1(10, 20);
	//���3
	return d1;
}

void OB_Demo03()
{
	//���4
	Dog d2 = funDemo01();//�ڹص�rvo�Ż��󣬴˴��ǿ������캯�����ڱ�����������-��C/C++-�������������� /Zc:nrvo-
}

//��ʼ���б�
/*
* ��ʼ���б��﷨
* ����(����1������2������3��������) :��Ա����1(��ʼֵ1)����Ա����2(��ʼֵ2)����Ա����3(��ʼֵ3)������
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

//��ľ�̬��Ա���� 
//���������static�ؼ���
//ʹ��ǰ��Ҫ��ʼ������������ ����::������ = xx;
//Ҳ����ֱ������������
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
	cout << "Dog3�ľ�̬��Ա����m_Age��ֵ��" << d1.m_Age << endl;
	cout << "Dog3�ľ�̬��Ա����m_Name��ֵ��" << d1.m_Name << endl;
	cout<<"Dog3�ľ�̬��Ա����m_Age��ֵ��" << Dog3::m_Age << endl;
    cout << "Dog3�ľ�̬��Ա����m_Name��ֵ��" << Dog3::m_Name << endl;
}

//��̬��Ա����
//��̬��Ա�������ܷ��ʷǾ�̬��Ա�����ͳ�Ա����
class Dog4 {
public:
	static int m_Age;
	static int m_Name;
	int m_Age2;
	static void PrintDog()
	{
		cout << "Dog4�ľ�̬��Ա����" << endl;
		cout << "Dog4�ľ�̬��Ա����m_Age��ֵ��" << m_Age << endl;
		cout << "Dog4�ľ�̬��Ա����m_Name��ֵ��" << m_Name << endl;
		//cout << "Dog4�ķǾ�̬��Ա����m_Age2��ֵ��" << m_Age2 << endl;//������̬��Ա�������ܷ��ʷǾ�̬��Ա�����ͳ�Ա����
		//PrintDog2();//������̬��Ա�������ܷ��ʷǾ�̬��Ա�����ͳ�Ա����
	}

	Dog4(int age, int name,int age2) {
		m_Age = age;
		m_Name = name;
		m_Age2 = age2;
	}
	void PrintDog2()
	{
		cout << "Dog4�ĳ�Ա����" << endl;
		cout << "Dog4�ľ�̬��Ա����m_Age��ֵ��" << m_Age << endl;
		cout << "Dog4�ľ�̬��Ա����m_Name��ֵ��" << m_Name << endl;
	}
}; 

void OB_Demo05()
{
	Dog4 d1(10, 20,30);
	d1.PrintDog();
	Dog4::PrintDog();//��̬��Ա����ֱ�ӵ���
}

int main()
{
	OB_Demo04();
	return 0;
}