#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// L <= R <=10^12
// R - L <= 10^6

vector<ll> seive(ll N) {

	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= N; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	vector<ll> primes;
	for (int i = 2; i <= N; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}

	return primes;
}

// time complexity -> O(sqrt(R)*loglog(sqrt(R)) + (R-L+1)*(sqrt(R)/log(sqrt(R))))
int segmented_seive(ll L, ll R) {

	auto primes = seive(sqrtl(R)); // sqrt(R)*loglog(sqrt(R))

	vector<bool> isPrime(R - L + 1, true);

	for (auto p : primes) { // (R-L+1)*(sqrt(R)/log(sqrt(R)))

		ll start = max(p * p, ((L + p - 1) / p) * p);

		if (start > R) continue;

		for (ll k = start; k <= R; k += p) {
			isPrime[k - L] = false;
		}
	}

	if (L == 1) {
		isPrime[0] = false;
	}

	int ans = 0;
	for (int i = 0; i < R - L + 1; ++i) {
		if (isPrime[i]) {
			ans++;
			cout << L + i << endl;
		}
	}

	return ans;
}

int main() {

	ll l = 6, r = 330;

	cout << segmented_seive(l, r) << endl;
}