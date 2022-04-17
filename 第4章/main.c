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
