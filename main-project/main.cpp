#include <iostream>

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
		for (int i = 0; i < size; i++)
		{
			cout << results[i]->ucastnik.umber << '\n';
			cout << results[i]->ucastnik.last_name << '\n';
			cout << results[i]->ucastnik.first_name << '\n';
			cout << results[i]->ucastnik.middle_name << '\n';
			cout << results[i]->finish.hour << ' ';
			cout << results[i]->finish.minut << ' ';
			cout << results[i]->finish.second << '\n';
			cout << results[i]->start.hour << ' ';
			cout << results[i]->start.minut << ' ';
			cout << results[i]->start.second << '\n';
			cout << results[i]->club << '\n';
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