/*
https://leetcode.com/problems/fizz-buzz/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {

	vector<string> ans(n);
	for (int i = 1; i <= n; ++i) {

		if (i % 3 == 0 && i % 5 == 0) {
			ans[i - 1] = "FizzBuzz";
		}
		else if (i % 3 == 0) {
			ans[i - 1] = "Fizz";
		}
		else if (i % 5 == 0) {
			ans[i - 1] = "Buzz";
		}
		else {
			ans[i - 1] = to_string(i);
		}
	}

	return ans;
}

int main() {

	int n = 15;

	auto res = fizzBuzz(n);

	for (string s : res) {
		cout << s << endl;
	}
}