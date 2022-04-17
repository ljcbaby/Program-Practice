#include <cstdio>

class Date {
protected:
    int year;
    int month;
    int day;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Time {
protected:
    int hour;
    int minute;
    int second;
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
};

class Schedule : public Date, public Time {
private:
    int ID;
public:
    Schedule(int y, int m, int d, int h, int mn, int s, int id) : Date(y, m, d), Time(h, mn, s), ID(id) {}
    bool operator < (const Schedule&) const;
    void print() const;
};

inline bool Schedule::operator < (const Schedule& s) const {
    if (year < s.year) return true;
    if (year > s.year) return false;
    if (month < s.month) return true;
    if (month > s.month) return false;
    if (day < s.day) return true;
    if (day > s.day) return false;
    if (hour < s.hour) return true;
    if (hour > s.hour) return false;
    if (minute < s.minute) return true;
    if (minute > s.minute) return false;
    if (second < s.second) return true;
    if (second > s.second) return false;
    return ID < s.ID;
}

inline void Schedule::print() const {
    printf("No.%d: %d/%d/%d %d:%d:%d", ID, year, month, day, hour, minute, second);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int y, m, d, h, mn, s, id;
    scanf("%d %d/%d/%d %d:%d:%d", &id, &y, &m, &d, &h, &mn, &s);
    Schedule s1(y, m, d, h, mn, s, id);
    scanf("%d", &id);
    while (id) {
        scanf("%d/%d/%d %d:%d:%d", &y, &m, &d, &h, &mn, &s);
        Schedule s2(y, m, d, h, mn, s, id);
        if (s2 < s1) s1 = s2;
        scanf("%d", &id);
    }
    printf("The urgent schedule is ");
    s1.print();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
