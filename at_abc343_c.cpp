/*
https://atcoder.jp/contests/abc343/tasks/abc343_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cubic_root(ll n) {

	ll i = 0;

	while (i * i * i <= n) {
		i++;
	}

	return i;
}

bool palindrome(ll n) {

	string s = to_string(n);

	int lo = 0, hi = s.size() - 1;

	while (lo < hi) {
		if (s[lo] != s[hi]) {
			return false;
		}
		lo++, hi--;
	}

	return true;
}

int main() {

	ll n;
	cin >> n;

	ll r = cubic_root(n);

	for (ll i = r; i >= 0; --i) {
		if (palindrome(i * i * i) && i * i * i <= n) {
			cout << i*i*i << endl;
			return 0;
		}
	}
}