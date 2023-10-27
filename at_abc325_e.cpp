/*
https://atcoder.jp/contests/abc325/tasks/abc325_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll car[1005][1005], train[1005][1005];

vector<bool> visited1(1005), visited2(1005);
vector<ll> dist1(1005, 1e17), dist2(1005, 1e17);

void dijkstra1(int src) {

	set<pair<ll, int>> s;
	s.insert({0, src});
	dist1[src] = 0;

	while (s.size() > 0) {
		auto node = *s.begin();
		int v = node.second;

		s.erase(s.begin());

		if (visited1[v]) continue;
		visited1[v] = true;

		for (int i = 0; i < n; ++i) {
			if (i == v) continue;
			if (dist1[v] + car[v][i] < dist1[i]) {
				dist1[i] = dist1[v] + car[v][i];
				s.insert({dist1[i], i});
			}
		}
	}

}

void dijkstra2(int src) {

	set<pair<ll, int>> s;
	s.insert({0, src});
	dist2[src] = 0;

	while (s.size() > 0) {
		auto node = *s.begin();
		int v = node.second;

		s.erase(s.begin());

		if (visited2[v]) continue;
		visited2[v] = true;

		for (int i = 0; i < n; ++i) {
			if (i == v) continue;
			if (dist2[v] + train[v][i] < dist2[i]) {
				dist2[i] = dist2[v] + train[v][i];
				s.insert({dist2[i], i});
			}
		}
	}

}


int main() {

	ll a, b, c;
	cin >> n >> a >> b >> c;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ll d;
			cin >> d;
			car[i][j] = d * a;
			train[i][j] = d * b + c;
		}
	}

	dijkstra1(0);
	dijkstra2(n - 1);

	ll ans = 1e17;

	for (int i = 0; i < n; ++i) {
		ans = min(ans, dist1[i] + dist2[i]);
	}

	cout << ans << endl;
}