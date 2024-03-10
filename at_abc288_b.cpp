/*
https://atcoder.jp/contests/abc288/tasks/abc288_b
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

	multiset<string> ms;
	for (int i = 0; i < m; ++i) {
		ms.insert(v[i]);
	}

	for (auto s : ms) {
		cout << s << endl;
	}
}