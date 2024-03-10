/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
*/
#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {

	vector<pair<char, int>> v;
	for (char ch : s) {
		if (v.empty() || v.back().first != ch) {
			v.push_back({ch, 1});
		}
		else {
			v.back().second++;
		}
	}

	int lo = 0, hi = v.size() - 1;
	while (lo < hi) {
		if (v[lo].first ==  v[hi].first) {
			lo++, hi--;
		}
		else {
			break;
		}
	}

	if (lo == hi) {
		return v[lo].second == 1;
	}

	int ans = 0;
	for (int i = lo; i <= hi; ++i) {
		ans += v[i].second;
	}
	return ans;
}

int main() {

	// string s = "aabccabba";
	// string s = "cabaabac";
	// string s = "ca";
	// string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
	string s = "abbbbbbbaabbbbbbbaa";
	cout << minimumLength(s) << endl;
}