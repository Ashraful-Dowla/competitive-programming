/*
https://leetcode.com/problems/factorial-trailing-zeroes/description/
*/
#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {

	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) {
		cnt += (n / i);
	}

	return cnt;
}

int main() {

	int n = 30;
	cout << trailingZeroes(n);
}