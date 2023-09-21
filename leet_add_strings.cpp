/*
https://leetcode.com/problems/add-strings/
*/
#include <bits/stdc++.h>
using namespace std;

void add_leading_zeros(string& num, int d) {
	for (int i = 0; i < d; ++i) {
		num = '0' + num;
	}
}

string addStrings(string num1, string num2) {

	int sz_1 = num1.size();
	int sz_2 = num2.size();

	if (sz_1 > sz_2) {
		add_leading_zeros(num2, sz_1 - sz_2);
	}
	else {
		add_leading_zeros(num1, sz_2 - sz_1);
	}

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int carry = 0;
	string ans;
	for (int i = 0; i < max(sz_1, sz_2); ++i) {
		int res = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = res / 10;
		res %= 10;
		char ch = res + '0';
		ans.push_back(ch);
	}

	if (carry) {
		char ch = carry + '0';
		ans.push_back(ch);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {

	// string num1 = "11", num2 = "123";
	// string num1 = "456", num2 = "77";
	string num1 = "0", num2 = "0";
	cout << addStrings(num1, num2);
}