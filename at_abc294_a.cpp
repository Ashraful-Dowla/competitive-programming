/*
https://atcoder.jp/contests/abc294/tasks/abc294_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (!(x & 1)) {
			cout << x << " ";
		}
	}
	cout << endl;
}