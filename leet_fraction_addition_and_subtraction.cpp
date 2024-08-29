/*
https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string fractionAddition(string expression) {

	if (expression[0] != '-') {
		expression = "+" + expression;
	}

	int i = 0, n = expression.size();
	vector<int> v;
	while (i < n) {
		string num;
		if (expression[i] == '+' || expression[i] == '-') {
			num.push_back(expression[i]);
		}
		i++;
		while (i < n && expression[i] != '+' && expression[i] != '-'
		        && expression[i] != '/') {
			num.push_back(expression[i]);
			++i;
		}
		v.push_back(stoi(num));
	}

	if (v.size() == 2) {
		return to_string(v[0]) + "/" + to_string(v[1]);
	}

	ll gcd = 0, prod = 1;
	for (int i = 1; i < v.size(); i += 2) {
		prod *= v[i];
		gcd = __gcd(gcd, 1LL * v[i]);
	}

	ll lcm = prod / gcd;

	ll sum = 0;
	for (int i = 1; i < v.size(); i += 2) {
		ll q = lcm / v[i];
		sum += v[i - 1] * q;
	}

	if (sum == 0) {
		return "0/1";
	}

	ll gd = __gcd(abs(sum), lcm);
	ll num = sum / gd, den =  lcm / gd;

	return to_string(num) + "/" + to_string(den);
}

int main() {

	// string expression = "-1/2+1/2";
	// string expression = "-1/2+1/2+1/3";
	// string expression = "1/3-1/2";
	string expression = "-7/3";
	cout << fractionAddition(expression) << endl;
}