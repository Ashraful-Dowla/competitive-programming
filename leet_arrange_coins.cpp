/*
https://leetcode.com/problems/arranging-coins/
*/
#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n) {

	double nn = n;
	double k = -1 + sqrt(1.0 + 8.0 * nn);
	k /= 2.0;

	return (int)k;
}

int main() {

	int n = 9;
	cout << arrangeCoins(n) << endl;
}