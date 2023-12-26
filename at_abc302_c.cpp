/*
https://atcoder.jp/contests/abc302/tasks/abc302_c
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10];
bool vis[10];

bool check(string s1, string s2) {

	int cnt = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) {
			cnt++;
		}
	}

	return cnt == 1;
}

void dfs(int i) {

	vis[i] = true;

	for (int child : graph[i]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {

			if (check(v[i], v[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	dfs(0);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += vis[i];
	}

	cout << (ans == n ? "Yes" : "No") << endl;
}