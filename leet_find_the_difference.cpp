/*
https://leetcode.com/problems/find-the-difference/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp;
char findTheDifference(string s, string t) {

	for (char ch : t) {
		mp[ch]++;
	}

	for (char ch : s) {
		mp[ch]--;
	}

	char ans;
	for (char ch : t) {
		if (mp[ch]) {
			ans = ch;
			break;
		}
	}

	return ans;
}

int main() {

	// string s = "abcd", t = "abcde";
	string s = "", t = "y";
	cout << findTheDifference(s, t);
}