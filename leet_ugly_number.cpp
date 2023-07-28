/*
https://leetcode.com/problems/ugly-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n) {

	if (n <= 0) {
		return false;
	}

	long long nn = n;

	for (long long i = 2; i * i <= nn; ++i) {
		while (nn % i == 0) {
			if (i > 5) return false;
			nn /= i;
		}
	}

	return nn <= 5;
}

int main() {

	int n = 14;
	cout << isUgly(n);
}