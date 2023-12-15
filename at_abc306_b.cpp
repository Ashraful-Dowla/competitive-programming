/*
https://atcoder.jp/contests/abc306/tasks/abc306_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {

	ll sum = 0;
	for (int i = 0; i < 64; ++i) {
		ll x;
		cin >> x;
		if (x) {
			sum |= (1LL << i);
		}
	}

	cout << sum << endl;
}