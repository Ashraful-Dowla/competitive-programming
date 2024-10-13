// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// final: j-Ih-gfE-dCba

// Input: s = "ab-cdg"
// Output: "gd-cba"
// final: gd-cba

#include<bits/stdc++.h>
using namespace std;

bool check(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main() {

	string s;
	cin >> s;

	int lo = 0, hi = s.size() - 1;
	while (lo < hi) {
		if (!check(s[lo])) {
			lo++;
		}
		else if (!check(s[hi])) {
			hi--;
		}
		else {
			swap(s[lo], s[hi]);
			lo++, hi--;
		}
	}

	cout << s << endl;
	return 0;
}

