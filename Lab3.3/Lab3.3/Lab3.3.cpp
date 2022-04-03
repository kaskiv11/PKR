// Lab3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct DateOfBirth
{
	int day;
	int month;
	int year;
};

struct Note
{
	string firstName;
	string lastName;
	string phone;
	DateOfBirth date;
};
void Create(Note* n, const int N);
void Print(Note* n, const int N);
void SaveToFile(Note* n, const int N, const char* filename);
void LoadFromFile(Note*& n, int& N, const char* filename);
void Sort(Note* n, const int N);
int PrintNote(Note* n, const int N, const string phone);
//void Data(Note n);


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть к-сть Note: "; cin >> N;
	Note* n = new Note[N];

	Create(n, N);
	Sort(n, N);
	Print(n, N);

	char filename[100];
	string phone;

	int menuItem;
	do {
		cout << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - сортування даних за алфавітом по днях" << endl;
		cout << " [4] - вивід телефонного записника за номером телефону" << endl;
		cout << " [7] - запис даних у файл" << endl;
		cout << " [8] - зчитування даних із файлу" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl;
		switch (menuItem)
		{
		case 1:
			Create(n, N);
			break;
		case 2:
			Print(n, N);
			break;
		case 3:
			Sort(n, N);
			break;
		case 4:
			cin.get();
			cin.sync();

			cout << "Номер телефону: "; getline(cin, phone);
			PrintNote(n, N, phone);
			break;
		case 7:
			cin.get();
			cin.sync();

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(n, N, filename);
			break;
		case 8:
			cin.get();
			cin.sync();

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(n, N, filename);
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


void Create(Note * n, const int N)
{
	for (int i = 0; i < N; i++) {
		cout << "Note № " << i + 1 << ":" << endl;
		cout << "Ім'я: "; cin >> n[i].firstName;
		cout << "Прізвище: "; cin >> n[i].lastName;
		cout << "Номер телефону: "; cin >> n[i].phone;
		cout << "День: "; cin >> n[i].date.day;
		cout << "Місяць: "; cin >> n[i].date.month;
		cout << "Рік: "; cin >> n[i].date.year;
		cout << endl;
	}
}

void Print(Note * n, const int N)
{
	cout << "=============================================================================="
		<< endl;
	cout << "|  №  |   Імя     |   Прізвище   | Номер телефону |  День |  Місяць |   Рік   |"
		<< endl;
	cout << "=============================================================================="
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1
			<< " | " << setw(9) << left << n[i].firstName
			<< " | " << setw(12) << left << n[i].lastName
			<< " | " << setw(14) << left << n[i].phone
			<< " | " << setw(5) << left << n[i].date.day
			<< " | " << setw(7) << left << n[i].date.month
			<< " | " << setw(7) << right << setprecision(2) << n[i].date.year << " |";
		cout << endl;
        cout << "------------------------------------------------------------------------------";
		cout << endl;
	}
}

void Sort(Note * n, const int N)
{
	Note tmp;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (n[j].date.day > n[j + 1].date.day) {
				tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
			}
}

void SaveToFile(Note* n, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&n[i], sizeof(Note)); // записали елементи масиву
	fout.close();
}

void LoadFromFile(Note*& n, int& N, const char* filename)
{
	delete[] n; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	n = new Note[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&n[i], sizeof(Note)); // прочитали елементи масиву
	fin.close();
}

int PrintNote(Note* n, const int N, const string phone)
{
	int stan = 0;
	for (int i = 0; i < N; i++) {
		if (n[i].phone == phone) {
			stan = 1;
			break;
		}
		else if (i == N - 1) {
			stan = -1;
			cout << "Такого записника немає" << endl;
		}
	}

	if (stan == 1) {
		cout << "=============================================================================="
			<< endl;
		cout << "|  №  |   Імя     |   Прізвище   | Номер телефону |  День |  Місяць |   Рік   |"
			<< endl;
		cout << "=============================================================================="
			<< endl;

		for (int i = 0; i < N; i++)
		{
			if (n[i].phone == phone) {
				cout << "| " << setw(3) << right << i + 1
					<< " | " << setw(9) << left << n[i].firstName
					<< " | " << setw(12) << left << n[i].lastName
					<< " | " << setw(14) << left << n[i].phone
					<< " | " << setw(5) << left << n[i].date.day
					<< " | " << setw(7) << left << n[i].date.month
					<< " | " << setw(7) << right << setprecision(2) << n[i].date.year << " |";
				cout << endl;
				cout << "------------------------------------------------------------------------------";
				cout << endl;
			}
		}
	}
	return stan;
}