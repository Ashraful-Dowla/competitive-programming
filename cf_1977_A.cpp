//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1977/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, m;
	cin >> n >> m;

	if (n < m) {
		cout << "NO" << endl;
	}
	else if ((n - m) % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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