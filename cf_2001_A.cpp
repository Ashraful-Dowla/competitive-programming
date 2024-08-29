//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2001/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	map<int, int> mp;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		mx = max(mx, ++mp[x]);
	}

	cout << n - mx << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}