/*
https://atcoder.jp/contests/abc352/tasks/abc352_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> q(n);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		q[p - 1] = i;
	}

	set<int> s;
	for (int i = 0; i < k; ++i) {
		s.insert(q[i]);
	}

	int ans = INT_MAX;
	ans = min(ans, *s.rbegin() - *s.begin());

	for (int i = k; i < n; ++i) {
		s.erase(q[i - k]);
		s.insert(q[i]);
		ans = min(ans, *s.rbegin() - *s.begin());
	}

	cout << ans << endl;
}