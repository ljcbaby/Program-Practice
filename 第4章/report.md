# 第4章《房价预测》实验报告

21051117 卢俊成

## 主要数据结构和变量

- `sumX` `sumY` `sumXY` `sumXX` 各个参数的累计
- `count` 计数器
- `sumDiff` `minDiff` `maxDiff` `sumDelta` 差异分析的各参数

## 程序主要流程

1. 读取数据并计算 `y = ax + b` 的 `a` 和 `b`
2. 再次读取数据并进行差异分析

## 程序主要函数功能

未抽提函数

## 已实现功能

全部题目要求功能

## 编译与运行信息

### 编译信息

```bash
/usr/bin/gcc -std=c17 -fdiagnostics-color=always -Wfatal-errors -Wall -Wextra -g 1.c -o 1 -lm
```

### 测试命令行

```bash
./1 1.in 1.out
```

### 测试数据

#### 输入

```text
210,3999000
160,3299000
240,3690000
141,2320000
300,5399000
198,2999000
153,3149000
142,1989990
138,2120000
149,2425000
194,2399990
200,3470000
189,3299990
447,6999000
126,2599000
230,4499000
132,2999000
123,1999000
260,4999980
303,5990000
176,2529000
188,2550000
160,2429000
196,2599000
389,5739000
110,2499000
145,4645000
252,4690000
220,4750000
263,2999000
183,3499000
100,1699000
204,3149000
313,5799000
181,2859000
143,2499000
123,2299000
213,3450000
421,5490000
216,2870000
166,3685000
223,3299000
256,3140000
120,2990000
85,1799000
185,2999000
120,2395000
```

#### 输出

```text
13459.38x+716259.14
521024.34
39907.44
1977130.30
15.76%
```

## 源代码

```c
// Work on stdc17
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const* argv[ ]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    FILE* in, * out;
    in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Can't read %s.\n", argv[1]);
        exit(1);
    }
    out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Can't write %s.\n", argv[2]);
        exit(1);
    }
    int count = 0;
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumXX = 0;
    double x, y;
    while (fscanf(in, "%lf,%lf", &x, &y) == 2) {
        count++;
        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumXX += x * x;
    }
    double a = ((double)count * sumXY - sumX * sumY) / ((double)count * sumXX - sumX * sumX);
    double b = ((double)sumY - a * sumX) / count;
    fprintf(out, "%.2lfx+%.2lf\n", a, b);
    freopen(argv[1], "r", in);
    if (in == NULL) {
        fprintf(stderr, "Can't read %s.\n", argv[1]);
        exit(1);
    }
    double sumDiff = 0;
    double minDiff = __DBL_MAX__;
    double maxDiff = 0;
    double sumDelta = 0;
    for (int sum = count + 1; sum; sum--) {
        fscanf(in, "%lf,%lf", &x, &y);
        double diff = fabs(y - (a * x + b));
        sumDiff += diff;
        if (diff < minDiff) minDiff = diff;
        if (diff > maxDiff) maxDiff = diff;
        sumDelta += diff * 100 / y;
    }
    fprintf(out, "%.2lf\n%.2lf\n%.2lf\n", sumDiff / count, minDiff, maxDiff);
    fprintf(out, "%.2lf%%\n", sumDelta / count);
    return 0;
}
```
