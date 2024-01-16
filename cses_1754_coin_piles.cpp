/*
https://cses.fi/problemset/task/1754/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll a, ll b) {
	if (2 * a < b || 2 * b < a) return false;
	return (((2 * a - b) % 3 == 0) && ((2 * b - a) % 3 == 0));
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		ll a, b;
		cin >> a >> b;

		if (check(a, b) || check(b, a)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}