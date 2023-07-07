/*
https://leetcode.com/problems/repeated-dna-sequences/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {

	vector<string>ans;
	unordered_map<string, int> mp;

	int len = s.size();

	for (int i = 0; i + 9 < len; ++i) {

		string res = s.substr(i, 10);
		mp[res]++;

		if (mp[res] == 2) {
			ans.push_back(res);
		}
	}

	return ans;
}

int main() {

	// string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string s = "AAAAAAAAAAAAA";

	auto res = findRepeatedDnaSequences(s);

	for (auto r : res) {
		cout << r << endl;
	}
}