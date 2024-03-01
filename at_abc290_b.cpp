/*
https://atcoder.jp/contests/abc290/tasks/abc290_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (k == 0 && s[i] == 'o') {
			s[i] = 'x';
		}
		else if (s[i] == 'o') {
			k--;
		}
	}

	cout << s << endl;
}