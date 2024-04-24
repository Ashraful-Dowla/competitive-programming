/*
https://atcoder.jp/contests/abc348/tasks/abc348_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
ll x[105], y[105];

vector<pli> dis[105];

ll euclid_dis(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool cmp(pli a, pli b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}


	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll d = euclid_dis(i, j);
			dis[i].push_back({d, j});
			dis[j].push_back({d, i});
		}
	}

	for (int i = 0; i < n; ++i) {
		sort(dis[i].begin(), dis[i].end(), cmp);
	}

	for (int i = 0; i < n; ++i) {
		cout << dis[i][0].second + 1 << endl;
	}
}