#include "Student.h"

// ===== AUX =====

bool isValid(char x)
{
	string aux = "01234567890,.;[]'=/<>?{}|+_)(*&^%$#@!`~";
	if (aux.find(x) == true)
		return false;
	return true;
}

// ====== CONSTRUCTOR =========

Student::Student()
{
	Grade = 0;
	LastName = "NULL";
	FirstName = "NULL";
	Faculty = "NULL";
}

// ===== SETTERE =====
void Student::Set_LastName(string name)
{
	for (auto it : name)
		if (isValid(it) == false)
			return;
	LastName = name;
}

void Student::Set_FirstName(string name)
{
	for (auto it : name)
		if (isValid(it) == false)
			return;
	FirstName = name;
}

void Student::Set_Faculty(string name)
{
	for (auto it : name)
		if (isValid(it) == false)
			return;
	Faculty = name;
}

void Student::Set_Grade(float x)
{
	if (x < 0 || x>10)
		return;
	Grade = x;
}

// ===== GETTERE =====

string Student::Get_Name()
{
	return LastName;
}

string Student::Get_FirstName()
{
	return FirstName;
}

string Student::Get_Faculty()
{
	return Faculty;
}

float Student::Get_Grade()
{
	return Grade;
}

// =====================

void Student::List()
{
	cout << endl << "Nume si prenume: " << LastName << ' ' << FirstName << endl << "Facultate: " << Faculty << endl << "Nota: " << Grade;
}