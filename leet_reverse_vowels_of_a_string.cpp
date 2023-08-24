/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;

bool isVowel(char ch) {
	ch = tolower(ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s) {

	vector<pic> vec, vowels;

	for (int i = 0; i < s.size(); ++i) {
		if (isVowel(s[i])) {
			vowels.push_back({i, s[i]});
		}
		else {
			vec.push_back({i, s[i]});
		}
	}

	int lo = 0, hi = vowels.size() - 1;

	while (lo < hi) {
		swap(vowels[lo].second, vowels[hi].second);
		vec.push_back(vowels[lo]);
		vec.push_back(vowels[hi]);
		lo++, hi--;
	}

	if (lo == hi) {
		vec.push_back(vowels[lo]);
	}

	sort(vec.begin(), vec.end());

	string ans;
	for (pic p : vec) {
		ans.push_back(p.second);
	}

	return ans;
}

int main() {

	// string s = "hello";
	string s = "leetcode";
	cout << reverseVowels(s) << endl;
}