/*
https://atcoder.jp/contests/abc351/tasks/abc351_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> v;

	for (int i = 0; i < n; ++i) {

		v.push_back(a[i]);
		int len = v.size();

		while (len >= 2 && v[len - 1] == v[len - 2]) {
			int u = v.back();
			v.pop_back();
			v.pop_back();
			v.push_back(u + 1);
			len = v.size();
		}
	}

	cout << v.size() << endl;
}