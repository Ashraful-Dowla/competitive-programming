/*
https://atcoder.jp/contests/abc304/tasks/abc304_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	ll x, y;
};

vector<node> points;
vector<int> graph[2005], vis(2005);

ll dis(int i, int j) {
	return (points[i].x - points[j].x) * (points[i].x - points[j].x)
	       + (points[i].y - points[j].y) * (points[i].y - points[j].y);
}

void dfs(int v) {

	vis[v] = true;
	for (int child : graph[v]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

int main() {

	int n;
	ll d;

	cin >> n >> d;

	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;

		points.push_back({x, y});
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (dis(i, j) <= d * d) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	dfs(0);

	for (int i = 0; i < n; ++i) {
		cout << (vis[i] ? "Yes" : "No") << endl;
	}
}