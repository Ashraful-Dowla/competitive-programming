//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	string a, b;
	cin >> a >> b;

	swap(a[0], b[0]);
	cout << a << " " << b << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
