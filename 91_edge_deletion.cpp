#include <bits/stdc++.h>
using namespace std;

// input
// 4
// 1 2
// 1 4
// 4 3
// 10 5 12 6


const int N = 1e5 + 10, M = 1e9 + 7;
vector<int>graph[N];
int subtree_sum[N], val[N];

void dfs(int vertex, int par = 0) {
	subtree_sum[vertex] += val[vertex];
	for (int child : graph[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	dfs(1);
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		int part1 = subtree_sum[i];
		int part2 = subtree_sum[1] - part1;
		ans = max(ans, (part1 * 1LL * part2) % M);
	}
	cout << ans << endl;
}