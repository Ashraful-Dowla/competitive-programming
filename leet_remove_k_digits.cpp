/*
https://leetcode.com/problems/remove-k-digits/
*/
#include <bits/stdc++.h>
using namespace std;


string removeKdigits(string num, int k) {

	int n = num.size();
	int len = n - k;

	vector<char> ans;
	for (int i = 0; i < n; ++i) {

		while (ans.size() && num[i] < ans.back() && len - ans.size() < n - i) {
			ans.pop_back();
		}

		if (ans.size() < len) {
			ans.push_back(num[i]);
		}
	}

	string res;
	bool ok = false;
	for (int i = 0; i < len; ++i) {

		if (ok) {
			res.push_back(ans[i]);
		}
		else if (ans[i] != '0' && !ok) {
			ok = true;
			res.push_back(ans[i]);
		}
	}

	return res.size() ? res : "0";

}

int main() {

	// string num = "1432219";
	// int k = 3;

	// string num = "10200";
	// int k = 1;

	string num = "10";
	int k = 2;

	cout << removeKdigits(num, k);
}