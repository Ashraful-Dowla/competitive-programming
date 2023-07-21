#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(n)
// space complexity -> O(1)

int boyer_more_algo(vector<int>& nums) {

	int m_idx = 0, cnt = 1;
	for (int i = 0; i < nums.size(); ++i) {

		if (nums[i] == nums[m_idx]) cnt++;
		else cnt--;

		if (cnt == 0) {
			m_idx = i;
			cnt = 1;
		}
	}

	cnt = 0;
	for (int x : nums) {
		if (x == nums[m_idx]) cnt++;
	}

	return cnt > (nums.size() / 2) ?  nums[m_idx] : -1;
}

int main() {

	// vector<int> nums = {2, 3, 4, 3, 3};
	// vector<int> nums = {2, 2, 2, 3, 4};
	vector<int> nums = {2, 3, 7, 3, 4};

	cout << boyer_more_algo(nums) << endl;
}