/*
https://leetcode.com/problems/power-of-two/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
	long nn = n;
	if (nn == 0) return nn;
	return !(nn & (nn - 1));
}

int main() {
	int n = 1;
	cout << isPowerOfTwo(n);
}