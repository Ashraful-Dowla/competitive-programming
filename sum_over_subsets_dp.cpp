#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity -> O(4^n)
void solve(vector<int> &a, int n) {

	vector<int> sos(1 << n, 0);

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < (1 << n); ++i) {
			if ((mask & i) == i) {
				sos[mask] += a[i];
			}
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		cout << sos[i] << " ";
	}
	cout << endl;

}

// suboptimal
// time complexity -> O(3^n)
void solve2(vector<int> &a, int n) {

	vector<int> sos(1 << n, 0);

	for (int mask = 0; mask < (1 << n); ++mask) {
		sos[mask] = a[0];
		for (int i = mask; i > 0; i = (i - 1) & mask) {
			sos[mask] += a[i];
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		cout << sos[i] << " ";
	}
	cout << endl;

}


int main() {

	int n = 2;
	vector<int> a = {7, 12, 14, 16}; // 2^n

	solve(a, n);

	solve2(a, n);

}