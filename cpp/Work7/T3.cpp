#include <cstdio>

class Shape {
public:
    virtual float area() = 0;
    static float sumArea;
};

class Circle : public Shape {
public:
    float area() {
        return 3.14159f * r * r;
    }
    float r;
};

class Square : public Shape {
public:
    float area() {
        return r * r;
    }
    float r;
};

class Rectangle : public Shape {
public:
    float area() {
        return w * h;
    }
    float w, h;
};

class Trapezoid : public Shape {
public:
    float area() {
        return (w1 + w2) * h / 2;
    }
    float w1, w2, h;
};

class Triangle : public Shape {
public:
    float area() {
        return w * h / 2;
    }
    float w, h;
};

float Shape::sumArea = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
#endif
    Circle s1;
    scanf("%f", &s1.r);
    Shape::sumArea += s1.area();
    Square s2;
    scanf("%f", &s2.r);
    Shape::sumArea += s2.area();
    Rectangle s3;
    scanf("%f %f", &s3.w, &s3.h);
    Shape::sumArea += s3.area();
    Trapezoid s4;
    scanf("%f %f %f", &s4.w1, &s4.w2, &s4.h);
    Shape::sumArea += s4.area();
    Triangle s5;
    scanf("%f %f", &s5.w, &s5.h);
    Shape::sumArea += s5.area();
    printf("%.3f\n", Shape::sumArea);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
#endif
    return 0;
}
