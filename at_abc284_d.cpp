#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll N = 3e6 + 10;
vector<bool> is_prime(N, true);

void seive() {
	is_prime[1] = false;
	for (ll i = 2; i < N; ++i) {
		if (is_prime[i]) {
			for (ll j = 2 * i; j < N; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {

	int t;
	cin >> t;

	seive();

	while (t--) {
		ll n;
		cin >> n;

		for (ll i = 2; i < N; ++i) {
			if (is_prime[i]) {
				if (n % (i * i) == 0) {
					ll p = i;
					ll q = n / (p * p);
					if (p != q && n == p * p * q) {
						cout << p << " " << q << endl;
						break;
					}
				}
				else if (n % i == 0) {
					ll q = i;
					ll p = sqrtl(n / q);
					if (p != q && n == p * p * q) {
						cout << p << " " << q << endl;
						break;
					}
				}
			}
		}
	}
}