
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct student {
	string name;
	double mark;
};


void getmark(student* students, int *n, string *s);
void sort(student* a, int kil);

int main()
{
	setlocale(LC_CTYPE, "ukr");
	ifstream fin;
	fin.open("students.csv");
	string s;
	getline(fin, s);
	// num - кількість бюджетників
	int num = 0, n = stoi(s);
	student* students = new student[n];

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(fin, s);
		getmark(students, &num, &s);
	}

	sort(students, num);

	int numStependiat = num * 2 / 5;

	ofstream fout;
	fout.open("rating.csv");
	for (int i = 0; i < numStependiat; i++)
		fout << students[i].name << ',' << fixed << setprecision(3) << students[i].mark << endl;


	delete[] students;
	fin.close();
	fout.close();
	system("pause");
	return 0;
}


void getmark(student* students, int* n, string *s) {

	int i = (*s).find(',');
	students[*n].name = (*s).substr(0, i);
	double sum = 0;
	int k = 0;
	while ((*s).find(',', i + 1) < (*s).length())
	{
		k++;
		sum += stoi((*s).substr(i + 1, (*s).find(',', i + 1) - i - 1));
		i = (*s).find(',', i + 1);
	}
	students[*n].mark = sum / k;
	if ((*s).substr(i + 1, (*s).length() - i - 1) == "TRUE")
		(*n)--;
	(*n)++;
}

void sort(student* a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].mark < a[j].mark)
			{
				student x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
}