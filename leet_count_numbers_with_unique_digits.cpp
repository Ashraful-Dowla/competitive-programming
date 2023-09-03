/*
https://leetcode.com/problems/count-numbers-with-unique-digits/description/
*/
#include <bits/stdc++.h>
using namespace std;

int countNumbersWithUniqueDigits(int n) {

    int ans = 1;

    for (int i = 1; i <= n; ++i) {
        int temp = 9, digit = 9;
        for (int j = 1; j < i; ++j) {
            temp *= digit;
            digit--;
        }
        ans += temp;
    }

    return ans;
}

int main() {

    int n = 3;
    for (int n = 0; n <= 8; ++n) {
        cout << n << " " << countNumbersWithUniqueDigits(n) << endl;
    }

}