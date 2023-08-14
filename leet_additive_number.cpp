/*
https://leetcode.com/problems/additive-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long double ll;

bool solve(string &num, int idx, ll prev1, ll prev2, ll curr, bool ok) {

	if (idx == num.size()) {
		return ok && curr == 0;
	}

	bool isPossible = false;
	curr = curr * 10 + (num[idx] - '0');

	if (curr > 0) {
		isPossible |= solve(num, idx + 1, prev1, prev2, curr, ok);
	}
	if (prev1 == -1) {
		isPossible |= solve(num, idx + 1, curr, prev2, 0, ok);
	}
	else if (prev2 == -1) {
		isPossible |= solve(num, idx + 1, prev1, curr, 0, ok);
	}
	else if (prev1 + prev2 == curr) {
		isPossible |= solve(num, idx + 1, prev2, curr, 0, true);
	}

	return isPossible;
}

bool isAdditiveNumber(string num) {
	return solve(num, 0, -1, -1, 0, false);
}

int main() {

	// string num = "112358";
	// string num = "199100199";
	// string num = "011235";
	// string num = "120122436";
	// string num = "101";
	// string num = "121474836472147483648";
	// string num = "111122335588143";
	string num = "199111992";
	cout << isAdditiveNumber(num) << endl;
}