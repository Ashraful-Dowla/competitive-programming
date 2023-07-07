/*
https://leetcode.com/problems/compare-version-numbers/description/
*/
#include <bits/stdc++.h>
using namespace std;

void convert(vector<int>& v, string s) {
	s += ".";

	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			v.push_back(res);
			res = 0;
		}
		else {
			char ch = s[i];
			res = res * 10 + (ch - '0');
		}
	}
}

int compareVersion(string version1, string version2) {

	vector<int> v1;
	convert(v1, version1);

	vector<int> v2;
	convert(v2, version2);

	int sz_1 = v1.size(), sz_2 = v2.size();

	if (sz_1 > sz_2) {
		for (int i = 0; i < sz_1 - sz_2; ++i) {
			v2.push_back(0);
		}
	}
	else {
		for (int i = 0; i < sz_2 - sz_1; ++i) {
			v1.push_back(0);
		}
	}

	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] > v2[i]) return 1;
		else if (v1[i] < v2[i]) return -1;
	}

	return 0;
}

int main() {
	// string version1 = "1.0";
	// string version2 = "1.0.0";

	// string version1 = "1.01";
	// string version2 = "1.001";

	string version1 = "0.1";
	string version2 = "1.1";

	cout << compareVersion(version1, version2);
}