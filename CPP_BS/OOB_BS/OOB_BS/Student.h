#pragma once
#include "Teacher.h"


class Student
{
public:
	Student();
	~Student();
private:
    int m_id;
	Teacher* m_teacher;
};