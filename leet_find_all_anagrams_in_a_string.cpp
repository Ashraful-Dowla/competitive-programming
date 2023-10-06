/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

int p_cnt[30], pf[30][30005];

vector<int> findAnagrams(string s, string p) {

	int k = p.size();
	for (int i = 0; i < k; ++i) {
		p_cnt[p[i] - 'a']++;
	}

	int n = s.size();
	s = '_' + s;
	for (int i = 1; i <= n; ++i) {
		pf[s[i] - 'a'][i]++;
	}

	for (char ch = 'a'; ch <= 'z'; ++ch) {
		for (int i = 1; i <= n; ++i) {
			pf[ch - 'a'][i] += pf[ch - 'a'][i - 1];
		}
	}

	vector<int> ans;
	for (int i = k; i <= n; ++i) {

		bool ok = true;
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			int len = pf[ch - 'a'][i] - pf[ch - 'a'][i - k];

			if (len == p_cnt[ch - 'a']) continue;
			ok = false;
			break;
		}

		if (ok) {
			ans.push_back(i - k);
		}
	}

	return ans;
}

int main() {

	// string s = "cbaebabacd", p = "abc";
	string s = "abab", p = "ab";

	auto res = findAnagrams(s, p);

	for (int x : res) {
		cout << x << " ";
	}
}