/*
https://leetcode.com/problems/sqrtx/description/
*/
#include <bits/stdc++.h>
using namespace std;


int mySqrt(int x) {

	if (x == 0 || x == 1) return x;

	int lo = 0, hi = x;

	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (mid * 1LL * mid <= x * 1LL) lo = mid;
		else hi = mid;
	}

	return lo;
}

int main() {
	int  x = 9;

	cout << mySqrt(x);
}