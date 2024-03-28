/*
https://atcoder.jp/contests/abc346/tasks/abc346_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i + 1 < n; ++i) {
		cout << a[i]*a[i + 1] << " ";
	}
	cout << endl;
}