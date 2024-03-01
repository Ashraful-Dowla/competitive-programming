/*
https://atcoder.jp/contests/abc290/tasks/abc290_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	set<int> s;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	int p = 0;
	for (int i = 0; i < k; ++i) {
		if (s.find(i) == s.end()) {
			break;
		}
		else {
			p++;
		}
	}

	cout << p << endl;
}