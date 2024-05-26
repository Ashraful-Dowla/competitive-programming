/*
https://atcoder.jp/contests/abc279/tasks/abc279_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int ans = 0;
	for (char ch : s) {
		if (ch == 'w') ans += 2;
		else ans++;
	}

	cout << ans << endl;
}