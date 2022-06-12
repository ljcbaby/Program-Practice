// Work on stdc2x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 3
#define dimNum 4
#define MAX_ROUNDS 200

typedef struct iris {
    double sepalLength;
    double sepalWidth;
    double petalLength;
    double petalWidth;
    int clusterID;
    int recordID;
    char type[16];
} Iris;

int isContinue;
Iris iris[1000];
Iris clusterCenter[K];
Iris centerCalc[K];
int dataNum;
double distance[K];
int dataSize[K];

int main(int argc, char const* argv[ ]) {
    // File Process
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

    // data Input
    int i;
    for (i = 0;~fscanf(in, "%lf,%lf,%lf,%lf,%s\n", &iris[i].sepalLength, &iris[i].sepalWidth, &iris[i].petalLength, &iris[i].petalWidth, iris[i].type); i++)
        iris[i].recordID = i + 1;
    dataNum = i;
    fclose(in);

    // Initialize
    for (i = 0;i < K;i++)
        clusterCenter[i] = iris[i];

    // Random Initialize
    // srand(time(NULL));
    // dataSize[0] = rand() % dataNum;
    // for (dataSize[1] = rand() % dataNum; dataSize[1] == dataSize[0]; dataSize[1] = rand() % dataNum);
    // for (dataSize[2] = rand() % dataNum; dataSize[2] == dataSize[0] || dataSize[2] == dataSize[1]; dataSize[2] = rand() % dataNum);
    // clusterCenter[0] = iris[dataSize[0]];
    // clusterCenter[1] = iris[dataSize[1]];
    // clusterCenter[2] = iris[dataSize[2]];

    // K-Means
    int round = 0;
    do {
        round++;
        isContinue = 0;
        for (i = 0;i < K;i++) {
            centerCalc[i].sepalLength = 0;
            centerCalc[i].sepalWidth = 0;
            centerCalc[i].petalLength = 0;
            centerCalc[i].petalWidth = 0;
            dataSize[i] = 0;
        }
        for (i = 0;i < dataNum;i++) {
            int j;
            for (j = 0;j < K;j++)
                distance[j] = (iris[i].sepalLength - clusterCenter[j].sepalLength) * (iris[i].sepalLength - clusterCenter[j].sepalLength)
                + (iris[i].sepalWidth - clusterCenter[j].sepalWidth) * (iris[i].sepalWidth - clusterCenter[j].sepalWidth)
                + (iris[i].petalLength - clusterCenter[j].petalLength) * (iris[i].petalLength - clusterCenter[j].petalLength)
                + (iris[i].petalWidth - clusterCenter[j].petalWidth) * (iris[i].petalWidth - clusterCenter[j].petalWidth);
            int minIndex = 0;
            for (j = 1;j < K;j++)
                if (distance[j] < distance[minIndex])
                    minIndex = j;
            iris[i].clusterID = minIndex + 1;
            centerCalc[minIndex].sepalLength += iris[i].sepalLength;
            centerCalc[minIndex].sepalWidth += iris[i].sepalWidth;
            centerCalc[minIndex].petalLength += iris[i].petalLength;
            centerCalc[minIndex].petalWidth += iris[i].petalWidth;
            dataSize[minIndex]++;
        }
        for (i = 0;i < K;i++)
            if (dataSize[i] != 0) {
                centerCalc[i].sepalLength /= dataSize[i];
                centerCalc[i].sepalWidth /= dataSize[i];
                centerCalc[i].petalLength /= dataSize[i];
                centerCalc[i].petalWidth /= dataSize[i];
            }
        for (i = 0;i < K;i++)
            if (centerCalc[i].sepalLength != clusterCenter[i].sepalLength || centerCalc[i].sepalWidth != clusterCenter[i].sepalWidth || centerCalc[i].petalLength != clusterCenter[i].petalLength || centerCalc[i].petalWidth != clusterCenter[i].petalWidth) {
                isContinue = 1;
                clusterCenter[i] = centerCalc[i];
            }
    } while (isContinue && round < MAX_ROUNDS);

    // date Output
    for (i = 0;i < dataNum;i++)
        fprintf(out, "%d:%.1lf,%.1lf,%.1lf,%.1lf,%s,%d\n", iris[i].recordID, iris[i].sepalLength, iris[i].sepalWidth, iris[i].petalLength, iris[i].petalWidth, iris[i].type, iris[i].clusterID);
    fprintf(out, "\nRound: %d\n\nAnalysis:\n", round);

    // Analysis
    char* type[K] = { "Iris-setosa", "Iris-versicolor", "Iris-virginica" };
    int typeCount[K][K] = { 0 };
    for (i = 0;i < dataNum;i++)
        for (int j = 0;j < K;j++)
            if (strcmp(iris[i].type, type[j]) == 0)
                typeCount[j][iris[i].clusterID - 1]++;
    int sum, max;
    int ssum = 0, corcnt = 0;
    for (i = 0;i < K;i++) {
        sum = typeCount[i][0] + typeCount[i][1] + typeCount[i][2];
        ssum += sum;
        int tmp = typeCount[i][0] > typeCount[i][1] ? typeCount[i][0] : typeCount[i][1];
        max = tmp > typeCount[i][2] ? tmp : typeCount[i][2];
        corcnt += max;
        fprintf(out, "%s: %d/%d %.2lf%%\n", type[i], max, sum, max * 100.0 / sum);
    }
    fprintf(out, "Total: %d/%d %.2lf%%\n", corcnt, ssum, corcnt * 100.0 / ssum);

    // Post-processing
    fclose(out);

    return 0;
}
