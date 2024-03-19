/*
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
*/
#include <bits/stdc++.h>
using namespace std;

string customSortString(string order, string s) {

	unordered_map<char, int> mp;
	for (char ch : s) {
		mp[ch]++;
	}

	string ans;
	for (char ch : order) {
		while (mp[ch] > 0) {
			ans.push_back(ch);
			mp[ch]--;
		}
	}

	for (char ch : s) {
		while (mp[ch] > 0) {
			ans.push_back(ch);
			mp[ch]--;
		}
	}

	return ans;
}

int main() {


	// string order = "cba", s = "abcd";
	string order = "bcafg", s = "abcd" ;

	cout << customSortString(order, s) << endl;
}