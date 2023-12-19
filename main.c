#include <stdio.h>

int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char* months[] =
        {
        " ",
        "\n\n\nJanuary",
        "\n\n\nFebruary",
        "\n\n\nMarch",
        "\n\n\nApril",
        "\n\n\nMay",
        "\n\n\nJune",
        "\n\n\nJuly",
        "\n\n\nAugust",
        "\n\n\nSeptember",
        "\n\n\nOctober",
        "\n\n\nNovember",
        "\n\n\nDecember",
        };

int inputYear(void)
{
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    return year;
}

int determineDayCode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1.) / 4.;
    d2 = (year - 1.) / 100.;
    d3 = (year - 1.) / 400.;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

int determineLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        days_in_month[2] = 29;
        return 1;
    }
    else
    {
        days_in_month[2] = 28;
        return 0;
    }
}

// output the calendar
void calendar(int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        printf("%s", months[month]);
        printf("\n\nSun\tMon\tTue\tWen\tThu\tFri\tSat\n");

        // correcting the position for the first date
        for (day = 1; day <= daycode; day++)
        {
            printf("\t");
        }

        // Print all dates for one month
        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%2d", day);

            // check if the day before sat
            if ( (day + daycode) % 7 > 0)
                printf("\t");
            else
                printf("\n");
        }

        // Set position for next month
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void)
{
    int year, daycode;

    year = inputYear();
    daycode = determineDayCode(year);
    determineLeapYear(year);
    calendar(daycode);

    printf("\n");
    return 0;
}