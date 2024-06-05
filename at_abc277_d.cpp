/*
https://atcoder.jp/contests/abc277/tasks/abc277_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
vector<int> graph[N];
bool vis[N];

ll bfs(int s, vector<int>& v) {

	vis[s] = true;
	queue<int> q;
	q.push(s);

	ll res = 0;
	while (!q.empty()) {

		int u = q.front();
		q.pop();

		res += v[u];

		for (int child : graph[u]) {
			if (vis[child]) continue;
			q.push(child);
			vis[child] = true;
		}
	}

	return res;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {

		int x = v[i], xi = i;
		int y = v[(i + 1) % n], yi = (i + 1) % n;

		if (x == y || (x + 1) % m == y) {
			graph[xi].push_back(yi);
			graph[yi].push_back(xi);
		}
	}

	ll mx = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		mx = max(mx, bfs(i, v));
	}

	cout << sum - mx << endl;

}