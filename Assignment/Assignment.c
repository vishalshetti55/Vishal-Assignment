#include <stdio.h>
#include <math.h>

int* highestNetworkQuality(int towers[][3], int n, int radius) {
    int maxQuality = 0;
    static int result[2];

    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int networkQuality = 0;
            for (int i = 0; i < n; i++) {
                int xi = towers[i][0];
                int yi = towers[i][1];
                int qi = towers[i][2];
                double d = sqrt(pow((xi - x), 2) + pow((yi - y), 2));
                if (d <= radius) {
                    networkQuality += qi / (1 + d);
                }
            }
            if (networkQuality > maxQuality) {
                maxQuality = networkQuality;
                result[0] = x;
                result[1] = y;
            }
        }
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int towers[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &towers[i][0], &towers[i][1], &towers[i][2]);
    }

    int radius;
    scanf("%d", &radius);

    int* result = highestNetworkQuality(towers, n, radius);
    printf("[%d, %d]\n", result[0], result[1]);

    return 0;
}
