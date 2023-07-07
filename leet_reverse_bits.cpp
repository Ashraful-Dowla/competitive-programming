/*
https://leetcode.com/problems/reverse-bits/description/
*/
#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {

	uint32_t nn = 0;
	for (int i = 31; i >= 0; --i) {
		if ((n >> i) & 1) {
			nn |= (1 << (31 - i));
		}
	}
	return nn;
}

int main() {

	// uint32_t n = 43261596;
	uint32_t n = 4294967293;

	cout << reverseBits(n);
}