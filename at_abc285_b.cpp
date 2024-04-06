/*
https://atcoder.jp/contests/abc285/tasks/abc285_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	s = "_" + s;
	for (int i = 1; i < n; ++i) {
		int l = 0;
		for (int j = 1; j + i <= n; ++j) {
			if (s[j] != s[j + i]) {
				l++;
			}
			else {
				break;
			}
		}
		cout << l << endl;
	}
}