/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi ans;

void merge_sort(vi& nums, vi& i_nums, int l, int r, int mid) {

	int l_sz = mid - l + 1;
	int L[l_sz + 1];

	int r_sz = r - mid;
	int R[r_sz + 1];

	for (int i = 0; i < l_sz; ++i) {
		L[i] = i_nums[i + l];
	}

	for (int i = 0; i < r_sz; ++i) {
		R[i] = i_nums[i + mid + 1];
	}

	L[l_sz] = R[r_sz] = n;

	int l_i = 0, r_i = 0;

	for (int i = l; i <= r; ++i) {

		if (nums[L[l_i]] > nums[R[r_i]]) {

			ans[L[l_i]] += (r_sz - r_i);

			i_nums[i] = L[l_i];
			l_i++;
		}
		else {
			i_nums[i] = R[r_i];
			r_i++;
		}
	}
}


void merge(vi& nums, vi& i_nums, int l, int r) {

	if (l == r) return ;

	int mid = (l + r) / 2;
	merge(nums, i_nums, l, mid);
	merge(nums, i_nums, mid + 1, r);
	merge_sort(nums, i_nums, l, r, mid);
}

vector<int> countSmaller(vector<int>& nums) {

	n = nums.size();
	vi i_nums(n);

	nums.push_back(INT_MIN);

	for (int i = 0; i < n; ++i) {
		i_nums[i] = i;
	}

	ans.assign(n, 0);
	merge(nums, i_nums, 0, n - 1);

	return ans;
}

int main() {

	// vector<int> nums = {5, 2, 6, 1};
	// vector<int> nums = { -1};
	vector<int> nums = { -1, -1};
	// vector<int> nums = {2, 0, 1};
	auto res = countSmaller(nums);

	for (int x : res) {
		cout << x << " ";
	}
}