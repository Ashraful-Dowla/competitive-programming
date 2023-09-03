/*
https://leetcode.com/problems/sum-of-two-integers/description/
*/
#include <bits/stdc++.h>
using namespace std;

string numToBinary(int num) {
	string s;
	for (int i = 12; i >= 0; --i) {
		if (((num >> i) & 1)) {
			s.push_back('1');
		}
		else {
			s.push_back('0');
		}
	}
	return s;
}

void twosComplement(string &s) {
	bool ok = false;
	for (int i = 12; i >= 0; --i) {
		if (ok) {
			if (s[i] == '1') s[i] = '0';
			else s[i] = '1';
		}
		else if (s[i] == '1') {
			ok = true;
		}
	}
}

int calculateSum(string a, string b) {

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int ans = 0, carry = 0, sign = 0;
	for (int i = 0; i < a.size(); ++i) {

		if (a[i] == b[i] && a[i] == '1') {
			if (carry) {
				ans |= (1 << i);
				sign = 1;
			}
			else sign = 0;
			carry = 1;
		}
		else if (a[i] == b[i] && a[i] == '0') {
			if (carry) {
				ans |= (1 << i);
				sign = 1;
			}
			else sign = 0;
			carry = 0;
		}
		else {
			if (carry) {
				sign = 0;
			}
			else {
				ans |= (1 << i);
				sign = 1;
				carry = 0;
			}
		}
	}

	string s = numToBinary(ans);

	if (sign) {
		twosComplement(s);
	}

	reverse(s.begin(), s.end());

	ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			ans |= (1 << i);
		}
	}

	return sign ? -ans : ans;
}

int getSum(int a, int b) {

	string ba = numToBinary(abs(a));
	string bb = numToBinary(abs(b));

	if (a < 0) {
		twosComplement(ba);
	}
	if (b < 0) {
		twosComplement(bb);
	}

	int res = calculateSum(ba, bb);

	return res;
}

int generateNumber(int mn, int mx) {
	return mn + rand() % (mx - mn + 1);
}

int main() {

	int a = 8, b = -4;

	int mn = -1000, mx = 1000;
	for (int i = 0; i < 100; ++i) {
		a = generateNumber(mn, mx);
		b = generateNumber(mn, mx);

		if (getSum(a, b) != (a + b)) {
			cout << a << " " << b << " " << " wrong" << endl;
		}
		else {
			cout << a << " " << b << " " << " correct" << endl;
		}
	}

}