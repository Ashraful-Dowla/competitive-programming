/*
https://atcoder.jp/contests/abc345/tasks/abc345_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int n = s.size();

	if (s[0] == '<' && s[n - 1] == '>') {
		for (int i = 1; i < n - 1; ++i) {
			if (s[i] == '=') {
				continue;
			}
			cout << "No" << endl;
			return 0;
		}
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}