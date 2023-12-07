/*
https://atcoder.jp/contests/abc331/tasks/abc331_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll s, m, l;

	cin >> n >> s >> m >> l;

	ll ans = 1e15;

	for (int ss = 0; ss <= n; ++ss) {
		for (int mm = 0; mm <= n; ++mm) {
			for (int ll = 0; ll <= n; ++ll) {
				if (ss * 6 + mm * 8 + ll * 12 >= n) {
					ans = min(ans, ss * s + mm * m + ll * l);
				}
			}
		}
	}

	cout << ans << endl;
}