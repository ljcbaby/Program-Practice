#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    Teacher(string nam, int a, string t) {
        name = nam;
        age = a;
        title = t;
    }
    void display() {
        cout << "name:" << name << endl;
        cout << "age" << age << endl;
        cout << "title:" << title << endl;
    }
protected:
    string name;
    int age;
    string title;
};

class Student {
public:
    Student(string nam, char s, float sco) {
        name1 = nam;
        sex = s;
        score = sco;
    }
    void display1() {
        cout << "name:" << name1 << endl;
        cout << "sex:" << sex << endl;
        cout << "score:" << score << endl;
    }
protected:
    string name1;
    char sex;
    float score;
};

class Graduate : public Student, public Teacher {
private:
    float wages;
public:
    Graduate(string name, int age, char sex, string title, float score, float wages) : Student(name, sex, score), Teacher(name, age, title), wages(wages) {}
    void show() {
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "sex:" << sex << endl;
        cout << "score:" << score << endl;
        cout << "title:" << title << endl;
        cout << "wages:" << wages << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Graduate grad1("Wang-li", 24, 'f', "assistant", 89.5, 1234.5);
    grad1.show();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
