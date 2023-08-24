/*
https://leetcode.com/problems/power-of-four/description/
*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {

	if (n <= 0) return false;

	int x = log10(n) / log10(4);
	int nn = pow(4, x);

	return nn == n;
}

int main() {

	int n = 16;
	cout << isPowerOfFour(n);
}