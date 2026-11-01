#include <iostream>
#include <cctype>

int main() {
    const int MAX = 1000;
    char str[MAX];
    int i = 0;
    int ch;

    std::cout << "Enter string: ";

    while (i < MAX - 1) {
        ch = std::cin.get();

        if (ch == EOF) break;

       
        if (ch == '\\') {
            int next = std::cin.get();
            if (next == '0') {
                break; 
            }
            else {
                str[i++] = '\\';
                if (next != EOF && i < MAX - 1) {
                    str[i++] = next;
                }
            }
        }
        else if (ch == '\n') {
            continue;
        }
        else {
            str[i++] = ch;
        }
    }

    str[i] = '\0';

    int sum = 0;
    int count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        if (std::isdigit(str[j])) {
            sum += str[j] - '0';
            count++;
        }
    }

    int pos = 0;
    while (str[pos] != '\0') pos++;

    str[pos++] = '&';

    if (sum == 0) {
        str[pos++] = '0';
    }
    else {
        int start = pos;
        while (sum > 0) {
            str[pos++] = (sum % 10) + '0';
            sum /= 10;
        }
        int left = start, right = pos - 1;
        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++; right--;
        }
    }

    str[pos++] = '&';

    // write count
    if (count == 0) {
        str[pos++] = '0';
    }
    else {
        int start = pos;
        while (count > 0) {
            str[pos++] = (count % 10) + '0';
            count /= 10;
        }
        // reverse
        int left = start, right = pos - 1;
        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++; right--;
        }
    }

    str[pos] = '\0';

    std::cout << "Result: " << str << std::endl;
    return 0;
}