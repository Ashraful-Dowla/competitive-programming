/*
https://atcoder.jp/contests/abc340/tasks/abc340_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			v.push_back(x);
		}
		else {
			int n = v.size();
			cout << v[n - x] << endl;
		}
	}
}