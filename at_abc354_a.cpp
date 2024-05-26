/*
https://atcoder.jp/contests/abc354/tasks/abc354_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll h;
	cin >> h;

	vector<ll> v;

	v.push_back(0);
	for (int i = 0; i <= 32; ++i) {
		ll x = (1LL << i) + v.back();
		v.push_back(x);
	}

	auto it = lower_bound(v.begin(), v.end(), h);

	cout << it - v.begin() + (*it == h) << endl;
}