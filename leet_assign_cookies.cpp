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

}