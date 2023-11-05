/*
https://atcoder.jp/contests/abc327/tasks/abc327_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	bool ok = false;
	for (int i = 0; i + 1 < n; ++i) {

		if (s[i] == 'a' && s[i + 1] == 'b') {
			ok = true;
			break;
		}
		else if (s[i] == 'b' && s[i + 1] == 'a') {
			ok = true;
			break;
		}
	}

	cout << (ok ? "Yes" : "No") << endl;
}