// Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.

#include <stdio.h>

int day_of_year(int year, int month, int day);
char *month_name(int n);
void month_day(int year, int day, int *pday, int *pmonth);

int day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    int day = day_of_year(2024, 2, 29); // Leap year, valid
    printf("Day of year: %d\n", day);

    int month, mday;
    month_day(2024, 60, &mday, &month);
    printf("Month: %d, Day: %d\n", month, mday);

    // Error cases
    day_of_year(2024, 2, 30);            // Invalid
    month_day(2024, 367, &mday, &month); // Invalid

    return 0;
}

//
int day_of_year(int year, int month, int day)
{
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int *p = *(day_table + leap); 

    if (month < 0 || month > 12 || year < 0)
    {
        printf("Error: Invalid year or month.\n");
        ;
        return -1;
    }

    if (day < 1 || day > *(p + month))
    {
        printf("Error: %d is a invalid day for month %d\n", day, month);
        return -1;
    }

    for (int i = 1; i < month; i++)
    {
        day += *(p + i);
    }
    return day;
}

void month_day(int year, int day, int *pday, int *pmonth)
{
    if (year < 0)
    {
        printf("Error: Can't use negative values");
        return;
    }

    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int i;
    int *p = *(day_table + leap);

    if (day < 1 || day > (leap ? 366 : 365))
    {
        printf("Error: Day %d is invalid for year %d\n", day, year);
        return;
    }

    for (i = 1; day > *(p + i); i++)
    {
        day -= *(p + i);
    }
    *pmonth = i;
    *pday = day;
}

char *month_name(int n)
{
    static char *name[] = {
        "Invalid month", 
        "January", "Febrary", "March", 
        "April", "May", "June", 
        "July", "August", "September", 
        "October", "November", "December"};
    
    return (n < 1 || n > 12)? name[0] : name[n];
}
