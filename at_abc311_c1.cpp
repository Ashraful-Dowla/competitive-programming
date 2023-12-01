/*
https://atcoder.jp/contests/abc311/tasks/abc311_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];
bool in_stack[N], vis[N];

vector<int> res, ans;

void dfs(int v) {

	if (in_stack[v]) {
		res = ans;
		return ;
	}
	if (vis[v]) return ;

	vis[v] = in_stack[v] = true;

	for (int child : graph[v]) {
		ans.push_back(child);
		dfs(child);
		ans.pop_back();
	}

	in_stack[v] = false;
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;

		graph[i].push_back(x);
	}

	ans.push_back(1);
	dfs(1);
	int v = res.back();
	res.pop_back();
	ans.clear();

	for (int x : res) {
		if (x == v) v = -1;
		if (v == -1) {
			ans.push_back(x);
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}