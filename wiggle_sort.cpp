#include <bits/stdc++.h>
using namespace std;

//time complexity -> O(n)
void wiggle_sort(vector<int> nums) {

	for (int i = 1; i < nums.size(); ++i) {

		if (i % 2 == 1 && nums[i] < nums[i - 1]) {
			swap(nums[i], nums[i - 1]);
		}
		else if (i % 2 == 0 && nums[i] > nums[i - 1]) {
			swap(nums[i], nums[i - 1]);
		}
	}

	for (int x : nums) {
		cout << x << " ";
	}
	cout << endl;

}

// time complexity -> O(nlogn)
void wiggle_sort_2(vector<int> nums) {

	sort(nums.begin(), nums.end());

	for (int i = 1; i + 1 < nums.size(); i += 2) {
		swap(nums[i], nums[i + 1]);
	}

	for (int x : nums) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {

	vector<int> nums = {3, 5, 2, 1, 6, 4};
	wiggle_sort(nums);
	wiggle_sort_2(nums);
}