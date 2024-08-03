//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1474/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e7 + 10;
vector<bool> isPrime(N, true);
vector<int> primes;

void seive() {

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
			}
		}
	}

}

void solve() {

	int d;
	cin >> d;

	int second_div = *lower_bound(primes.begin(), primes.end(), d + 1);
	int third_div = *lower_bound(primes.begin(), primes.end(), second_div + d);

	cout << (second_div * 1LL * third_div) << endl;
}

int main() {
	Faster;

	seive();

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}