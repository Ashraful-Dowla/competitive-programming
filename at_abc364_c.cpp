/*
https://atcoder.jp/contests/abc364/tasks/abc364_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll x, y;
	cin >> n >> x >> y;

	vector<ll> a(n), b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ct1 = 0;
	ll sx = 0;
	for (int i = n - 1; i >= 0; --i) {
		sx += a[i];
		ct1++;
		if (sx > x) {
			break;
		}

	}

	int ct2 = 0;
	ll sy = 0;
	for (int i = n - 1; i >= 0; --i) {
		sy += b[i];
		ct2++;
		if (sy > y) {
			break;
		}

	}
	cout << min(ct1, ct2) << endl;
}