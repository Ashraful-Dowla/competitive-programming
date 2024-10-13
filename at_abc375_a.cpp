/*
https://atcoder.jp/contests/abc375/tasks/abc375_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i + 2 < n; ++i) {
		if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#') {
			ans++;
		}
	}

	cout << ans << endl;
}