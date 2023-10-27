/*
https://leetcode.com/problems/assign-cookies/
*/
#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {

	int g_sz = g.size(), s_sz = s.size();

	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int i = 0, j = 0, ans = 0;

	while (i < g_sz && j < s_sz) {
		if (s[j] >= g[i]) {
			ans++;
			i++, j++;
		}
		else {
			j++;
		}
	}

	return ans;
}

int main() {

	// vector<int> g = {1, 2, 3}, s = {1, 1};
	// vector<int> g = {1, 2}, s = {1, 2, 3};
	vector<int> g = {7, 8, 9, 10}, s = {5, 6, 7, 8};

	cout << findContentChildren(g, s);
}