/*
https://cses.fi/problemset/task/2183/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;

int main() {

	int n;
	cin >> n;

	v.assign(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int i = 0;
	ll ans = 1;

	while (i < n && ans >= v[i]) {
		ans += v[i];
		i++;
	}

	cout << ans << endl;
}