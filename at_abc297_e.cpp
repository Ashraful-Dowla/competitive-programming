/*
https://atcoder.jp/contests/abc297/tasks/abc297_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, k;
	cin >> n >> k;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	set<ll> s;
	s.insert(0);

	for (int i = 0; i < k; ++i) {
		ll mn = *s.begin();
		s.erase(s.begin());

		for (int j = 0; j < n; ++j) {
			s.insert(mn + v[j]);
		}
	}

	cout << *s.begin() << endl;
}