/*
https://atcoder.jp/contests/abc371/tasks/abc371_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<bool> mp(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int num;
		char ch;
		cin >> num >> ch;

		if (mp[num]) {
			cout << "No" << endl;
		}
		else {
			if (ch == 'M') {
				cout << "Yes" << endl;
				mp[num] = true;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}