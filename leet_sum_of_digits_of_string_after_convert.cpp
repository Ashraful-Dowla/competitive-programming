/*
https://leetcode.com/problems/sum-of-digits-of-string-after-convert/submissions/1377229092/?envType=daily-question&envId=2024-09-03
*/
#include <bits/stdc++.h>
using namespace std;

int sum(string s) {

	int res = 0;
	for (char ch : s) {
		res += (ch - '0');
	}

	return res;
}

int getLucky(string s, int k) {

	string num;
	for (char ch : s) {
		int n = ch - 'a' + 1;
		num += to_string(n);
	}

	int ans;
	for (int i = 0; i < k; ++i) {
		ans = sum(num);
		num = to_string(ans);
	}

	return ans;
}

int main() {

	string s = "zbax";
	int k = 2;


	cout << getLucky(s, k) << endl;
}