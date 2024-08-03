/*
https://atcoder.jp/contests/abc361/tasks/abc361_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, k;
	cin >> n >> k;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int rem = n - k;
	ll ans = 1e15;

	for (int i = 0; i + rem - 1 < n; ++i) {
		ans = min(ans, v[i + rem - 1] - v[i]);
	}

	cout << ans << endl;
}