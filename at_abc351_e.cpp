/*
https://atcoder.jp/contests/abc351/tasks/abc351_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v[4];
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		if ((x + y) % 2 == 0) {
			v[0].push_back(x + y);
			v[1].push_back(x - y);
		}
		else {
			v[2].push_back(x + y);
			v[3].push_back(x - y);
		}
	}

	ll ans = 0;
	for (int i = 0; i < 4; ++i) {
		sort(v[i].begin(), v[i].end());

		ll sum = 0;
		for (int j = 0; j < v[i].size(); ++j) {
			ans += v[i][j] * j - sum;
			sum += v[i][j];
		}
	}

	cout << ans / 2 << endl;
}