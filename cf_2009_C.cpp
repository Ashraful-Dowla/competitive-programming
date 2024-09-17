//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2009/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	ll x, y, k;
	cin >> x >> y >> k;

	cout << max((2 * ((x + k - 1) / k)) - 1, 2 * ((y + k - 1) / k)) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}