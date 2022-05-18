#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <cstring>
times convert(char* str)
{
	times result;
	char* context = NULL;
	char* str_number = strtok_s(str, ".", &context);
	result.hour = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.minut = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.second = atoi(str_number);
	return result;
}
void read(const char* file_name, book_result* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			book_result* item = new book_result;
			file >> item->ucastnik.umber;
			file >> item->ucastnik.last_name;
			file >> item->ucastnik.first_name;
			file >> item->ucastnik.middle_name;
			file >> tmp_buffer;
			item->start = convert(tmp_buffer);
			file >> tmp_buffer;
			item->finish = convert(tmp_buffer);
			file.read(tmp_buffer, 1); // чтения лишнего символа пробела
			file.getline(item->club, MAX_STRING_SIZE);
			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "Ошибка открытия файла";
	}
}