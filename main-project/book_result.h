#ifndef BOOK_RESULT_H
#define BOOK_RESULT_H
#include "constants.h"
struct times
{
	int hour;
	int minut;
	int second;
};
struct participant
{
	int umber;
	char first_name[MAX_STRING_SIZE];
	char middle_name[MAX_STRING_SIZE];
	char last_name[MAX_STRING_SIZE];
};
struct book_result
{
	participant ucastnik;
	times start;
	times finish;
	char club[MAX_STRING_SIZE];
};
#endif