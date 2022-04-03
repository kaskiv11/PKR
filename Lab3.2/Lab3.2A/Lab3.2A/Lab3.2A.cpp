// Lab3.2A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	int physics;
	int maths;
	int comp_science;
	
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void PrintIndexSorted(Student* s, int* I, const int N);
int BinSearch(Student* s, const int N, const string lastName, const int course, const int physics);
void Sort(Student* s, const int N);
int* IndexSort(Student* s, const int N);

void Create(Student* s, const int N) {
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



void Print(Student* s, const int N) {
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


int BinSearch(Student* s, const int N, const string lastName, const int course, const int physics)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній 
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (s[m].lastName == lastName && s[m].сourse == course && s[m].physics == physics)
			return m;
		if ((s[m].сourse < (int)course)
			||
			(s[m].сourse == course &&
				s[m].lastName < lastName)
			||
			(s[m].сourse == course &&
				s[m].lastName == lastName &&
				s[m].physics < physics))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}

int* IndexSort(Student* s, const int N) {
	int* I = new int[N]; // створили індексний масив
	for (int i = 0; i < N; i++)
		I[i] = i; // заповнили його початковими даними
	int i, j, value; // починаємо сортувати масив індексів
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((s[I[j]].physics > s[value].physics)
				||
				(s[I[j]].physics == s[value].physics &&
					s[I[j]].сourse > s[value].сourse)
				||
				(s[I[j]].physics == s[value].physics &&
					s[I[j]].сourse == s[value].сourse &&
					s[I[j]].lastName < s[value].lastName));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}

void PrintIndexSorted(Student* s, int* I, const int N) {
	cout << "=========================================================================================================="
		<< endl;
	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Інформатика | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << " | " << setw(2) << right << i + 1 << " ";
		cout << " | " << setw(14) << left << s[I[i]].lastName;
		cout << " |  " << setw(2) << right << s[I[i]].сourse << " ";
		cout << " | " << setw(23) << left << SpecialtyStr[s[I[i]].specialty];
		cout << " | " << setw(4) << right << s[I[i]].physics << "  ";
		cout << " | " << setw(6) << right << s[I[i]].maths << "    ";
		cout << " | " << setw(6) << right << s[I[i]].comp_science << "   " << "   |";
		cout << endl;
	}
	cout << "=========================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* s, const int N) {
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((s[i1].сourse > s[i1 + 1].сourse)
				||
				(s[i1].сourse == s[i1 + 1].сourse &&
					s[i1].lastName > s[i1 + 1].lastName)
				||
				(s[i1].сourse == s[i1 + 1].сourse &&
					s[i1].lastName == s[i1 + 1].lastName &&
					s[i1].physics > s[i1 + 1].physics))
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
}

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];
	string lastName;
	int isphysics, found, course, physics;

	//LineSearchPhysics(s, N);
	//cout << "Кількість  студентів які отимали з фізики та математики 4 або 5: " << searchForPhysics(s, N);


	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - бінарний пошук студент за прізвищем, курсом і оцінкою з фізики" << endl;
		cout << " [5] - індексне впорядкування та вивід даних" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Sort(s, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cout << " прізвище: "; cin >> lastName;
			cout << " курс: "; cin >> course;
			cout << "Спеціальність:0 - Комп’ютерні науки, 1 - Інформатика, \n 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання"
				<< endl << "Введіть оцінку з фізики: ";
			cin >> isphysics;
			physics = (int)isphysics;
			if ((found = BinSearch(s, N, lastName, course, physics)) != -1)
				cout << "Знайдено студента в позиції " << found + 1 << endl;
			else
				cout << "Шуканого студента не знайдено" << endl;
			break;
		case 5:
			PrintIndexSorted(s, IndexSort(s, N), N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}