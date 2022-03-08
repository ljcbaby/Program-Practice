#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>

// map month to days
const int daysInMonth[ ][12] = {
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// a day from 1900/1/1
class Date {
private:
    int year;
    int month;
    int day;
    // Valid check
    bool isValid();
    // Valid process
    void advance();
    // Leap year check
    bool isLeapYear(int) const;
public:
    // constructor

    // default 1900/1/1
    Date(int, int, int);
    // copy constructor
    Date(const Date& date);
    // create from string
    Date(const std::string& date);
    // create from char*
    Date(const char* date);

    // assignment operator
    Date& operator=(const Date& date);

    // getter

    // return year
    int getYear() const;
    // return month
    int getMonth() const;
    // return day
    int getDay() const;

    // setter

    // set year
    void setYear(int YYYY);
    // set month
    void setMonth(int MM);
    // set day
    void setDay(int DD);
    // set date
    // default 1900/1/1
    void setDate(int, int, int);

    // adder

    // add year
    void addYears(int years);
    // add month
    void addMonths(int months);
    // add day
    void addDays(int days);

    // compare

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>(const Date&) const;
    bool operator>=(const Date&) const;

    // Leap year or not
    bool isLeapYear() const;

    // IO

    // format: YYYY/MM/DD or YYYY-MM-DD or YYYY.MM.DD
    friend std::istream& operator>>(std::istream&, Date&);
    // format: YYYY-MM-DD
    friend std::ostream& operator<<(std::ostream&, const Date&);

    // get date from file
    // default FILE is stdin
    // default format: %4d-%2d-%2d(YYYY-MM-DD)
    void Input(FILE*, char* format);

    // output date to file
    // default FILE is stdout
    // default format: %4d-%20d-%02d(YYYY-MM-DD)
    void Print(FILE*, char* format) const;

    // others

    // return x days after the date
    Date NextDays(int x) const;
    // return the days of the year
    int Days() const;
    // return the days from 1900/1/1
    int DaysFrom1900() const;
    // return the day of the week, with 0~6 indicating Sunday to Saturday
    // Kim larsen calculation formula
    int WeekDay() const;
    // return the days between two dates
    int Span(Date date) const;
};

bool Date::isValid() {
    if (year < 1753) { exit(1); }
    if (year > 9999) { return false; }
    if (month < 1 || month > 12) { return false; }
    if (day < 1 || day > daysInMonth[isLeapYear()][month - 1]) { return false; }
    return true;
}

void Date::advance() {
    while (!isValid()) {
        // if month is negative, minus year
        if (month < 1) {
            year--;
            month += 12;
            continue;
        }
        // if month is over, add year
        if (month > 12) {
            month -= 12;
            year += 1;
            continue;
        }
        // if day is negative, minus month
        if (day < 1) {
            month--;
            day += daysInMonth[isLeapYear()][month - 1];
            continue;
        }
        // if day is over, add month
        if (day > daysInMonth[isLeapYear()][month - 1]) {
            day -= daysInMonth[isLeapYear()][month - 1];
            month += 1;
            continue;
        }
        if (year < 1900) { exit(1); }
    }
}

inline bool Date::isLeapYear(int YYYY) const {
    return (YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0;
}

Date::Date(int YYYY = 1900, int MM = 1, int DD = 1) {
    year = YYYY;
    month = MM;
    day = DD;
    advance();
}
Date::Date(const Date& date) { *this = date; }
Date::Date(const std::string& date) {
    sscanf(date.c_str(), "%d%*c%d%*c%d", &year, &month, &day);
    advance();
}
Date::Date(const char* date) {
    sscanf(date, "%d%*c%d%*c%d", &year, &month, &day);
    advance();
}

inline Date& Date::operator=(const Date& date) {
    year = date.year;
    month = date.month;
    day = date.day;
    return *this;
}

inline int Date::getYear() const { return year; }
inline int Date::getMonth() const { return month; }
inline int Date::getDay() const { return day; }
inline void Date::setYear(int YYYY) { year = YYYY; advance(); }
inline void Date::setMonth(int MM) { month = MM; advance(); }
inline void Date::setDay(int DD) { day = DD; advance(); }
inline void Date::setDate(int YYYY, int MM, int DD) {
    year = YYYY;
    month = MM;
    day = DD;
    advance();
}
inline void Date::addYears(int years) { year += years; advance(); }
inline void Date::addMonths(int months) { month += months; advance(); }
inline void Date::addDays(int days) { day += days; advance(); }

inline bool Date::operator==(const Date& date) const {
    return year == date.year && month == date.month && day == date.day;
}
inline bool Date::operator!=(const Date& date) const { return !(*this == date); }
inline bool Date::operator<(const Date& date) const {
    if (year < date.year) return true;
    if (year > date.year) return false;
    if (month < date.month) return true;
    if (month > date.month) return false;
    return day < date.day;
}
inline bool Date::operator<=(const Date& date) const { return !(*this > date); }
inline bool Date::operator>(const Date& date) const { return date < *this; }
inline bool Date::operator>=(const Date& date) const { return !(*this < date); }

inline bool Date::isLeapYear() const {
    return isLeapYear(year);
}

std::istream& operator>>(std::istream& is, Date& date) {
    char ch;
    is >> date.year >> ch >> date.month >> ch >> date.day;
    date.advance();
    return is;
}
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << date.year << '-'
        << std::setw(2) << std::setfill('0') << date.month << '-'
        << std::setw(2) << std::setfill('0') << date.day;
    return os;
}
inline void Date::Input(FILE* fp = stdin, char* format = (char*)"%4d-%2d-%2d") {
    fscanf(fp, format, &year, &month, &day);
    advance();
}
inline void Date::Print(FILE* fp = stdout, char* format = (char*)"%4d-%02d-%02d") const {
    fprintf(fp, format, year, month, day);
}

inline Date Date::NextDays(int x) const {
    Date date = *this;
    date.addDays(x);
    return date;
}

inline int Date::Days() const {
    int days = day;
    for (int i = 1; i < month; i++)
        days += daysInMonth[isLeapYear()][i - 1];
    return days;
}

inline int Date::DaysFrom1900() const {
    int days = Days();
    for (int i = 1900; i < year; i++)
        days += 365 + isLeapYear(i);
    return days;
}

int Date::WeekDay() const {
    int Y = year, M = month, D = day;
    if (M < 3) {
        Y--;
        M += 12;
    }
    return (D + 2 * M + 3 * (M + 1) / 5 + Y + Y / 4 - Y / 100 + Y / 400 + 1) % 7;
}

inline int Date::Span(Date date) const {
    return abs(DaysFrom1900() - date.DaysFrom1900());
}

//Tester
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    //Why need a tester?
    Date date;
    date.Print();printf("\n");
    Date date1(2000, 2, 1);
    std::cout << date1 << std::endl;
    Date date2("2003-01-01");
    date2.Print();printf("\n");
    Date date3((char*)"2004-01-01");
    date3.Print();printf("\n");
    Date date4(date);
    date4.Print();printf("\n");
    date4 = date2;
    date4.Print();printf("\n\n");

    date.setDate(2000, 2, 28);
    date.addDays(1);
    date1.setDate(2001, 2, 28);
    date1.addDays(1);
    date2.setDate(2002, 2, 28);
    date2.addDays(1);
    date3.setDate(2003, 2, 28);
    date3.addDays(1);
    date4.setDate(2004, 2, 28);
    date4.addDays(1);
    date.Print();printf("\n");
    date1.Print();printf("\n");
    date2.Print();printf("\n");
    date3.Print();printf("\n");
    date4.Print();printf("\n\n");

    std::cout << date.isLeapYear() << " "
        << date1.isLeapYear() << " "
        << date2.isLeapYear() << " "
        << date3.isLeapYear() << " "
        << date4.isLeapYear() << std::endl << std::endl;
    std::cout << date.Days() << " "
        << date1.Days() << " "
        << date2.Days() << " "
        << date3.Days() << " "
        << date4.Days() << std::endl << std::endl;
    std::cout << date.DaysFrom1900() << " "
        << date1.DaysFrom1900() << " "
        << date2.DaysFrom1900() << " "
        << date3.DaysFrom1900() << " "
        << date4.DaysFrom1900() << std::endl << std::endl;
    std::cout << date.WeekDay() << " "
        << date1.WeekDay() << " "
        << date2.WeekDay() << " "
        << date3.WeekDay() << " "
        << date4.WeekDay() << std::endl << std::endl;
    std::cout << date.Span(date1) << std::endl;

    date.setDate(1900, 1, 1);
    for (int i = 0; i < 73200; i++) {
        std::cout << std::setw(7) << date.DaysFrom1900() << " "
            << date << " " << date.WeekDay() << " "
            << date.DaysFrom1900() % 7 << std::endl;
        if (date.WeekDay() != date.DaysFrom1900() % 7)
            break;
        date.addDays(1);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}