#include <bits/stdc++.h>
using namespace std;

// n! divisible by k^x

int fact_pow(int n, int k) {

	int res = 0;
	while (n) {
		n /= k;
		res += n;
	}

	return res;
}


int main() {

	int n = 6, k = 2;
	// int n = 100, k = 18;

	vector<pair<int, int>> pf;
	for (int i = 2; i * i <= k; ++i) {
		while (k % i == 0) {
			if (pf.empty() || pf.back().first != i) {
				pf.push_back({i, 1});
			}
			else {
				pf.back().second++;
			}
			k /= i;
		}
	}

	if (k > 1) {
		pf.push_back({k, 1});
	}

	int x = INT_MAX;
	for (auto p : pf) {
		// cout << p.first << " " << p.second << endl;
		x = min(x, fact_pow(n, p.first) / p.second);
	}

	cout << x << endl;
}