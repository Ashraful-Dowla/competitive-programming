/*
https://leetcode.com/problems/different-ways-to-add-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y, char sign) {

	if (sign == '+') return x + y;
	if (sign == '-') return x - y;
	return x * y;
}

vector<int> diffWaysToCompute(string expression) {

	vector<int> results;
	bool isNumber = true;

	for (int i = 0; i < expression.size(); ++i) {

		if (!isdigit(expression[i])) {

			isNumber = false;
			vector<int> left = diffWaysToCompute(expression.substr(0, i));
			vector<int> right = diffWaysToCompute(expression.substr(i + 1));

			for (int x : left) {
				for (int y : right) {
					int val = solve(x, y, expression[i]);
					results.push_back(val);
				}
			}
		}
	}

	if (isNumber) {
		results.push_back(stoi(expression));
	}
	return results;
}

int main() {

	// string expression = "2-1-1";
	string expression = "2*3-4*5";

	auto res = diffWaysToCompute(expression);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}