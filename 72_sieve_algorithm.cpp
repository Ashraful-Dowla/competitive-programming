#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool>isPrime(N, true);

int main() {
	isPrime[0] = isPrime[1] = false;

	//O(nlog(log(n)))
	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 1; i < 100; ++i) {
		if (isPrime[i]) cout << i << endl;
	}
}