//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1881/problem/F
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

vector<int> graph[N];

void dfs(vector<int>& depth, vector<bool>& visited, int v) {

	visited[v] = true;

	for (int child : graph[v]) {
		if (visited[child]) continue;

		depth[child] = depth[v] + 1;
		dfs(depth, visited, child);
	}

}

void clr(int n) {
	for (int i = 1; i <= n; ++i) {
		graph[i].clear();
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> marked(k);
	for (int i = 0; i < k; ++i) {
		cin >> marked[i];
	}

	clr(n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (k == 1) {
		cout << 0 << endl;
		return ;
	}

	vector<int> depth1(n + 1, 0);
	vector<bool> v1(n + 1, false);

	dfs(depth1, v1, marked[0]);

	int i_mx = marked[0];

	for (int i : marked) {
		if (depth1[i_mx] < depth1[i]) {
			i_mx = i;
		}
	}

	vector<int> depth2(n + 1, 0);
	vector<bool> v2(n + 1, false);

	dfs(depth2, v2, i_mx);

	i_mx = marked[0];

	for (int i : marked) {
		if (depth2[i_mx] < depth2[i]) {
			i_mx = i;
		}
	}

	cout << (depth2[i_mx] + 1) / 2 << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}