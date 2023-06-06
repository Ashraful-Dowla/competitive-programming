/*
https://leetcode.com/problems/permutation-sequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {

	vector<int>p;
	for (int i = 1; i <= n; ++i) {
		p.push_back(i);
	}

	int ct = 1;
	do {

		if (ct == k) break;
		ct++;

	} while (next_permutation(p.begin(), p.end()));

	string s;
	for (int i = 0; i < n; ++i) {
		s += to_string(p[i]);
	}

	return s;

}

int main() {
	int n = 9, k = 300000;

	cout << getPermutation(n, k) << endl;
}