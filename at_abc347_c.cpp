/*
https://atcoder.jp/contests/abc347/tasks/abc347_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll a, b;

	cin >> n >> a >> b;

	ll mod = a + b;
	vector<ll> d(n);

	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		d[i] %= mod;
	}

	sort(d.begin(), d.end());

	for (int i = 1; i < n; ++i) {
		if (d[i] - d[i - 1] > b) {
			cout << "Yes" << endl;
			return 0;
		}
	}


	if (d[0] + mod - d[n - 1] > b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}