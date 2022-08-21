#include "DataBase.h"

DataBase::DataBase()
{
	University_Name = "UNIVERSITATEA ALEXANDRU IOAN CUZA, IASI";
}

void DataBase::Create(vector<Student> x)
{
	//University_Name = "UNIVERSITATEA ALEXANDRU IOAN CUZA, IASI";
	Entries = x;
}

void DataBase::AddEntry(Student x)
{
	Entries.push_back(x);
}

void DataBase::PrintAll()
{
	cout << endl << University_Name << endl;
	unsigned cont = 0;
	for (auto it : Entries)
	{
		cont++;
		cout << endl << "#" << cont;
		it.List();
	}
	cout << endl;
}

void DataBase::FindByName(string name)
{
	for (auto it : Entries)
		if (it.Get_Name() == name)
		{
			cout << endl << "Studentul cu numele " << name << " este inscris. Informatii: " << endl;
			it.List();
			cout << endl;
			return; // daca avem mai multi mai vedem
		}
	cout << "Nu l-am gasit pe " << name;
	return;
}

void DataBase::FindByFaculty(string Faculty)
{
	for (auto it : Entries)
	{
		if (it.Get_Faculty() == Faculty)
		{
			cout << endl << University_Name << " are specializarea cautata. "<< endl;
			return;
		}
	}
	cout << endl << University_Name << " nu are specializarea cautata. " << endl;
	return;
}

void DataBase::FindByMinimumGrade(float grade)
{	
	cout << endl << "La " << University_Name << " studentii urmatori au macar media " << grade << endl;

	for (auto it : Entries)
	{
		if (it.Get_Grade() > grade)
			it.List();
	}
}

unsigned DataBase::Get_Count()
{
	return Entries.size();
}

Student& DataBase::Get_Student(unsigned nr)
{
	return Entries.at(nr);
}

void DataBase::DeleteStudent(unsigned nr)
{
	Entries.erase(Entries.begin() + nr);
}
