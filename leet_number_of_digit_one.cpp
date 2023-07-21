/*
https://leetcode.com/problems/number-of-digit-one/description/
*/
#include <bits/stdc++.h>
using namespace std;

int power(int n) {

	int res = 1;
	for (int i = 0; i < n; ++i) {
		res *= 10;
	}

	return res;
}

int countDigitOne(int n) {

	int res = 0;
	string s = to_string(n);
	for (int i = 0; i < s.size(); ++i) {

		if (s[i] == '0') continue;

		if (s[i] > '1') {
			int len = s.size() - i - 1;
			res += power(len);
			res += (s[i] - '0') * len * power(len - 1);
		}
		else {
			if (i == s.size() - 1) {
				res++;
			}
			else {
				int len = s.size() - i - 1;
				res += len * power(len - 1);
				res += stoi(s.substr(i + 1, s.size() - i - 1));
				res++;
			}
		}
	}

	return res;

}

int main() {

	int n = 1201;
	cout << countDigitOne(n);
}