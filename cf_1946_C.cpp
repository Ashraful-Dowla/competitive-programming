//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1946/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 2e5 + 10;
vector<int> graph[N];
int cut;

int dfs(int v, int p, int x) {

	int sz = 1;
	for (int c : graph[v]) {
		if (c != p) {
			sz += dfs(c, v, x);
		}
	}

	if (sz >= x) {
		cut++;
		sz = 0;
	}

	return sz;
}

void solve() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int lo = 1, hi = n, ans = 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		cut = 0;
		dfs(1, -1, mid);
		if (cut - 1 >= k) {
			ans = max(ans, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	cout << ans << endl;

	for (int i = 1; i <= n; ++i) {
		graph[i].clear();
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}