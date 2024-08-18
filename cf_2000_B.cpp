//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2000/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<bool>chk(n + 5, false);
	chk[v[1]] = true;

	for (int i = 2; i <= n; ++i) {
		if (chk[v[i] - 1] || chk[v[i] + 1]) {
			chk[v[i]] = true;
		}
		else {
			cout << "NO" << endl;
			return ;
		}
	}

	cout << "YES" << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}