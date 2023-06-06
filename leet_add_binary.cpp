/*
https://leetcode.com/problems/add-binary/description/
*/
#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
	int sz_a = a.size();
	int sz_b = b.size();

	if (sz_a <= sz_b) {
		int d = sz_b - sz_a;

		for (int i = 0; i < d; ++i) {
			a = '0' + a;
		}
	}
	else {
		int d = sz_a - sz_b;

		for (int i = 0; i < d; ++i) {
			b = '0' + b;
		}
	}

	char carry = '0';
	string ans = "";
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] == b[i] && a[i] == '1') {
			ans = carry + ans;
			carry = '1';
		}
		else if (a[i] == b[i] && a[i] == '0') {
			ans = carry + ans;
			carry = '0';
		}
		else {
			if (carry == '1') {
				ans = '0' + ans;
				carry = '1';
			}
			else {
				ans = '1' + ans;
				carry = '0';
			}
		}
	}

	if (carry == '1') ans = '1' + ans;

	// cout << a << " " << b << endl;

	return ans;
}

int main() {
	// string a = "1010", b = "1011";
	string a = "11", b = "1";

	cout << addBinary(a, b);
}