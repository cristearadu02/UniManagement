#pragma once
#include "Student.h"
#include <vector>

using namespace std;

class DataBase
{
private:
	vector<Student> Entries;
	string University_Name;
public:
	DataBase();
	void Create(vector<Student> x);
	void AddEntry(Student x);
	void PrintAll();
	void FindByName(string name);
	void FindByFaculty(string Faculty);
	void FindByMinimumGrade(float grade);
	unsigned Get_Count();
	Student& Get_Student(unsigned nr);
	void DeleteStudent(unsigned nr);
};