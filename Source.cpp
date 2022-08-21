#include <iostream>
#include <fstream>
#include "DataBase.h"

using namespace std;

int opt = -1;
void Introdu_Opt()
{
	cout << endl << "1.Introdu un student nou. " << endl << "2.Cauta un student." << endl << "3.Afiseaza toti studentii" << endl << "4.Modifica un student existent" << endl << "5.Sterge un student" << endl << "6.Iesire" << endl;
	opt = -1;
	while (opt < 0 || opt>6)
	{
		cout << endl << "Alege o optiune: " << endl;
		cin >> opt;
	}

}

int main()
{
	DataBase uni;
	int ok = 0;
	cout << "Incarcare baza de date . . . ";

// ---> Incarcam in uni inregistrarile anterioare <---
	ifstream fin("DataBase.txt");
	vector<Student> Entries_File;
	string row;
	Student Current;
	
	while (fin >> row)
	{
		do
		{
			if (row == ">>>>>")
				fin >> row;
			Current.Set_LastName(row);
			fin >> row;
			Current.Set_FirstName(row);
			fin >> row;
			Current.Set_Faculty(row);
			fin >> row;
			float temp = ::atof(row.c_str());
			Current.Set_Grade(temp);
			Entries_File.push_back(Current);
			fin >> row;
		} while (row.empty());
	}
	uni.Create(Entries_File);
	fin.close();
// ---> Incarcam in uni inregistrarile anterioare <---

	Introdu_Opt();
	while (ok == 0)
	{
		switch (opt)
		{
		case 1: // Student nou
		{
			Student x;
			string name;
			float grade;

			cout << "Nume: "; cin >> name;
			x.Set_LastName(name);

			cout << "Prenume: "; cin >> name;
			x.Set_FirstName(name);

			cout << "Facultate: "; cin >> name;
			x.Set_Faculty(name);

			cout << "Nota: "; cin >> grade;
			x.Set_Grade(grade);
			
			ofstream fout("DataBase.txt", ios::app);
			fout << endl; fout << ">>>>>"; fout << endl;
			fout << x.Get_Name(); fout << endl;
			fout << x.Get_FirstName(); fout << endl;
			fout << x.Get_Faculty(); fout << endl;
			fout << x.Get_Grade(); //fout << endl;
			
			uni.AddEntry(x);
			fout.close();
			Introdu_Opt();
			//uni.PrintAll();

			break;
		}
		case 2: // Cauta student
		{	char opt_find;
			string name_find;
			float grade_find;
			cout << endl << "Cauta dupa:" << endl << "a. Nume" << endl << "b. Facultate" << endl <<"c. Nota minima" << endl;
			cout << "Optiunea aleasa: "; cin >> opt_find;

			switch (opt_find)
			{
			case 'a':
			{	cout << endl << "Numele studentului pe care il caut: "; cin >> name_find;
				cout << endl;
				uni.FindByName(name_find);
				break; 
			}
			case 'b':
			{	cout << endl << "Numele facultatii pe care o caut: "; cin >> name_find;
				cout << endl;
				uni.FindByFaculty(name_find);
				break;
			}
			case 'c':
			{	cout << endl << "Nota minima a studentilor pe care ii caut: "; cin >> grade_find;
				cout << endl;
				uni.FindByMinimumGrade(grade_find);
				break;
			}
			default:
				break;
			}
			Introdu_Opt();
			break;
		}
		case 3: // Afiseaza toti studentii
		{	
			uni.PrintAll();
			Introdu_Opt();
			break;
		}
		case 4: // Modifica student
		{	unsigned nr = 0;
			
		while (nr < 1 || nr > uni.Get_Count())
		{
			cout << "Nr. studentului pe care il modific:(1-" << uni.Get_Count() << "): "; cin >> nr;
		}
		Student aux = uni.Get_Student(nr-1);
		aux.List();
		cout << endl;

		ofstream fout("DataBase.txt");
		for (unsigned i = 0; i < uni.Get_Count(); i++)
		{	
			fout << ">>>>>\n";
			aux = uni.Get_Student(i);
			if (nr-1 == i)
			{
				Student auxx;
				string name;
				float grade;
				cout << "Nume: "; cin >> name;
				auxx.Set_LastName(name);

				cout << "Prenume: "; cin >> name;
				auxx.Set_FirstName(name);

				cout << "Facultate: "; cin >> name;
				auxx.Set_Faculty(name);

				cout << "Nota: "; cin >> grade;
				auxx.Set_Grade(grade);

				fout << auxx.Get_Name() << "\n";
				fout << auxx.Get_FirstName() << "\n";
				fout << auxx.Get_Faculty() << "\n";
				fout << auxx.Get_Grade() << "\n";

			}
			else
			{
				fout << aux.Get_Name() << "\n";
				fout << aux.Get_FirstName() << "\n";
				fout << aux.Get_Faculty() << "\n";
				fout << aux.Get_Grade() << "\n";
			}
		}
			fout.close();
			ifstream fin("DataBase.txt");
			vector<Student> Entries_File;
			string row;
			Student Current;

			while (fin >> row)
			{
				do
				{
					if (row == ">>>>>")
						fin >> row;
					Current.Set_LastName(row);
					fin >> row;
					Current.Set_FirstName(row);
					fin >> row;
					Current.Set_Faculty(row);
					fin >> row;
					float temp = ::atof(row.c_str());
					Current.Set_Grade(temp);
					Entries_File.push_back(Current);
					fin >> row;
				} while (row.empty());
			}
			uni.Create(Entries_File);
			fin.close();
			Introdu_Opt();
			break;
		}
		case 5: // Sterge student
		{	unsigned nrr=0;
		while (nrr < 1 || nrr > uni.Get_Count())
		{
			cout << endl << "Numele studentului pe care il stergem (1-" << uni.Get_Count() << "): "; cin >> nrr;
		}
		nrr--;
		uni.DeleteStudent(nrr);
		ofstream fout("DataBase.txt");
		for (unsigned i = 0; i < uni.Get_Count(); i++)
		{
			fout << ">>>>>\n";
			Student aux = uni.Get_Student(i);
			
				fout << aux.Get_Name() << "\n";
				fout << aux.Get_FirstName() << "\n";
				fout << aux.Get_Faculty() << "\n";
				fout << aux.Get_Grade() << "\n";
			
		}
		fout.close();
		Introdu_Opt();
			break;
		}
		case 6: // Iesire
		{	cout << endl << "BAZA DE DATE INCHISA CU SUCCES!" << endl;
			ok = 1;
			break;
		}
		default:
			break;
		}
	}

	return 0;
}