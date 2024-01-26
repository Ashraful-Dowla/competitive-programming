/*
https://atcoder.jp/contests/abc296/tasks/abc296_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == 'M' && s[i + 1] == 'M') {
			cout << "No" << endl;
			return 0;
		}
		else if (s[i] == 'F' && s[i + 1] == 'F') {
			cout << "No" << endl;
			return 0;
		}
	}


	cout << "Yes" << endl;
}