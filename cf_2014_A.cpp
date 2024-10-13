//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2014/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int robin = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			if (robin > 0) {
				ans++;
				robin--;
			}
		}
		else if (a[i] >= k) {
			robin += a[i];
		}
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