#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main() {
    const int MAX = 1000;
    char str[MAX];
    int i = 0;
    int ch;

    cout << "Enter string: ";

    // Read until the user types \0
    while (i < MAX - 1) {
        ch = getchar();
        if (ch == EOF) break;

        if (ch == '\\') {
            int next = getchar();
            if (next == '0') break;
            str[i++] = '\\';
            if (next != '\n' && next != EOF && i < MAX - 1)
                str[i++] = next;
        }
        else if (ch == '\n') {
            continue;// ignores enter
        }
        else {
            str[i++] = ch;
        }
    }
    str[i] = '\0';// now it is a proper C-string

    int sum = 0;
    int count = 0;
    char* p = str;

    while (*p != '\0') {
        if (isdigit(*p)) {
            sum += *p - '0';
            count++;
        }
        p++;
    }
    *p++ = '&';

    if (sum == 0) {
        *p++ = '0';
    }
    else {
        char* start = p;
        while (sum > 0) {
            *p++ = (sum % 10) + '0';
            sum /= 10;
        }
        // reverse the digits we just wrote
        char* left = start;
        char* right = p - 1;
        while (left < right) {
            char tmp = *left;
            *left = *right;
            *right = tmp;
            left++;
            right--;
        }
    }

    *p++ = '&';

    // Append count
    if (count == 0) {
        *p++ = '0';
    }
    else {
        char* start = p;
        while (count > 0) {
            *p++ = (count % 10) + '0';
            count /= 10;
        }
        // reverse
        char* left = start;
        char* right = p - 1;
        while (left < right) {
            char tmp = *left;
            *left = *right;
            *right = tmp;
            left++;
            right--;
        }
    }

    *p = '\0';// terminate the modified C-string

    cout << "Result: " << str << endl;
    return 0;
}