#include <stdio.h>


int isLeapYear(int year);
int getFirstDayOfYear(int year);
void printMonth(int year, int month, int startDay);


const char *months[] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    } else {
        daysInMonth[1] = 28;
    }

    int startDay = getFirstDayOfYear(year);
    for (int month = 0; month < 12; month++) {
        printMonth(year, month, startDay);
        startDay = (startDay + daysInMonth[month]) % 7;
    }

    system("pause"); // Waits for user to press any key to continue
    return 0;
}


int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)) {
        return 1;
    } else
        return 0;
}


int getFirstDayOfYear(int year) {
    int day = 1;
    for (int y = 1; y < year; y++) {
        if (isLeapYear(y)) {
            day += 366;
        } else {
            day += 365;
        }
    }
    return day % 7;
}


void printMonth(int year, int month, int startDay) {
    printf("\n\n  ------------%s %d------------\n", months[month], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int day;
    // Print leading spaces
    for (day = 0; day < startDay; day++) {
        printf("     ");
    }

    // Print days of the month
    for (int date = 1; date <= daysInMonth[month]; date++) {
        printf("%5d", date);
        if (++day > 6) {
            printf("\n");
            day = 0;
        }
    }
    if (day != 0) {
        printf("\n");
    }
}
