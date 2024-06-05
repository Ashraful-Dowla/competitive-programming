/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/submissions/1271068356/?envType=daily-question&envId=2024-05-29
*/
#include <bits/stdc++.h>
using namespace std;

int numSteps(string s) {

	int zero = 1, one = 0, n = s.size();

	for (int i = n - 1; i >= 0; --i) {

		if (s[i] == '1') one++;
		else if (one > 0) zero++;
	}

	return one == 1 ? n - 1 : zero + n;
}

int main() {

	string s = "1101011";
	cout << numSteps(s) << endl;
}