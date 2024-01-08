/*
https://atcoder.jp/contests/abc298/tasks/abc298_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int g = 0, p = 0;

	for (char ch : s) {
		if (ch == 'o') g++;
		else if (ch == 'x') p++;
	}

	if (g > 0 && p == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}