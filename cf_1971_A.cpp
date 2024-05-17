//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1971/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int x, y;
	cin >> x >> y;

	cout << min(x, y) << " " << max(x, y) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}