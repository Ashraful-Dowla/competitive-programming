/*
https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/1217945381/?envType=daily-question&envId=2024-03-30
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int k) {

	deque<int> dq;
	map<int, int> fq;

	int ans = 0;
	for (int x : nums) {

		fq[x]++;
		dq.push_back(x);

		while (!dq.empty() && fq.size() > k) {
			int d = dq.front();
			dq.pop_front();

			fq[d]--;

			if (fq[d] == 0) {
				fq.erase(d);
			}
		}

		ans += dq.size();
	}

	return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {

	return solve(nums, k) - solve(nums, k - 1);
}

int main() {

	vector<int> nums = {1, 2, 1, 2, 3};
	int k = 2;

	// vector<int> nums = {1, 2, 1, 3, 4};
	// int k = 3;

	cout << subarraysWithKDistinct(nums, k) << endl;
}