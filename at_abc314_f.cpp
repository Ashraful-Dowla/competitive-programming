/*
https://atcoder.jp/contests/abc314/tasks/abc314_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 998244353;
const int N = 4e5 + 10;

ll sz[N], ans[N];
int parent[N], child[N][2], n;

ll binaryExp(ll a, ll b) {

	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return ans;
}

void make(int n) {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void dfs(int v, ll val) {

	if (v <= n) {
		ans[v] = val;
		return ;
	}

	ll inv = binaryExp(sz[v], M - 2);
	dfs(child[v][0], (val % M + (sz[child[v][0]]*inv) % M) % M);
	dfs(child[v][1], (val % M + (sz[child[v][1]]*inv) % M) % M);
}


int main() {

	cin >> n;

	make(n);

	for (int i = 1; i <= n - 1; ++i) {
		int x, y;
		cin >> x >> y;

		x = find(x), y = find(y);

		sz[n + i] = sz[x] + sz[y];
		parent[x] = parent[y] = parent[n + i] = n + i;

		child[n + i][0] = x, child[n + i][1] = y;
	}

	dfs(2 * n - 1, 0);

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}