/*
https://atcoder.jp/contests/abc313/tasks/abc313_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	int mx = 0;

	for (int i = 1; i < n; ++i) {
		mx = max(mx, vec[i]);
	}

	cout << max(0, mx + 1 - vec[0]) << endl;
}