/*
https://atcoder.jp/contests/abc296/tasks/abc296_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll x;

	cin >> n >> x;

	vector<ll>v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {

		auto it = lower_bound(v.begin(), v.end(), v[i] + x);

		if (it != v.end() && *it - v[i] == x) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

}