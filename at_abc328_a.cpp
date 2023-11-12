/*
https://atcoder.jp/contests/abc328/tasks/abc328_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v <= x) {
			sum += v;
		}
	}

	cout << sum << endl;
}