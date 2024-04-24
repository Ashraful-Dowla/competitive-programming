//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/791/B
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

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

vector<int> graph[N], t[N];
bool vis[N];
ll vcnt, edge;

void dfs(int v) {

	vis[v] = true;
	vcnt++;
	edge += graph[v].size();

	for (int child : graph[v]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

void solve() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vcnt = edge = 0;
			dfs(i);
			if (edge != vcnt * (vcnt - 1)) {
				cout << "NO" << endl;
				return ;
			}
		}
	}

	cout << "YES" << endl;
}

int main() {
	Faster;

	solve();
}