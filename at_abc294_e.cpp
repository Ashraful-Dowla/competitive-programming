/*
https://atcoder.jp/contests/abc294/tasks/abc294_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {

	ll l;
	int n, m;

	cin >> l >> n >> m;

	vector<pll> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
	}


	ll ans = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (a[i].first == b[j].first) {
			ans += min(a[i].second, b[j].second);
			if (a[i].second < b[j].second) {
				b[j].second -= a[i].second;
				i++;
			}
			else if (a[i].second > b[j].second) {
				a[i].second -= b[j].second;
				j++;
			}
			else {
				i++, j++;
			}
		}
		else {
			if (a[i].second < b[j].second) {
				b[j].second -= a[i].second;
				i++;
			}
			else {
				a[i].second -= b[j].second;
				j++;
			}
		}
	}

	cout << ans << endl;
}