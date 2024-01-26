/*
https://cses.fi/problemset/task/1643
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll sum = v[0], best = v[0];

	for (int i = 1; i < n; ++i) {
		sum = max(v[i], sum + v[i]);
		best = max(best, sum);
	}

	cout << best << endl;
}