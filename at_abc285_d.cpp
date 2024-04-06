/*
https://atcoder.jp/contests/abc285/tasks/abc285_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> graph[N];
bool vis[N], in_stack[N];

bool dfs(int v) {

	if (in_stack[v]) return true;
	if (vis[v]) return false;

	vis[v] = in_stack[v] = true;

	bool isPossible = false;
	for (int child : graph[v]) {
		isPossible |= dfs(child);
	}

	in_stack[v] = false;

	return isPossible;
}

int main() {

	int n;
	cin >> n;

	unordered_map<string, int> mp;

	int num = 0;
	for (int i = 0; i < n; ++i) {
		string u, v;
		cin >> u >> v;

		if (mp.find(u) == mp.end()) {
			mp[u] = ++num;
		}
		if (mp.find(v) == mp.end()) {
			mp[v] = ++num;
		}

		graph[mp[u]].push_back(mp[v]);
	}

	bool isPossible = false;
	for (int i = 1; i <= num; ++i) {
		if (!vis[i]) {
			isPossible |= dfs(i);
		}
	}

	cout << (isPossible ? "No" : "Yes") << endl;
}