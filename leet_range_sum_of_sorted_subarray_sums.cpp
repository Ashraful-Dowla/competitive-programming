#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
// brute force
// time complexity -> O(N^2)
int rangeSum(vector<int>& nums, int n, int left, int right) {

	ll mod = 1e9 + 7;

	vector<ll> res;
	for (int i = 0; i < n; ++i) {
		ll sum = 0;
		for (int j = i; j < n; ++j) {
			sum += nums[j];
			res.push_back(sum);
		}
	}

	sort(res.begin(), res.end());

	ll ans = 0;
	for (int i = left - 1; i < right; ++i) {
		ans = (ans + res[i]) % mod;
	}
	return ans;
}*/

// min heap
// time complexity -> O(N^2)
int rangeSum(vector<int>& nums, int n, int left, int right) {

	ll mod = 1e9 + 7;

	multiset<pair<ll, int>> ms;
	for (int i = 0; i < nums.size(); ++i) {
		ms.insert({nums[i], i});
	}

	ll ans = 0;
	for (int i = 1; i <= right; ++i) {
		auto p = *ms.begin();
		ms.erase(p);

		if (i >= left) {
			ans = (ans + p.first) % mod;
		}

		if (p.second + 1 < n) {
			p.first += nums[++p.second];
			ms.insert(p);
		}
	}

	return ans;
}



int main() {

	vector<int> nums = {1, 2, 3, 4};
	int n = 4;
	int left = 1;
	int right = 5;

	cout << rangeSum(nums, n, left, right);
}