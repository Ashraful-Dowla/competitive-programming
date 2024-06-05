/*
https://www.spoj.com/problems/NFACTOR/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> isPrime(N, true), cnt(N, 0);
int pf[12][N];

void seive() {

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			cnt[i]++;
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
				cnt[j]++;
			}
		}
	}

	for (int i = 1; i < N; ++i) {
		pf[cnt[i]][i]++;
	}

	for (int i = 0; i <= 10; ++i) {
		for (int j = 1; j < N; ++j) {
			pf[i][j] += pf[i][j - 1];
		}
	}

}

int main() {

	seive();

	int t;
	cin >> t;

	while (t--) {
		int a, b, n;
		cin >> a >> b >> n;

		cout << pf[n][b] - pf[n][a - 1] << endl;
	}
}