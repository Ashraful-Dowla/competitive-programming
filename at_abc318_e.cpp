/*
https://atcoder.jp/contests/abc318/tasks/abc318_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
vector<int> pos[N];

typedef long long ll;

int main() {

	int n;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		pos[x].push_back(i);
		s.insert(x);
	}

	ll ans = 0;
	for (int x : s) {

		int sz = pos[x].size();
		vector<ll> p(sz, 0);

		for (int i = 1; i < sz; ++i) {
			p[i] = p[i - 1] + pos[x][i] - pos[x][i - 1] - 1;
		}

		vector<ll> pf(sz, 0);

		for (int i = 1; i < sz; ++i) {
			pf[i] = pf[i - 1] + p[i];
		}

		for (int j = 1; j < sz; ++j) {
			ans += pf[sz - 1] - pf[j - 1] - (sz - j) * p[j - 1];
		}
	}

	cout << ans << endl;
}