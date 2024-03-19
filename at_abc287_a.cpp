/*
https://atcoder.jp/contests/abc287/tasks/abc287_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int f = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "For") {
			f++;
		}
	}

	if (f > n - f) cout << "Yes" << endl;
	else cout << "No" << endl;
}