/*
https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/?envType=daily-question&envId=2024-09-15
*/
#include <bits/stdc++.h>
using namespace std;

int findTheLongestSubstring(string s) {

	map<char, int> ch;

	string p = "aeiou";
	for (int i = 0; i < p.size(); ++i) {
		ch[p[i]] = (1 << i);
	}

	vector<int> idx(32, -1);

	int pf = 0, len = 0;
	for (int i = 0; i < s.size(); ++i) {

		pf ^= ch[s[i]];
		if (idx[pf] == -1 && pf != 0) {
			idx[pf] = i;
		}

		len = max(len, i - idx[pf]);
	}

	return len;
}

int main() {

	string s = "eleetminicoworoep";
	cout << findTheLongestSubstring(s) << endl;
}