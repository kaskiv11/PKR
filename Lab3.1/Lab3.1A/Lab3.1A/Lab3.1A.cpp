#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

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
	int сourse;
	Specialty specialty;
	int physics, maths;
	int comp_science;
};

void Create(Student* student, const int N);
void Print(Student* student, const int N);
double LineSearchPhysics(Student *s, const int N);
int searchForPhysics(Student *s, const int N);
int LineSearchPhysics5(Student* s, const int N);
int LineSearchPhysics4(Student* s, const int N);
int LineSearchPhysics3(Student* s, const int N);



void Create(Student* s, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << " Студент № " << i + 1 << ":" << endl;

		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище: ";
		getline(cin, s[i].lastName);
		cout << " Курс: ";
		cin >> s[i].сourse;
		cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: ";
		cin >> s[i].physics;
		cout << " Оцінка з математики: ";
		cin >> s[i].maths;
		cout << " Оцінка з інформатики: ";
		cin >> s[i].comp_science;
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	cout << "=========================================================================================================="
		<< endl;
	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Інформатика | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << " | " << setw(2) << right << i + 1 << " ";
		cout << " | " << setw(14) << left << s[i].lastName;
		cout << " |  " << setw(2) << right << s[i].сourse << " ";
		cout << " | " << setw(23) << left << SpecialtyStr[s[i].specialty];
		cout << " | " << setw(4) << right << s[i].physics << "  ";
		cout << " | " << setw(6) << right << s[i].maths << "    ";
		cout << " | " << setw(6) << right << s[i].comp_science << "   " << "   |";
		cout << endl;
	}
	cout << "=========================================================================================================="
		<< endl;
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

