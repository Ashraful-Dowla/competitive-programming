/*
https://atcoder.jp/contests/abc297/tasks/abc297_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll d;

	cin >> n >> d;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 1; i < n; ++i) {
		if (v[i] - v[i - 1] <= d) {
			cout << v[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}