/*
https://leetcode.com/problems/number-complement/
*/
#include <bits/stdc++.h>
using namespace std;

int findComplement(int num) {

	vector<int> bits;

	for (int i = 31; i >= 0; --i) {
		int bit = (num >> i) & 1;
		bits.push_back(bit);
	}

	bool ok = false;
	int res = 0;
	for (int i = 0; i <= 31; ++i) {
		if (ok && bits[i] == 0) {
			res |= 1 << (31 - i);
		}
		else if (bits[i] == 1) {
			ok = true;
		}
	}

	return res;
}

int main() {

	int num = 13;
	cout << findComplement(num) << endl;
}