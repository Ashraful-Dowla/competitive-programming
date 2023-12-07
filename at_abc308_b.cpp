/*
https://atcoder.jp/contests/abc308/tasks/abc308_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<string> d(m);

	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}

	int p0;
	cin >> p0;

	unordered_map<string, int> mp;
	for (int i = 0; i < m; ++i) {
		cin >> mp[d[i]];
	}

	int sum = 0;

	for (int i = 0; i < n; ++i) {
		if (mp[v[i]] > 0) {
			sum += mp[v[i]];
		}
		else {
			sum += p0;
		}
	}

	cout << sum << endl;
}