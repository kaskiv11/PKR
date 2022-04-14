// Lab3.1B.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Course { I = 1, II, III, IV, V, VI };

string CourseStr[] = {
	"I", "II", "III", "IV", "V", "VI"
};

enum Specialty {
	KN, INF, MATHandECONOMY, PHYSICALEDUCATIONandINFORMAT, WORKTRAINING
};

string SpecialtyStr[] = {
	"Компютерні науки",
	"Інформатика",
	"Математика та еконм",
	"Фіз. та інформ.",
	"Труд. навчання"
};

struct Student {
	string lastName;
	Course сourse;
	Specialty specialty;
	int physics, maths;
	union {
		int programming;
		int numMethods;
		int pedagogy;
	};
};

void Create(Student* student, const int N);
void Print(Student* student, const int N);
double LineSearchPhysics(Student *s, const int N);
int searchForPhysics(Student *s, const int N);
int LineSearchPhysics5(Student* s, const int N);
int LineSearchPhysics4(Student* s, const int N);
int LineSearchPhysics3(Student* s, const int N);


void Create(Student* student, const int N) {
	int course, speciality;
	for (int i = 0; i < N; i++) {
		cout << "Студент № " << i + 1 << ":" << endl;
		cout << "Прізвище: "; cin >> student[i].lastName;
		cout << "Курс: "; cin >> course;
		student[i].сourse = (Course)course;
		cout << "Спеціальність: 0 - Комп’ютерні науки,  1 - Інформатика, \n 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання"
			<< endl << "Введіть спеціальність: ";
		cin >> speciality;        student[i].specialty = (Specialty)speciality;
		cout << "Оцінка з фізики: "; cin >> student[i].physics;
		cout << "Оцінка з математики: "; cin >> student[i].maths;
		switch (student[i].specialty) {
		case KN:
			cout << "Оцінка з програмування:"; cin >> student[i].programming;
			break;
		case INF:
			cout << "Оцінка з чисельних методів:"; cin >> student[i].numMethods;
			break;
		case MATHandECONOMY:
		case PHYSICALEDUCATIONandINFORMAT:
		case WORKTRAINING:
			cout << "Оцінка з педагогіки:"; cin >> student[i].pedagogy;
			break;
		}
		cout << endl;
	}
}



void Print(Student* student, const int N) {
	cout << "==================================================================================================="
		<< endl;
	cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "==================================================================================================="
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << right << i + 1 << " ";
		cout << "| " << setw(11) << left << student[i].lastName
			<< "| " << setw(4) << right << CourseStr[(int)student[i].сourse - 1] << " "
			<< "| " << setw(18) << left << SpecialtyStr[student[i].specialty]
			<< "| " << setw(6) << right << student[i].physics << " "
			<< "| " << setw(6) << right << student[i].maths << " ";
		switch (student[i].specialty) {
		case KN:
			cout << "| " << setw(8) << right
				<< student[i].programming << " | " << setw(12) << right
				<< " | " << setw(12) << right << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(11) << right
				<< " | " << setw(9) << right << student[i].numMethods
				<< " | " << setw(12) << right << " |" << endl;
			break;
		case  MATHandECONOMY:
		case PHYSICALEDUCATIONandINFORMAT:
		case WORKTRAINING:
			cout << "| " << setw(11) << right
				<< " | " << setw(12) << right
				<< " | " << setw(10) << right << student[i].pedagogy << " |" << endl;
			break;
		}
	}
	cout << "===================================================================================================" << endl;
	cout << endl;
}

int searchForPhysics(Student *s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 4 || s[i].physics == 5)
		{

			if (s[i].maths == 4 || s[i].maths == 5) {
				k++;
			}
		}
	}
	return k;
}

double LineSearchPhysics(Student* s, const int N)
{
	int k = 0, l = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics)
		{
			if (s[i].physics == 5) {
				k++;
			}
			if (s[i].physics == 4) {
				l++;
			}
			if (s[i].physics == 3) {
				n++;
			}
		}
	}
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«5» з фізики : " << k << endl;
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«4» з фізики : " << l << endl;
	cout << " Кількість  студентів які отримали оцінку " << endl;
	cout << "«3» з фізики : " << n << endl;
	return  0;
}


int LineSearchPhysics5(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 5) {
			k++;
		}
	}
	return k;
}


int LineSearchPhysics4(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 4) {
			k++;
		}
	}
	return k;
}

int LineSearchPhysics3(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 3) {
			k++;
		}
	}
	return k;
}


int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);
	LineSearchPhysics(s, N);
	cout << "Кількість  студентів які отимали з фізики та математики 4 або 5: " << searchForPhysics(s, N) << endl;
	cout << "Кількість  студентів які отимали з фізики 5: " << LineSearchPhysics5(s, N) << endl;
	cout << "Кількість  студентів які отимали з фізики 4: " << LineSearchPhysics4(s, N) << endl;
	cout << "Кількість  студентів які отимали з фізики 3: " << LineSearchPhysics3(s, N) << endl;
	return 0;
}