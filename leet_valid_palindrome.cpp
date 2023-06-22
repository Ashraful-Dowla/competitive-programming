/*
https://leetcode.com/problems/valid-palindrome/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isVaild(char ch) {
	return ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9';
}

bool isPalindrome(string s) {

	string ns = "";
	for (char ch : s) {
		ch = tolower(ch);
		if (isVaild(ch)) {
			ns.push_back(ch);
		}
	}

	int lo = 0, hi = ns.size() - 1;

	while (lo <= hi) {
		if (ns[lo++] != ns[hi--]) return false;
	}

	return true;
}

int main() {
	// string s = "A man, a plan, a canal: Panama";
	// string s = "race a car";
	// string s = " ";
	// string s = "aa9as";

	cout << isPalindrome(s);
}