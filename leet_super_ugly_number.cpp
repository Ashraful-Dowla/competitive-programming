/*
https://leetcode.com/problems/super-ugly-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int nthSuperUglyNumber(int n, vector<int>& primes) {

	vector<int> ugly(n), i_prime(1005, 0);
	unordered_map<ll, bool>taken;

	ugly[0] = 1;
	taken[1] = true;

	for (int i = 1; i < n; ++i) {

		ll mn = INT_MAX, idx = -1;
		for (int j = 0; j < primes.size(); ++j) {
			ll p = primes[j];
			ll nw_prime = p * ugly[i_prime[p]];

			if (taken[nw_prime]) {
				i_prime[p]++;
				--j;
			}
			else if (mn > nw_prime) {
				mn = nw_prime;
				idx = p;
			}
		}

		ugly[i] = mn;
		taken[mn] = true;
		i_prime[idx]++;
	}

	return ugly[n - 1];
}

int main() {

	int n = 12;
	vector<int> primes = {2, 7, 13, 19};

	// int n = 1;
	// vector<int> primes = {2, 3, 5};

	// int n = 15;
	// vector<int> primes = {3, 5, 7, 11, 19, 23, 29, 41, 43, 47};

	// int n = 45;
	// vector<int> primes = {2, 3, 7, 13, 17, 23, 31, 41, 43, 47};

	cout << nthSuperUglyNumber(n, primes);
}