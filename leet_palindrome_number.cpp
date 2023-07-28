/*
https://leetcode.com/problems/palindrome-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {

	if (x < 0) return false;

	long long res = 0, v = x;
	while (v) {
		res = res * 10 + (v % 10);
		v /= 10;
	}

	return res == x;
}

int main() {

	int x = 10001;
	cout << isPalindrome(x) << endl;
}