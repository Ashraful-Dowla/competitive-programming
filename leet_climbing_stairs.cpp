/*
https://leetcode.com/problems/climbing-stairs/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[50];

int solve(int n) {

	if (n == 0) {
		return 1;
	}
	if (dp[n] != -1) return dp[n];

	int cnt = 0;
	if (n >= 1) cnt += solve(n - 1);
	if (n >= 2) cnt += solve(n - 2);

	return dp[n] = cnt;
}

int climbStairs(int n) {

	memset(dp, -1, sizeof(dp));
	return solve(n);
}

int main() {
	int n = 40;
	cout << climbStairs(n);
}