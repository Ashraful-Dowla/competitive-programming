/*
https://atcoder.jp/contests/abc342/tasks/abc342_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2e5 + 10;

vector<ll> k(N);
vector<bool> isPrime(N, true);

void precompute() {

	for (ll i = 1; i < N; ++i) {
		k[i] = i;
	}

	for (ll i = 2; i < N; ++i) {
		if (isPrime[i]) {
			for (ll j = i; j < N; j += i) {
				isPrime[j] = false;
				while (k[j] % (i * i) == 0) {
					k[j] /= (i * i);
				}
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);
	ll z = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] == 0) z++;
	}

	precompute();

	ll ans = 0;
	unordered_map<ll, ll> fq;
	for (int i = 0; i < n; ++i) {
		fq[k[v[i]]]++;
	}

	for (auto p : fq) {
		ll v = p.second * (p.second - 1);
		v /= 2;
		ans += v;
	}

	cout << ans + z*(n - z) << endl;
}