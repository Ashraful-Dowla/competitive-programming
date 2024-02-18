/*
https://atcoder.jp/contests/abc293/tasks/abc293_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	set<int> s;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s.insert(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (s.find(i) != s.end()) {
			s.erase(a[i]);
		}
	}

	cout << s.size() << endl;
	for (int x : s) {
		cout << x << " ";
	}
	cout << endl;
}