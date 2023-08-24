/*
https://leetcode.com/problems/power-of-three/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {

	if (n <= 0) return false;

	int x = log10(n) / log10(3);
	int nn = pow(3, x);

	return nn == n;
}

int main() {

	int n = 27;

	cout << isPowerOfThree(n) << endl;
}