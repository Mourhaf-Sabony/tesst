#include<iostream>
#include<cstdio>
#include "read.h"

using namespace std;

bool is_leap_year(short year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short number_of_days_in_month(short year, short month)
{
	if (month < 1 || month > 12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return month == 2 ? (is_leap_year(year) ? 29 : 28) : days[month - 1];
}

short get_day_order(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + 12 * a - 2;

	return  (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string month_name(short month_number)
{
	string arr[] = { "","Jan","Feb","Mar","Apr","May","Jun"
	,"Jul","Aug","Sep","Oct","Nov","Dec" };

	return arr[month_number];
}

void print_month_calendar(short year, short month)
{
	short days_number = number_of_days_in_month(year, month);

	short order_of_month = get_day_order(1, month, year);

	cout << "\n  _______________" << month_name(month) << "_______________" << endl;
	cout << "\n  Sun  Mon  Tue  Wed  Thu  Fru  Sat" << endl;

	short i;
	for (i = 0; i < order_of_month; i++)
		cout << "     ";

	for (short j = 1; j <= days_number; j++)
	{
		printf("%5d", j);
		if (++ i == 7)
		{
			i = 0;
			cout << "\n";
		}

	}

	cout << "\n  _________________________________\n";
}

void print_year_calendar(short year)
{
	cout << "\n  _________________________________\n";
	cout << "\n\t  Calendar - " << year;
	cout << "\n  _________________________________\n";
	
	for (short i = 1; i <= 12; i++)
	{
		print_month_calendar(year, i);
	}
}

int main() {

	short year = read::read_number("enter the year ? ");
	
	print_year_calendar(year);

	return 0;
}

