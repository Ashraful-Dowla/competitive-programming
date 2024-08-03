//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1986/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int a, b, c;
	cin >> a >> b >> c;

	int ans = 100;
	for (int x = 1; x <= 10; ++x) {
		ans = min(ans, abs(x - a) + abs(x - b) + abs(x - c));
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}