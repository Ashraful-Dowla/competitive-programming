//Author: Ashraful Dowla

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

vector<int>graph[N];
bool visited[N], in_stack[N];
int cnt[30], len;


bool dfs(int v) {

	if (in_stack[v]) return true;
	if (visited[v]) return false;

	visited[v] = in_stack[v] = true;

	bool is_loop_exists = false;
	for (int child : graph[v]) {
		is_loop_exists |= dfs(child);
	}

	in_stack[v] = visited[v] = false;

	return is_loop_exists;
}

void dfs2(string& s, int v) {

	visited[v] = true;
	len = max(len , cnt[s[v] - 'a']);

	for (int child : graph[v]) {
		if (!visited[child]) {
			cnt[s[child] - 'a']++;
			dfs2(s, child);
			cnt[s[child] - 'a']--;
		}
	}
}

void clr(int n) {

	for (int i = 1; i <= n; ++i) {
		graph[i].clear();
		visited[i] = in_stack[i] = false;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
	}


	vector<int> nodes;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			if (!dfs(i)) {
				nodes.push_back(i);
			}
		}
	}

	int ans = -1;
	for (int i : nodes) {
		len = 0;
		if (!visited[i]) {
			cnt[s[i] - 'a']++;
			dfs2(s, i);
			cnt[s[i] - 'a']--;

			ans = max(ans, len);
		}
	}

	cout << ans << endl;
	clr(n);
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}