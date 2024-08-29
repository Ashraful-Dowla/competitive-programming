//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1997/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

const ll INF = 2e9;

const int N = 2e5 + 10;
int a[N];
vector<int> tree[N];
bool ok;

void dfs(int u, ll m, ll g) {

	if (!ok) {
		return ;
	}
	if (g > INF) {
		ok = false;
		return ;
	}

	ll curr = a[u] - g;

	if (tree[u].empty()) {
		if (curr < m) {
			ok = false;
		}
		return ;
	}

	if (curr < m) {
		g += m - curr;
	}

	for (int v : tree[u]) {
		dfs(v, m, g);
	}
}

bool check(ll m) {
	ok = true;
	for (int v : tree[1]) {
		dfs(v, m, 0);
	}
	return ok;
}

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		tree[i].clear();
	}

	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		tree[p].push_back(i);
	}

	ll lo = 0, hi = INF, m = 0;

	while (lo <= hi) {
		ll mid = (hi + lo) / 2;

		if (check(mid)) {
			m = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	cout << a[1] + m << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}