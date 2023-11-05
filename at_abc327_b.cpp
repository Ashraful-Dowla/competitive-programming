/*
https://atcoder.jp/contests/abc327/tasks/abc327_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long double ll;

ll solve(int n) {

	ll res = 1;
	for (int i = 0; i < n; ++i) {
		res *= n;
	}

	return res;
}

int main() {

	ll b;
	cin >> b;

	int i = 1;
	while (true) {
		ll ans = solve(i);
		if (ans == b) {
			cout << i << endl;
			break;
		}
		else if (ans > b) {
			cout << -1 << endl;
			break;
		}
		++i;
	}
}