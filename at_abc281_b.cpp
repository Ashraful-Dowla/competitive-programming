/*
https://atcoder.jp/contests/abc281/tasks/abc281_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int n = s.size();

	if (n != 8) {
		cout << "No" << endl;
		return 0;
	}

	if (isupper(s[0]) && isupper(s[n - 1])) {

		int res = 0;
		for (int i = 1; i < n - 1; ++i) {
			if (isupper(s[i])) {
				cout << "No" << endl;
				return 0;
			}

			res = res * 10 + (s[i] - '0');
		}

		if (res >= 100000 && res <= 999999) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
}