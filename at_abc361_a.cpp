/*
https://atcoder.jp/contests/abc361/tasks/abc361_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k, x;
	cin >> n >> k >> x;

	vector<int> a;

	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		a.push_back(v);
	}

	a.insert(a.begin() + k, x);

	for (int v : a) {
		cout << v << " ";
	}
	cout << endl;
}