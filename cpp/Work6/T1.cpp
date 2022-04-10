#include <cstdio>

class Student {
private:
    int score;
    static int count;
    static int sum;
public:
    Student(int = 0);
    ~Student();
    void setScore(int s);
    static int getSum();
    static int getAverage();
};

Student::Student(int x) : score(x) {
    count++;
    sum += score;
}

Student::~Student() {
    count--;
    sum -= score;
}

void Student::setScore(int s) {
    sum -= score;
    score = s;
    sum += score;
}

int Student::getSum() {
    return sum;
}

int Student::getAverage() {
    return sum / count;
}

int Student::count = 0;
int Student::sum = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int t, i = 0;
    Student s[5];
    while (~scanf("%d", &t))
        s[i++].setScore(t);
    printf("%d\n%d\n", Student::getSum(), Student::getAverage());
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}