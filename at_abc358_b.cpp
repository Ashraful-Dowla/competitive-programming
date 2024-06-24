/*
https://atcoder.jp/contests/abc358/tasks/abc358_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	set<int> s;
	s.insert(0);

	for (int i = 0; i < n; ++i) {
		auto it = s.rbegin();

		if (v[i] <= *it) {
			cout << *it + k << endl;
			s.insert(*it + k);
		}
		else {
			cout << v[i] + k << endl;
			s.insert(v[i] + k);
		}
	}
}