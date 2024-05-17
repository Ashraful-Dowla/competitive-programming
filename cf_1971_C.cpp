//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1971/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a > b) {
		swap(a, b);
	}

	set<int> l, r;

	for (int i = a + 1; i < b; ++i) {
		r.insert(i);
	}

	for (int i = 1; i <= 12; ++i) {
		if (i == a || i == b || r.find(i) != r.end()) {
			continue;
		}
		l.insert(i);
	}

	int c1 = 0, c2 = 0;

	if (l.find(c) != l.end() || l.find(d) != l.end()) {
		c1++;
	}

	if (r.find(c) != r.end() || r.find(d) != r.end()) {
		c2++;
	}

	if (c1 == 0 || c2 == 0) {
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