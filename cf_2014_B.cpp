//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2014/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, k;
	cin >> n >> k;

	int lst = n;
	int fst = n - k + 1;

	if (lst % 2 == 0) {
		lst--;
	}
	if (fst % 2 == 0) {
		fst++;
	}

	int d = 1 + (lst - fst) / 2;

	if (d % 2 == 1) {
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