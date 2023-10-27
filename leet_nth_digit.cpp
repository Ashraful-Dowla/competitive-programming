/*
https://leetcode.com/problems/nth-digit/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int findNthDigit(int n) {

	ll base = 1, digit = 1;

	while (n * 1LL > 9 * base * digit) {
		n -= 9 * base * digit;
		digit++;
		base *= 10;
	}

	ll q = (n - 1) / digit;
	int r = (n - 1) % digit;

	string ans = to_string(base + q);
	return ans[r] - '0';

}

int main() {

}