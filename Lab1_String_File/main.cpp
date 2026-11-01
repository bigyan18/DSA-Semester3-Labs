#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cctype>

int main() {
    const int MAX = 1000;
    char str[MAX];

    //Read from file1.txt
    FILE* in = fopen("file1.txt", "r");
    if (!in) {
        std::cout << "Cannot open file1.txt\n";
        return 1;
    }
    if (fgets(str, MAX, in) == nullptr) {
        std::cout << "File is empty or read error\n";
        fclose(in);
        return 1;
    }
    fclose(in);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

   
    int sum = 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            sum += str[i] - '0';
            count++;
        }
    }

    int len = 0;
    while (str[len] != '\0') len++;

    str[len++] = '&';

    if (sum == 0) {
        str[len++] = '0';
    }
    else {
        int start = len;
        while (sum > 0) {
            str[len++] = (sum % 10) + '0';
            sum /= 10;
        }
        int left = start;
        int right = len - 1;
        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++;
            right--;
        }
    }


    str[len++] = '&';

    if (count == 0) {
        str[len++] = '0';
    }
    else {
        int start = len;
        while (count > 0) {
            str[len++] = (count % 10) + '0';
            count /= 10;
        }

        int left = start;
        int right = len - 1;
        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++;
            right--;
        }
    }

    str[len] = '\0';

    //Write to file2.txt
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