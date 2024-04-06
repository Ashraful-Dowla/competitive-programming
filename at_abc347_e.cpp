/*
https://atcoder.jp/contests/abc347/tasks/abc347_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, q;
	cin >> n >> q;

	set<int> s;
	vector<int> idx(n + 1);
	vector<ll> pf(q + 1, 0), ans(n + 1, 0);

	for (int i = 1; i <= q; ++i) {
		int x;
		cin >> x;

		if (s.find(x) == s.end()) {
			s.insert(x);
			idx[x] = i;
		}
		else {
			s.erase(x);
			ans[x] += pf[i - 1] - pf[idx[x] - 1];
		}

		pf[i] = pf[i - 1] + s.size();
	}

	for (int x : s) {
		ans[x] += pf[q] - pf[idx[x] - 1];
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}