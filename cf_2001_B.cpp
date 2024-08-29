//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2001/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << -1 << endl;
	}
	else {
		vector<int> v(n + 1);
		for (int i = 2, j = 1; i <= n; i += 2, ++j) {
			v[i] = j;
		}
		for (int i = 1, j = n; i <= n; i += 2, --j) {
			v[i] = j;
		}

		for (int i = 1; i <= n; ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
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