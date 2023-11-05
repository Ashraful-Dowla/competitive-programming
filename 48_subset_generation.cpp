#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets;

void generate(vector<int>&subset, int i, vector<int>&nums) {

	if (i == nums.size()) {
		subsets.push_back(subset);
		return ;
	}

	subset.push_back(nums[i]);
	generate(subset, i + 1, nums);
	subset.pop_back();

	generate(subset, i + 1, nums);
}

int main() {
	int n;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int>empty;
	generate(empty, 0, vec);

	for (auto subset : subsets) {
		for (auto el : subset) {
			cout << el << " ";
		}
		cout << endl;
	}
}