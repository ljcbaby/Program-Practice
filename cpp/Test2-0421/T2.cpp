#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    std::string sex;
    std::string ID;
    std::string Birthday;
public:
    Person(std::string name, std::string sex, std::string ID, std::string Birthday) {
        Person::name = name;
        Person::sex = sex;
        Person::ID = ID;
        Person::Birthday = Birthday;
    }
    virtual void show() {
        std::cout << "Name:" << name << " Sex:" << sex << " Identity card:" << ID << " Birthday:" << Birthday << std::endl;
    }
};

class Student :virtual public Person {
protected:
    std::string num;
    int score;
public:
    Student(std::string name, std::string sex, std::string ID, std::string Birthday, std::string num, int score) :Person(name, sex, ID, Birthday) {
        Student::num = num;
        Student::score = score;
    }
    virtual void show() {
        Person::show();
        std::cout << "Num:" << num << " Score:" << score << std::endl;
    }
};

class Teacher :virtual public Person {
protected:
    std::string profession;
public:
    Teacher(std::string name, std::string sex, std::string ID, std::string Birthday, std::string profession) :Person(name, sex, ID, Birthday) {
        Teacher::profession = profession;
    }
    virtual void show() {
        Person::show();
        std::cout << "profession:" << profession << std::endl;
    }
};

class StuTech :public Student, public Teacher {
public:
    StuTech(std::string name, std::string sex, std::string ID, std::string Birthday, std::string num, int score, std::string profession)
        :Person(name, sex, ID, Birthday), Student(name, sex, ID, Birthday, num, score), Teacher(name, sex, ID, Birthday, profession) {}
    void show() {
        Person::show();
        std::cout << "Num:" << num << " Score:" << score << std::endl;
        std::cout << "profession:" << profession << std::endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    std::string name, sex, ID, YY, MM, Bir, num, pro;
    int s;
    std::cin >> name >> sex >> ID >> YY >> MM >> num >> s >> pro;
    Bir = YY + "." + MM;
    StuTech ST(name, sex, ID, Bir, num, s, pro);
    std::cout << "The imformation of study-teacher is:" << std::endl;
    ST.show();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
