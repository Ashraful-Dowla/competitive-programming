/*
https://cses.fi/problemset/task/1071/
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {

	int t;
	cin >> t;

	while (t--) {
		ll x, y;
		cin >> x >> y;

		ll mx = max(x, y);

		ll l = (mx - 1) * (mx - 1) + 1, r = mx * mx;

		if (r % 2 == 0) {
			if (x == mx) {
				cout << r - y + 1 << endl;
			}
			else {
				cout << l + x - 1 << endl;
			}
		}
		else {
			if (x == mx) {
				cout << l + y - 1 << endl;
			}
			else {
				cout << r - x + 1 << endl;
			}
		}
	}

}