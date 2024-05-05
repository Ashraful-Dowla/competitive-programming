/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
*/
#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {

	string ans;
	bool ok = false;
	for (char c : word) {
		if (c == ch && !ok) {
			ans.push_back(c);
			reverse(ans.begin(), ans.end());
			ok = true;
		}
		else {
			ans.push_back(c);
		}
	}

	return ans;
}

int main() {

	string word = "abcdefd";
	char ch = 'd';

	cout << reversePrefix(word, ch) << endl;
}