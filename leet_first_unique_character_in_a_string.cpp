/*
https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {

	set<int>st;
	vector<int>cnt(30, 0), unq(30, -1);

	for (int i = 0; i < s.size(); ++i) {

		int idx = s[i] - 'a';
		cnt[idx]++;

		if (cnt[idx] == 1) {
			unq[idx] = i;
		}
		else if (cnt[idx] == 2) {
			unq[idx] = -1;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < 26; ++i) {
		if (unq[i] == -1) continue;
		ans = min(ans, unq[i]);
	}

	return ans == INT_MAX ? -1 : ans;
}

int main() {

	// string s = "leetcode";
	// string s = "loveleetcode";
	string s = "aabb";

	cout << firstUniqChar(s) << endl;
}