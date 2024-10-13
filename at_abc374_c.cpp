/*
https://atcoder.jp/contests/abc374/tasks/abc374_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[25], total, res;
vector<pair<ll, ll>> ans;

void solve(int i) {

	if (i >= n) {
		ll t = total - res;
		ans.push_back({labs(res - t), max(res, t)});
		return ;
	}

	res += a[i];
	solve(i + 1);
	res -= a[i];

	solve(i + 1);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		total += a[i];
	}

	solve(0);

	sort(ans.begin(), ans.end());
	cout << ans[0].second << endl;
}