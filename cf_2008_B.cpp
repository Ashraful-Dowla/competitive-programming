//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/2008/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int sq = sqrt(n);

	if (sq * sq != n) {
		cout << "No" << endl;
		return ;
	}

	string p;
	for (int i = 0; i < sq; ++i) {
		p.push_back('1');
	}

	for (int i = 0; i < sq - 2; ++i) {
		p.push_back('1');
		for (int j = 0; j < sq - 2; ++j) {
			p.push_back('0');
		}
		p.push_back('1');
	}

	for (int i = 0; i < sq; ++i) {
		p.push_back('1');
	}

	cout << (s == p ? "Yes" : "No") << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}