/*
https://leetcode.com/problems/hamming-distance/
*/
#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
	return __builtin_popcount(x ^ y);
}

int main() {

	// int x = 1 , y = 4;
	int x = 3 , y = 1;
	cout << hammingDistance(x, y) << endl;
}