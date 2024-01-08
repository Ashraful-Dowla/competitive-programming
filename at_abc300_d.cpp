/*
https://atcoder.jp/contests/abc300/tasks/abc300_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
vector<bool>isPrime(N, true);
vector<ll> prime;

void preprocess() {

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {

	ll n;
	cin >> n;

	preprocess();

	int sz = prime.size(), ans = 0;

	for (int i = 0; i < sz; ++i) {
		int k = sz - 1;
		for (int j = i + 1; j < sz && j < k; ++j) {
			while (j < k) {
				ll p = prime[i] * prime[i] * prime[j];
				if (p > n) {
					k = j;
					break;
				}
				p *= prime[k];
				if (p > n) {
					k--;
					continue;
				}
				p *= prime[k];
				if (p > n) {
					k--;
					continue;
				}
				break;
			}
			ans += (k - j);
		}
	}

	cout << ans << endl;
}