/*
https://atcoder.jp/contests/abc342/tasks/abc342_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;


	vector<int> v(200);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[x] = i;
	}

	int q;
	cin >> q;

	while (q--) {
		int a, b;
		cin >> a >> b;

		if (v[a] < v[b]) {
			cout << a << endl;
		}
		else {
			cout << b << endl;
		}
	}
}