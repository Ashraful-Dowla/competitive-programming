/*
https://atcoder.jp/contests/abc320/tasks/abc320_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

struct node
{
	ll b, x, y;
};

vector<node> graph[N];
vector<bool> visited(N);

vector<pair<ll, ll>> coord(N);

void dfs(ll v, ll x, ll y) {

	coord[v] = {x, y};
	visited[v] = true;

	for (auto child : graph[v]) {
		if (visited[child.b]) continue;
		dfs(child.b,  x + child.x, y + child.y);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		ll a, b, x, y;
		cin >> a >> b >> x >> y;

		graph[a].push_back({b, x, y});
		graph[b].push_back({a, -x, -y});
	}

	dfs(1, 0, 0);

	for (int i = 1; i <= n; ++i) {
		if (visited[i]) {
			cout << coord[i].first << " " << coord[i].second << endl;
		}
		else {
			cout << "undecidable" << endl;
		}
	}

}