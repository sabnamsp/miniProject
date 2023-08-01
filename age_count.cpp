#include <bits/stdc++.h>
using namespace std;

//leap year count
bool leapYear(int yr) {
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0)) 
    {
        return true;
    } else {
        return false;
    }
}

//days count from month
int daysInmonth(int month, bool leap_year) 
{
    if (month == 2 && leap_year) 
    {
        return 29;
    } else if (month == 2 && !leap_year) 
    {
        return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) 
    {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    string name;
    int age;
    time_t rawtime;
    struct tm* timeinfo;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int year = age;
    int month = year * 12 + timeinfo->tm_mon + 1;
    int days = 0;

    int beginYear = timeinfo->tm_year + 1900 - year;
    int endYear = beginYear + year;

    // Calculate the number of days
    for (int y = beginYear; y < endYear; y++) {
        if (leapYear(y)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    bool leap_year = leapYear(timeinfo->tm_year + 1900);
    for (int m = 1; m < timeinfo->tm_mon + 1; m++) 
    {
        days += daysInmonth(m, leap_year);
    }

    days += timeinfo->tm_mday;

    cout << name << "'s age is " << year << " years or " << month << " months or " << days << " days old" << endl;

    return 0;
}
