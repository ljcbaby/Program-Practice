#include <cstdio>
#include <algorithm>

class Student {
private:
    int room;
    char name[16];
    int height;
    int weight;
public:
    Student() {};
    ~Student() {};
    void getInfo() { scanf("%d %s %d %d", &room, name, &height, &weight); }
    bool operator<(const Student& s) const {
        if (room == s.room) return height > s.height;
        return room < s.room;
    }
    void print() { printf("%06d %s %d %d\n", room, name, height, weight); }
    int getRoom() { return room; }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    Student s[n];
    for (int i = 0; i < n; i++) { s[i].getInfo(); }
    std::sort(s, s + n);
    s[0].print();
    for (int i = 1; i < n; i++) {
        if (s[i].getRoom() != s[i - 1].getRoom()) s[i].print();
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}