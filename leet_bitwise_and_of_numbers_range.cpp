/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
*/
#include <bits/stdc++.h>
using namespace std;

int numOfBits(int n) {

	int cnt = 0;
	while (n) {
		n /= 2;
		cnt++;
	}

	return cnt;
}

int rangeBitwiseAnd(int left, int right) {

	int res = 0;
	while (left > 0 && right > 0) {
		int left_bits = numOfBits(left);
		int right_bits = numOfBits(right);

		if (left_bits != right_bits) break;

		int pow = 1 << (left_bits - 1);
		res |= pow;

		left -= pow, right -= pow;
	}

	return res;
}

int main() {

	int left = 4;
	int right = 5;

	cout << rangeBitwiseAnd(left, right);
}