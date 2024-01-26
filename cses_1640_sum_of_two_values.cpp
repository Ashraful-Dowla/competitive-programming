/*
https://cses.fi/problemset/task/1640
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, x;
	cin >> n >> x;

	vector<ll> a(n);
	map<ll, vector<int>> mp;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i + 1);
	}


	int st = -1, nd = -1;

	for (int i = 0; i < n; ++i) {

		ll r = x - a[i];

		if (x == 2 * r && mp[r].size() >= 2) {
			st = i + 1, nd = mp[r][1];
			break;
		}
		else if (x != 2 * r && mp[r].size() > 0) {
			st = i + 1, nd = mp[r][0];
			break;
		}
	}

	if (st == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << st << " " << nd << endl;
	}
}