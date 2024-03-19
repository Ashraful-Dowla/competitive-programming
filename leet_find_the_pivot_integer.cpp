/*
https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
*/
#include <bits/stdc++.h>
using namespace std;

int pivotInteger(int n) {

	vector<int> pf(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + i;
	}

	for (int i = 1; i <= n; ++i) {
		if (pf[i] == pf[n] - pf[i - 1]) {
			return i;
		}
	}

	return -1;
}

int main() {

	int n = 4;
	cout << pivotInteger(n) << endl;
}