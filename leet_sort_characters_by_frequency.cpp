/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;

vector<pci> vec;

bool cmp(pci a, pci b) {
	return a.second > b.second;
}

string frequencySort(string s) {

	sort(s.begin(), s.end());

	for (int i = 0; i < s.size(); ++i) {

		if (vec.empty() || vec.back().first != s[i]) {
			vec.push_back({s[i], 1});
		}
		else {
			vec.back().second++;
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	string ans;

	for (int i = 0; i < vec.size(); ++i) {
		int len = vec[i].second;
		char ch = vec[i].first;

		for (int j = 0; j < len; ++j) {
			ans.push_back(ch);
		}
	}

	return ans;
}

int main() {

	// string s = "tree";
	// string s = "cccaaa";
	string s = "Aabb";

	cout << frequencySort(s) << endl;
}