/*
https://leetcode.com/problems/reverse-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {

	int lo = 0, hi = s.size() - 1;

	while (lo < hi) {
		swap(s[lo], s[hi]);
		lo++, hi--;
	}
}

int main() {

	// vector<char> s = {'h', 'e', 'l', 'l', 'o'};
	vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};

	reverseString(s);

	for (char ch : s) {
		cout << ch << ' ';
	}
}