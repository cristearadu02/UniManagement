#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string LastName;  // numele de familie
	string FirstName; // prenumele
	string Faculty;
	float  Grade;
public:
	Student();
	void Set_LastName(string name);
	void Set_FirstName(string name);
	void Set_Faculty(string name);
	void Set_Grade(float x);
	string Get_Name();
	string Get_FirstName();
	string Get_Faculty();
	float  Get_Grade();
	void List();
};

