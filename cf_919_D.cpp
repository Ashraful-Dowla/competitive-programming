//Author: Ashraful Dowla
/*
https://codeforces.com/contest/919/problem/D
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

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;

int n, m, vis[N], dp[N][26];
string s;

vector<int> graph[N];
vector<bool> in_stack(N, false);

bool is_loop_exists(int v) {

	if (in_stack[v]) return true;
	if (vis[v]) return false;


	vis[v] = in_stack[v] = true;

	bool isPossible = false;
	for (int x : graph[v]) {
		isPossible |= is_loop_exists(x);
	}

	in_stack[v] = false;

	return isPossible;
}

void dfs(int v) {

	vis[v] = true;

	for (int x : graph[v]) {

		if (!vis[x]) {
			dfs(x);
		}

		for (int i = 0; i < 26; ++i) {
			dp[v][i] = max(dp[v][i], dp[x][i]);
		}
	}

	dp[v][s[v] - 'a']++;
}


void solve() {

	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		--u, --v;
		graph[u].push_back(v);
	}

	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (!vis[i] && is_loop_exists(i)) {
			cout << -1 << endl;
			return ;
		}
	}

	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
}

int main() {
	Faster;

	solve();
}