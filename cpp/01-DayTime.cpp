#include <cstdio>
#include <iostream>
#include <string>

//Max time is 23:59:59
class DayTime {
private:
    int hour;
    int minute;
    int second;
    void advance();
public:
    DayTime(int, int, int);
    DayTime(const DayTime&);
    DayTime& operator=(const DayTime&);
    bool operator==(const DayTime&);
    bool operator!=(const DayTime&);
    bool operator<(const DayTime&);
    bool operator>(const DayTime&);
    bool operator<=(const DayTime&);
    bool operator>=(const DayTime&);
    void setTime(int, int, int);
    void setTime(const char*);
    void inputTime();
    void printTime();
    char* getTime_s();
    int getHour();
    int getMinute();
    int getSecond();
    int getSeconds();
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    DayTime nextSeconds(int);
    DayTime nextMinutes(int);
    DayTime nextHours(int);
    DayTime nextSecond();
    DayTime nextMinute();
    DayTime nextHour();
    int Span(DayTime);
};

inline DayTime::DayTime(int hh=0, int mm=0, int ss=0) {
    hour = hh;
    minute = mm;
    second = ss;
    advance();
}

inline DayTime::DayTime(const DayTime& T) {
    *this = T;
}

inline DayTime& DayTime::operator=(const DayTime& T) {
    hour = T.hour;
    minute = T.minute;
    second = T.second;
    return *this;
}

inline bool DayTime::operator==(const DayTime& T) {
    return (hour == T.hour && minute == T.minute && second == T.second);
}

inline bool DayTime::operator!=(const DayTime& T) {
    return (hour != T.hour || minute != T.minute || second != T.second);
}

inline bool DayTime::operator<(const DayTime& T) {
    if (hour < T.hour) return true;
    if (hour == T.hour && minute < T.minute) return true;
    if (hour == T.hour && minute == T.minute && second < T.second) return true;
    return false;
}

inline bool DayTime::operator>(const DayTime& T) {
    if (hour > T.hour) return true;
    if (hour == T.hour && minute > T.minute) return true;
    if (hour == T.hour && minute == T.minute && second > T.second) return true;
    return false;
}

inline bool DayTime::operator<=(const DayTime& T) {
    if (hour < T.hour) return true;
    if (hour == T.hour && minute < T.minute) return true;
    if (hour == T.hour && minute == T.minute && second <= T.second) return true;
    return false;
}

inline bool DayTime::operator>=(const DayTime& T) {
    if (hour > T.hour) return true;
    if (hour == T.hour && minute > T.minute) return true;
    if (hour == T.hour && minute == T.minute && second >= T.second) return true;
    return false;
}

void DayTime::setTime(int hh, int mm, int ss) {
    hour = hh;
    minute = mm;
    second = ss;
    advance();
}

void DayTime::setTime(const char* time) {
    int hh, mm, ss;
    sscanf(time, "%d:%d:%d", &hh, &mm, &ss);
    setTime(hh, mm, ss);
}

void DayTime::inputTime() {
    printf("Please input time(hh:mm:ss): ");
    char time[10];
    scanf("%s", time);
    setTime(time);
}

void DayTime::printTime() {
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

char* DayTime::getTime_s() {
    char* time = new char[10];
    sprintf(time, "%02d:%02d:%02d", hour, minute, second);
    return time;
}

inline void DayTime::advance() {
    if (second >= 60 || second < 0) {
        minute += second / 60;
        second %= 60;
    }
    if (minute >= 60 || minute < 0) {
        hour += minute / 60;
        minute %= 60;
    }
    if (hour >= 24 || hour < 0) {
        hour %= 24;
    }
    if (hour < 0 || minute < 0 || second < 0) {
        if (second < 0) {
            minute -= 1;
            second += 60;
        }
        if (minute < 0) {
            hour -= 1;
            minute += 60;
        }
        if (hour < 0) {
            hour += 24;
        }
    }
}

inline int DayTime::getHour() {
    return hour;
}

inline int DayTime::getMinute() {
    return minute;
}

inline int DayTime::getSecond() {
    return second;
}

inline int DayTime::getSeconds() {
    return hour * 3600 + minute * 60 + second;
}

inline void DayTime::setHour(int hh) {
    hour = hh;
    advance();
}

inline void DayTime::setMinute(int mm) {
    minute = mm;
    advance();
}

inline void DayTime::setSecond(int ss) {
    second = ss;
    advance();
}

DayTime DayTime::nextSeconds(int ss) {
    DayTime T(*this);
    T.setSecond(second + ss);
    return T;
}

DayTime DayTime::nextMinutes(int mm) {
    DayTime T(*this);
    T.setMinute(minute + mm);
    return T;
}

DayTime DayTime::nextHours(int hh) {
    DayTime T(*this);
    T.setHour(hour + hh);
    return T;
}

inline DayTime DayTime::nextSecond() {
    return nextSeconds(1);
}

inline DayTime DayTime::nextMinute() {
    return nextMinutes(1);
}

inline DayTime DayTime::nextHour() {
    return nextHours(1);
}

int DayTime::Span(DayTime T) {
    return abs(getSeconds() - T.getSeconds());
}

//Tester
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    //Why need a tester?
    DayTime t1;
    t1.printTime();
    t1.setTime(12, 34, 56);
    t1.printTime();
    t1.setTime("01:23:45");
    t1.printTime();
    t1.inputTime(); //Input time from file: 12:34:57
    t1.printTime();
    DayTime t2(22, 58, 59);
    t2.printTime();
    std::cout << t2.getSeconds() << std::endl;
    t2.nextSecond().printTime();
    std::cout << t2.nextSecond().getSeconds() << std::endl;
    t2.nextMinute().printTime();
    std::cout << t2.nextMinute().getSeconds() << std::endl;
    t2.nextHour().printTime();
    std::cout << t2.nextHour().getSeconds() << std::endl;
    t2.nextSeconds(2).printTime();
    std::cout << t2.nextSeconds(2).getSeconds() << std::endl;
    t2.nextMinutes(2).printTime();
    std::cout << t2.nextMinutes(2).getSeconds() << std::endl;
    t2.nextHours(2).printTime();
    std::cout << t2.nextHours(2).getSeconds() << std::endl;

    std::cout << std::endl;

    std::cout << "Set time -26:-67:-89, check advance()." << std::endl;
    t1.setTime(-26, -67, -89);
    t1.printTime();
    std::cout << "Set time -12:-34:-56, check advance()." << std::endl;
    t1.setTime(-12, -34, -56);
    t1.printTime();

    std::cout << std::endl;

    std::cout << "Check Span()." << std::endl;
    t1.setTime("06:55:24");
    t2.setTime(22, 36, 14);

    std::cout << "t1.Span(t1):" << t1.Span(t1) << std::endl;
    std::cout << "t1.Span(t2):" << t1.Span(t2) << std::endl;
    std::cout << "t2.Span(t1):" << t2.Span(t1) << std::endl;
    std::cout << "t2.Span(t2):" << t2.Span(t2) << std::endl;

    std::cout << std::endl;

    std::cout << "Legel check." << std::endl;
    char* s;
    for (int i = -50;i <= 50;i++)
        for (int j = -99;j <= 99;j++)
            for (int k = -99;k <= 99;k++) {
                t1.setTime(i, j, k);
                s = t1.getTime_s();
                printf("%3d:%3d:%3d - %s\n", i, j, k, s);
                delete s;
            }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}