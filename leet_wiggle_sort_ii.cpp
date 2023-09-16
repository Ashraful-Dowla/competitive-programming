#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	int n = nums.size();
	vector<int> vec(n);

	int j = n - 1;
	for (int i = 1; i < n; i += 2) {
		vec[i] = nums[j--];
	}

	for (int i = 0; i < n; i += 2) {
		vec[i] = nums[j--];
	}

	for (int i = 0; i < n; ++i) {
		nums[i] = vec[i];
	}
}

int main() {

	// vector<int> nums = {1, 5, 1, 1, 6, 4};
	vector<int> nums = {1, 3, 2, 2, 3, 1};

	wiggleSort(nums);
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}

}