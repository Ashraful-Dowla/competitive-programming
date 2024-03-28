/*
https://atcoder.jp/contests/abc286/tasks/abc286_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && s[i] == 'n' && s[i + 1] == 'a') {
			cout << "nya";
			i += 1;
		}
		else {
			cout << s[i];
		}
	}

	cout << endl;
}