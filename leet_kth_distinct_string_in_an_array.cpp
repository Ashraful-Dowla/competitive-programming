/*
https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
*/
#include <bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {

	map<string, pair<int, int>> mp;

	int i = 0;
	for (string s : arr) {
		mp[s].first = i;
		mp[s].second++;
		i++;
	}

	vector<int> res;
	for (auto p : mp) {
		string ch = p.first;
		if (mp[ch].second == 1) {
			res.push_back(mp[ch].first);
		}
	}

	if (k > res.size()) {
		return string();
	}

	sort(res.begin(), res.end());
	return arr[res[k - 1]];
}

int main() {

	vector<string> arr = {"d", "b", "c", "b", "c", "a"};
	int k = 2;

	cout << kthDistinct(arr, k) << endl;
}