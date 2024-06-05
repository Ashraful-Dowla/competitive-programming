/*
https://atcoder.jp/contests/abc356/tasks/abc356_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, l, r;
	cin >> n >> l >> r;

	vector<int> v;

	for (int i = 0; i <= n; ++i) {
		v.push_back(i);
	}


	reverse(v.begin() + l, v.begin() + r + 1);

	for (int i = 1; i <= n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}