/*
https://leetcode.com/problems/valid-perfect-square/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPerfectSquare(int num) {

	ll lo = 1, hi = num;

	while (lo <= hi) {
		ll mid = (hi + lo) / 2;

		if (mid * mid == num * 1LL) {
			return true;
		}
		else if (mid * mid < num * 1LL) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	return false;

}

int main() {

	// int num = 16;
	// int num = 14;
	// int num = 1;

	for (int num = 1; num <= 100; ++num) {
		cout << num << " " << isPerfectSquare(num) << endl;
	}

}