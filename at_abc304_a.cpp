/*
https://atcoder.jp/contests/abc304/tasks/abc304_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll mx = 1e10;
	int idx = -1;

	vector<string> v;
	for (int i = 0; i < n; ++i) {

		string s;
		int a;
		cin >> s >> a;

		v.push_back(s);
		if (a < mx) {
			mx = a,
			idx = i;
		}
	}

	for (int i = idx; i < idx + n; ++i) {
		cout << v[(i % n)] << endl;
	}
}