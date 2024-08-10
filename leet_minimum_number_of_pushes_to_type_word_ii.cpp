/*
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pci;

int minimumPushes(string word) {

	int cnt[30] = {0};
	for (char ch : word) {
		cnt[ch - 'a']++;
	}

	vector<pci>v;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (cnt[ch - 'a'] > 0) {
			v.push_back({cnt[ch - 'a'], ch});
		}
	}

	sort(v.begin(), v.end());

	vector<int> g[10];
	for (int i = v.size() - 1; i >= 0; --i) {
		char ch = v[i].second;
		int mn = 30, idx = -1;
		for (int j = 2; j <= 9; ++j) {
			if (g[j].size() < mn) {
				mn = g[j].size();
				idx = j;
			}
		}
		g[idx].push_back(ch);
	}

	int ans = 0;
	for (int i = 2; i <= 9; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			char ch = g[i][j];
			ans += (j + 1) * cnt[ch - 'a'];
		}
	}

	return ans;
}

int main() {

	string word = "aabbccddeeffgghhiiiiii";
	cout << minimumPushes(word) << endl;
}