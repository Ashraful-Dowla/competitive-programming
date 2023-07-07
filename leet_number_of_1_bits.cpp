/*
https://leetcode.com/problems/number-of-1-bits/description/
*/
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
	return __builtin_popcount(n);
}

int main() {
	uint32_t n = 11;

	cout << hammingWeight(n);
}