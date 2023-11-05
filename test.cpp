#include <bits/stdc++.h>
using namespace std;

string s;

void solve(int open, int close) {

	if (open == 0 && close == 0) {
		cout << s << endl;
		return ;
	}


	if (open > 0) {
		s.push_back('(');
		solve(open - 1, close);
		s.pop_back();
	}

	if (close > 0 && close > open) {
		s.push_back(')');
		solve(open, close - 1);
		s.pop_back();
	}
}

int main() {

	int n = 3;
	solve(n, n);
}