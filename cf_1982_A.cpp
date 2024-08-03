//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1982/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int x1, y1;
	cin >> x1 >> y1;

	int x2, y2;
	cin >> x2 >> y2;

	if ((x1 < y1 && x2 >= y2) || (x1 > y1 && x2 <= y2)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
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