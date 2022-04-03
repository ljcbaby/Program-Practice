#include <cstdio>

class Time {
private:
    int days;
    int hours;
    int minutes;
public:
    Time(int = 0, int = 0, int = 0);
    Time(const Time&);
    Time Sum(const Time&);
    void Show() const;
    void Input();
};

Time::Time(int d, int h, int m) {
    days = d;
    hours = h;
    minutes = m;
}

Time::Time(const Time& t) {
    days = t.days;
    hours = t.hours;
    minutes = t.minutes;
}

Time Time::Sum(const Time& t) {
    Time sum(*this);
    sum.minutes += t.minutes;
    sum.hours += sum.minutes / 60;
    sum.minutes %= 60;
    sum.hours += t.hours;
    sum.days += sum.hours / 24;
    sum.hours %= 24;
    sum.days += t.days;
    return sum;
}

void Time::Show() const {
    printf("%d %d %d\n", days, hours, minutes);
}

void Time::Input() {
    scanf("%d %d %d", &days, &hours, &minutes);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Time t1, t2;
    t1.Input();
    t2.Input();
    Time t3 = t1.Sum(t2);
    t3.Show();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}