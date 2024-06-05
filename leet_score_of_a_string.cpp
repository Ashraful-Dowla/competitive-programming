/*
https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01
*/
#include <bits/stdc++.h>
using namespace std;

int scoreOfString(string s) {

	int ans = 0;
	for (int i = 0; i + 1 < s.size(); ++i) {
		int x = s[i] - 'a';
		int y = s[i + 1] - 'a';
		ans += abs(x - y);
	}

	return ans;
}

int main() {

	string s = "zaz";
	cout << scoreOfString(s) << endl;
}