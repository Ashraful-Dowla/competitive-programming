//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1974/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int x, y;
	cin >> x >> y;

	if (x == 0) {
		cout << (y + 1) / 2 << endl;
	}
	else if (y == 0) {
		cout << (x + 14) / 15 << endl;
	}
	else {
		int p = (y + 1) / 2;
		int r = 15 * p - y * 4;

		if (r >= x) {
			cout << p << endl;
		}
		else {
			x -= r;
			cout << p + (x + 14) / 15 << endl;
		}
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}