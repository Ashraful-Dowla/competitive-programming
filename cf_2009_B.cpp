//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2009/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	char ch[n][4];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 4; ++j) {
			if (ch[i][j] == '#') {
				cout << j + 1 << " ";
				break;
			}
		}
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}