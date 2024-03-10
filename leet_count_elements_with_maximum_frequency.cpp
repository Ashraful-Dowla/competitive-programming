/*
https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08
*/
#include <bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {

	map<int, int> mp;

	int fq = 0;
	for (int x : nums) {
		mp[x]++;
		fq = max(fq, mp[x]);
	}

	int ans = 0;
	for (auto p : mp) {
		if (p.second == fq) {
			ans += fq;
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 2, 2, 3, 1, 4};
	vector<int> nums = {1, 2, 3, 4, 5};

	cout << maxFrequencyElements(nums) << endl;
}