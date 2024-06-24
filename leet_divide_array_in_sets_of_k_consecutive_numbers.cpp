/*
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/submissions/1280489576/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossibleDivide(vector<int>& nums, int k) {

	multiset<ll> ms;
	for (int x : nums) {
		ms.insert(x * 1LL);
	}

	while (ms.size() > 0) {
		ll st = *ms.begin();
		for (ll x = st; x < st + k; ++x) {
			auto it = ms.find(x);
			if (it == ms.end()) {
				return false;
			}
			ms.erase(it);
		}
	}

	return true;
}

int main() {

	// vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 6};
	// int k = 4;

	// vector<int> nums = {3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
	// int k = 3;

	vector<int> nums = {1, 2, 3, 4};
	int k = 3;

	cout << isPossibleDivide(nums, k) << endl;
}