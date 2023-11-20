/*
https://codeforces.com/problemset/problem/230/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll, bool>mp;

bool isPrime(ll val) {
	for (int i = 2; i <= sqrt(val); ++i) {
		if (val % i == 0) return false;
	}

	return true;
}

void primeList(ll lo, ll hi) {
	for (ll i = lo; i <= hi; ++i) {
		if (isPrime(i)) mp[i * i] = true;
	}
}

int main() {
	long long n;
	cin >> n;
	ll arr[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	primeList(2, 1e6);

	for (int i = 0; i < n; i++) {
		if (mp[arr[i]]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}