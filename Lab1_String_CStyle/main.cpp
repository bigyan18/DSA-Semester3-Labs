#include <iostream>
#include <cctype>

int main() {
    const int MAX = 1000;
    char str[MAX];

    std::cout << "Enter string: ";
    std::cin.getline(str, MAX);

    int sum = 0;
    int count = 0;
    char* p = str;

    while (*p != '\0') {
        if (isdigit(*p)) {
            int number = 0;
            while (isdigit(*p)) {
                number = number * 10 + (*p - '0');
                p++;
            }
            sum += number;
            count++;
        }
        else {
            p++;
        }
    }

    // Go to the end of the string
    p = str;
    while (*p != '\0') p++;

    // Append &sum&count
    *p++ = '&';

    // write sum
    if (sum == 0) {
        *p++ = '0';
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
            *p++ = temp[j];
        }
    }

    *p++ = '&';

    // write count
    if (count == 0) {
        *p++ = '0';
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
            *p++ = temp[j];
        }
    }

    *p = '\0';

    std::cout << "Result: " << str << std::endl;

    return 0;
}