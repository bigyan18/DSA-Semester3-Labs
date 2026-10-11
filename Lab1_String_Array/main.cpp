#include <iostream>
#include <cctype>

int main() {
    const int MAX = 1000;
    char str[MAX];

    std::cout << "Enter string: ";
    std::cin.getline(str, MAX);

    int i = 0;
    int sum = 0;
    int count = 0;

    // Find all groups of digits
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

    // Find the end of the original string
    int len = 0;
    while (str[len] != '\0') len++;

    // Append results: &sum&count
    str[len++] = '&';

    // Convert sum to characters
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
        // reverse
        for (int j = t - 1; j >= 0; j--) {
            str[len++] = temp[j];
        }
    }

    str[len++] = '&';

    // Convert count to characters
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

    std::cout << "Result: " << str << std::endl;

    return 0;
}