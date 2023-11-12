/*
https://atcoder.jp/contests/abc319/tasks/abc319_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = 1e17 + 10;

bool can(vector<ll>& vec, ll w, int m) {

	int sz = vec.size();

	stack<ll>stk;
	for (int i = sz - 1; i >= 0; --i) {
		stk.push(vec[i]);
	}

	for (int i = 0; i < m; ++i) {

		ll ww = 0;
		if (!stk.empty()) {
			ww = stk.top();
			stk.pop();
		}

		while (!stk.empty() && ww + 1 + stk.top() <= w) {
			ww += 1 + stk.top();
			stk.pop();
		}
	}

	return stk.empty();
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<ll> vec(n);

	ll lo = 0, hi = 1e17;
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		lo = max(lo, vec[i]);
	}

	ll ans = MX;
	while (lo <= hi) {

		ll mid = (lo + hi) / 2;

		if (can(vec, mid, m)) {
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}


	cout << ans << endl;
}