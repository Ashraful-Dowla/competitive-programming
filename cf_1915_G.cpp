//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1915/problem/G
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define eb emplace_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INF = 1e15;

void solve() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, ll>> graph[n + 1];

	for (int i = 0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;

		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	ll s[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	multiset<pair<ll, pair<int, ll>>> ms;

	ll dis[n + 1][1001];
	bool vis[n + 1][1001];

	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= 1000; ++k) {
			dis[i][k] = INF;
			vis[i][k] = false;
		}
	}

	dis[1][s[1]] = 0;
	ms.insert({dis[1][s[1]], {1, s[1]}});

	while (ms.size() > 0) {
		auto it = *ms.begin();
		int u = it.second.first;
		ll k = it.second.second;
		ms.erase(ms.begin());

		if (vis[u][k]) {
			continue;
		}
		vis[u][k] = true;

		for (auto p : graph[u]) {
			int v = p.first;
			ll w = p.second;
			ll c = min(s[v], k);

			if (dis[v][c] > dis[u][k] + w * k) {
				dis[v][c] = dis[u][k] + w * k;
				ms.insert({dis[v][c], {v, c}});
			}
		}
	}


	ll ans = INF;

	for (int k = 1; k <= 1000; ++k) {
		ans = min(ans, dis[n][k]);
	}

	cout << ans << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}