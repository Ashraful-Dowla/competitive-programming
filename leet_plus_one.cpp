/*
https://leetcode.com/problems/plus-one/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int c = 1;
	vector<int> ans;

	for (int i = digits.size() - 1; i >= 0; --i) {
		int num = digits[i] + c;
		ans.push_back(num % 10);
		c = num / 10;
	}

	if (c) ans.push_back(c);

	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {
	// vector<int> digits = {1, 2, 3};
	// vector<int> digits = {4, 2, 3, 1};
	vector<int> digits = {9};


	auto res =  plusOne(digits);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}