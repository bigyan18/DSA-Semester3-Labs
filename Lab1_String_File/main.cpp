#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cctype>

int main() {
    const int MAX = 1000;
    char str[MAX];

    // Read from file1.txt
    FILE* in = fopen("file1.txt", "r");
    if (!in) {
        std::cout << "Cannot open file1.txt\n";
        return 1;
    }
    fgets(str, MAX, in);
    fclose(in);

    // Remove possible newline
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    // ===== Same processing as Program 1 =====
    int sum = 0;
    int count = 0;
    i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            int number = 0;
            while (isdigit(str[i])) {
                number = number * 10 + (str[i] - '0');
                i++;
            }
            sum += number;
            count++;
        }
        else {
            i++;
        }
    }

    int len = 0;
    while (str[len] != '\0') len++;

    str[len++] = '&';

    // sum
    if (sum == 0) {
        str[len++] = '0';
    }
    else {
        char temp[20];
        int t = 0;
        int s = sum;
        while (s > 0) {
            temp[t++] = (s % 10) + '0';
            s /= 10;
        }
        for (int j = t - 1; j >= 0; j--) {
            str[len++] = temp[j];
        }
    }

    str[len++] = '&';

    // count
    if (count == 0) {
        str[len++] = '0';
    }
    else {
        char temp[20];
        int t = 0;
        int c = count;
        while (c > 0) {
            temp[t++] = (c % 10) + '0';
            c /= 10;
        }
        for (int j = t - 1; j >= 0; j--) {
            str[len++] = temp[j];
        }
    }

    str[len] = '\0';

    // Write result to file2.txt
    FILE* out = fopen("file2.txt", "w");
    if (!out) {
        std::cout << "Cannot open file2.txt\n";
        return 1;
    }
    fputs(str, out);
    fclose(out);

    std::cout << "Result written to file2.txt\n";
    std::cout << "Result: " << str << std::endl;

    return 0;
}