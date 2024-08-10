//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool check(int a1, int a2, int b1, int b2) {
	return a1 > b1 && a2 > b2;
}

int check(int a, int b) {
	if (a > b) return 1;
	if (a == b) return 0;
	return -1;
}

void solve() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int ans = 0;
	if (check(a, c) + check(b, d) > 0) {
		ans++;
	}
	if (check(a, d) + check(b, c) > 0) {
		ans++;
	}
	if (check(b, c) + check(a, d) > 0) {
		ans++;
	}
	if (check(b, d) + check(a, c) > 0) {
		ans++;
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