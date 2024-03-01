/*
https://atcoder.jp/contests/abc342/tasks/abc342_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 2e5 + 10;
const ll INF = 2e18;

struct node
{
	int v;
	ll l, d, k, c;
};

vector<node> graph[N];
vector<ll> dis(N, -INF);

ll next_time(ll t, ll l, ll d, ll k) {

	t = min(t, l + (k - 1) * d);

	if (t < l) return -1;

	ll idx = (t - l) / d;
	return l + idx * d;
}

void dijsktra(int s) {

	multiset<pli> ms;

	dis[s] = INF;
	ms.insert({dis[s], s});

	while (ms.size() > 0) {

		auto top = *(--ms.end());

		int u = top.second;
		ll t = top.first;

		ms.erase(top);

		for (auto child : graph[u]) {

			ll l = child.l, d = child.d, k = child.k, c = child.c;
			int v = child.v;

			ll nxt_t = next_time(t - c, l, d, k);

			if (nxt_t < 0 || nxt_t <= dis[v]) {
				continue;
			}

			if (dis[v] >= 0) {
				ms.erase({dis[v], v});
			}

			dis[v] = nxt_t;
			ms.insert({dis[v], v});
		}
	}

}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		ll l, d, k, c;
		int u, v;
		cin >> l >> d >> k >> c >> u >> v;
		node nd = {u, l, d, k, c};
		graph[v].push_back(nd);
	}

	dijsktra(n);

	for (int i = 1; i < n; ++i) {
		if (dis[i] < 0) cout << "Unreachable" << endl;
		else cout << dis[i] << endl;
	}
}