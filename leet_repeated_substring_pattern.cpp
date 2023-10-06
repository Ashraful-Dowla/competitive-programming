/*
https://leetcode.com/problems/repeated-substring-pattern/description/
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10005

vector<int> divisors[N];

bool solve(string& s, int k) {

	int n = s.size();
	string t = s.substr(0, k), p;
	for (int i = 0; i < n / k; ++i) {
		p += t;
	}

	return s == p;
}

bool repeatedSubstringPattern(string s) {

	int n = s.size();

	int mx = 0;
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			if (divisors[j].empty()) {
				divisors[j].push_back(1);
			}
			divisors[j].push_back(i);
		}
	}

	for (int i = 0; i + 1 < divisors[n].size(); ++i) {
		if (solve(s, divisors[n][i])) {
			return true;
		}
	}

	return false;
}

int main() {

	// string s = "abab";
	// string s = "aba";
	// string s = "abcabcabcabc";
	// string s = "a";
	// string s = "ababab";
	string s = "babbabbabbabbab";
	cout << repeatedSubstringPattern(s) << endl;
}