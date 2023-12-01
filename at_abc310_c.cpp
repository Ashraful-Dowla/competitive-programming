/*
https://atcoder.jp/contests/abc310/tasks/abc310_c
*/
#include <bits/stdc++.h>
using namespace std;


int main() {

	int n;
	cin >> n;

	set<string> s;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		string x;
		cin >> x;

		if (s.find(x) == s.end()) {
			ans++;
		}

		s.insert(x);
		reverse(x.begin(), x.end());
		s.insert(x);
	}

	cout << ans << endl;
}