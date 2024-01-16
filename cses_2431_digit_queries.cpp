/*
https://cses.fi/problemset/task/2431/
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {

	int q;
	cin >> q;

	while (q--) {
		ll k;
		cin >> k;

		ll l = 1, r = 10, d = 1;

		while (k > d * (r - l)) {
			k -= d * (r - l);
			l = r;
			r *= 10;
			d++;
		}

		ll num = l + (k - 1) / d;
		ll dem = (k - 1) % d;
		string s = to_string(num);

		cout << s[dem] << endl;
	}
}