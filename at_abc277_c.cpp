/*
https://atcoder.jp/contests/abc277/tasks/abc277_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> graph[N];
vector<int> values;
bool vis[N];
map<int, int> mp;

int bfs(int s) {

	vis[s] = true;
	queue<int> q;
	q.push(s);

	int ans = s;

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		ans = max(ans, mp[u]);

		for (int v : graph[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
			}
		}

	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
		values.push_back(p[i].first);
		values.push_back(p[i].second);
	}

	values.push_back(0);
	values.push_back(1);
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());

	for (int i = 0; i < n; ++i) {
		int u = lower_bound(values.begin(), values.end(), p[i].first) - values.begin();
		int v = lower_bound(values.begin(), values.end(), p[i].second) - values.begin();

		mp[u] = p[i].first;
		mp[v] = p[i].second;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << bfs(1) << endl;
}