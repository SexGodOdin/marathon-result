#include <iostream>
#include <iomanip>

using namespace std;

#include "book_result.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №1. GIT\n";
	cout << "Вариант №1. Результаты марафона\n";
	cout << "Автор: Вадим Макаров\n\n";
	book_result* results[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", results, size);
		cout << "Результаты марафона\n\n";
		for (int i = 0; i < size; i++)
		{
			cout << results[i]->ucastnik.umber << '\n';
			cout << results[i]->ucastnik.last_name << " ";
			cout << results[i]->ucastnik.first_name[0] << ". ";
			cout << results[i]->ucastnik.middle_name[0] << ".";
			cout << '\n';
			cout << setw(2) << setfill('0') << results[i]->start.hour << ':';
			cout << setw(2) << setfill('0') << results[i]->start.minut << ':';
			cout << setw(2) << setfill('0') << results[i]->start.second;
			cout << '\n';
			cout << setw(2) << setfill('0') << results[i]->finish.hour << ':';
			cout << setw(2) << setfill('0') << results[i]->finish.minut << ':';
			cout << setw(2) << setfill('0') << results[i]->finish.second;
			cout << ", ";
			cout << ' ' << results[i]->club;
			cout << '\n';
		}
		for (int i = 0; i < size; i++)
		{
			delete results[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}