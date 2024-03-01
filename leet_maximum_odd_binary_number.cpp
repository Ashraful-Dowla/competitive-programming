/*
https://leetcode.com/problems/maximum-odd-binary-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s) {

	int one = 0;

	for (char ch : s) {
		if (ch == '1') {
			one++;
		}
	}

	string ans;

	for (int i = 0; i < one - 1; ++i) {
		ans.push_back('1');
	}

	for (int i = 0; i < s.size() - one; ++i) {
		ans.push_back('0');
	}

	ans.push_back('1');

	return ans;
}

int main() {

	// string s = "010";
	string s = "0101";

	cout << maximumOddBinaryNumber(s) << endl;
}