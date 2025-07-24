#include <stdio.h>
#include <string.h>

// Convert binary string to decimal
int binaryToDecimal(char str[]) {
    int value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        value = value * 2 + (str[i] - '0');
    }
    return value;
}

// Perform one cyclic shift
void shift(char str[], int n) {
    char first = str[0];
    for (int i = 0; i < n - 1; i++) {
        str[i] = str[i + 1];
    }
    str[n - 1] = first;
}

int main() {
    int T;
    scanf("%d", &T);  // number of test cases

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);  // length and K
        char A[105], temp[105];
        scanf("%s", A);  // input string

        strcpy(temp, A);
        int max = binaryToDecimal(A);

        // Find max value from all shifts
        for (int i = 1; i < N; i++) {
            shift(temp, N);
            int val = binaryToDecimal(temp);
            if (val > max)
                max = val;
        }

        // Reset and find Kth time max appears
        strcpy(temp, A);
        int count = 0;

        for (int i = 0; i < N * K; i++) {
            if (binaryToDecimal(temp) == max) {
                count++;
                if (count == K) {
                    printf("%d\n", i);
                    break;
                }
            }
            shift(temp, N);
        }
    }

    return 0;
}
