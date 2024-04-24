/*
https://atcoder.jp/contests/abc350/tasks/abc350_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	set<int> s;

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;

		if (s.find(x) == s.end()) {
			n--;
			s.insert(x);
		}
		else {
			n++;
			s.erase(x);
		}
	}

	cout << n << endl;
}