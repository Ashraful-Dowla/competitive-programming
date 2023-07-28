/*
https://leetcode.com/problems/expression-add-operators/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> ans, expression;

//time complexity -> O(N*4^N)
void solve(int idx, ll prev_operand, ll current_operand, ll val, string &num, ll target) {

	if (idx == num.size()) {
		if (target == val && current_operand == 0) {
			string t = accumulate(expression.begin(), expression.end(), string(""));
			ans.push_back(t.substr(1));
		}
		return ;
	}

	current_operand = current_operand * 10 + (num[idx] - '0');

	if (current_operand > 0) {
		solve(idx + 1, prev_operand, current_operand, val, num, target);
	}

	//addition
	expression.push_back("+");
	expression.push_back(to_string(current_operand));
	solve(idx + 1, current_operand, 0, val + current_operand, num, target);
	expression.pop_back();
	expression.pop_back();

	if (expression.size()) {

		//subtraction
		expression.push_back("-");
		expression.push_back(to_string(current_operand));
		solve(idx + 1, -current_operand, 0, val - current_operand, num, target);
		expression.pop_back();
		expression.pop_back();

		//multiplication
		expression.push_back("*");
		expression.push_back(to_string(current_operand));
		solve(idx + 1, prev_operand * current_operand, 0,
		      val - prev_operand + (prev_operand * current_operand), num, target);
		expression.pop_back();
		expression.pop_back();
	}
}

vector<string> addOperators(string num, int target) {
	solve(0, 0, 0, 0, num, target);
	return ans;
}

int main() {

	// string num = "123";
	// int target = 6;

	// string num = "232";
	// int target = 8;

	// string num = "3456237490";
	// int target = 9191;

	// string num = "105";
	// int target = 5;

	string num = "1";
	int target = 1;


	auto res = addOperators(num, target);

	cout << "x" << endl;

	for (string s : res) {
		cout << s << endl;
	}
}