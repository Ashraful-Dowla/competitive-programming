/*
https://atcoder.jp/contests/abc352/tasks/abc352_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll mx = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		mx = max(mx, b - a);
		ans += a;
	}

	cout << ans + mx << endl;
}