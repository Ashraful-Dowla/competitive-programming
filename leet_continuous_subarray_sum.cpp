/*
https://leetcode.com/problems/continuous-subarray-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkSubarraySum(vector<int>& nums, int k) {

    ll sum = 0;
    map<ll, int> mp;

    mp[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        ll mod = sum % k;

        if (mp.find(mod) == mp.end()) {
            mp[mod] = i;
        }
        else if (i - mp[mod] > 1) {
            return true;
        }
    }

    return false;
}

int main() {

    // vector<int> nums = {23, 2, 4, 6, 7};
    // int k = 6;

    // vector<int> nums = {23, 2, 6, 4, 7};
    // int k = 6;

    // vector<int> nums = {23, 2, 6, 4, 7};
    // int k = 13;

    vector<int> nums = {5, 0, 0, 0, 0};
    int k = 13;

    // vector<int> nums = {2, 4, 3};
    // int k = 6;

    cout << checkSubarraySum(nums, k) << endl;
}