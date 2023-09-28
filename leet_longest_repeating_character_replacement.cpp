/*
https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/
#include <bits/stdc++.h>
using namespace std;

int pf[30][100005];

int solve(char ch, int len, int n) {

	int k = INT_MAX;
	for (int i = len; i <= n; ++i) {
		int d = pf[ch - 'A'][i] - pf[ch - 'A'][i - len];
		k = min(k, len - d);
	}

	return k;
}

int characterReplacement(string s, int k) {

	s = "_" + s;

	int n = s.size() - 1;
	for (int i = 1; i <= n; ++i) {
		pf[s[i] - 'A'][i]++;
	}

	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		for (int i = 1; i <= n; ++i) {
			pf[ch - 'A'][i] += pf[ch - 'A'][i - 1];
		}
	}

	int ans = 0;
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		int lo = 0, hi = n;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (solve(ch, mid, n) <= k) {
				lo = mid + 1;
				ans = max(ans, mid);
			}
			else {
				hi = mid - 1;
			}
		}
	}

	return ans;
}

int main() {
	// string s = "AABABBA";
	// int k = 4;

	// string s = "ABAB";
	// int k = 3;

	string s = "IMNJJTRMJEGMSOLSCCQICIHLQIOGBJAEHQOCRAJQMBIBATGLJDTBNCPIFRDLRIJHRABBJGQAOLIKRLHDRIGERENNMJSDSSMESSTR";
	int k = 2;

	cout << characterReplacement(s, k) << endl;
}