/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
	ch = tolower(ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s) {

	int n = s.size();
	int lo = 0, hi = n - 1;

	vector<char> vec(n);

	while (lo <= hi) {

		while (lo < n && !isVowel(s[lo])) {
			vec[lo] = s[lo];
			lo++;
		}

		while (lo < hi && !isVowel(s[hi])) {
			vec[hi] = s[hi];
			hi--;
		}

		if (lo <= hi) {
			vec[hi] = s[lo];
			vec[lo] = s[hi];

			lo++, hi--;
		}
	}

	string ans;
	for (char ch : vec) {
		ans.push_back(ch);
	}

	return ans;
}

int main() {

	// string s = "hello";
	// string s = "leetcode";
	string s = " ";
	cout << reverseVowels(s) << endl;
}