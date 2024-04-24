/*
https://leetcode.com/problems/n-th-tribonacci-number/submissions/1240448765/?envType=daily-question&envId=2024-04-24
*/
#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {

	vector<int> trib(40, 0);
	trib[1] = 1, trib[2] = 1;

	for (int i = 3; i <= n; ++i) {
		trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];
	}

	return trib[n];
}

int main() {
	
	cout << tribonacci(2) << endl;
}