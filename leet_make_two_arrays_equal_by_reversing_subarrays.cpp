/*
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03
*/
#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {

	sort(target.begin(), target.end());
	sort(arr.begin(), arr.end());

	return target == arr;
}

int main() {

	vector<int> target = {1, 2, 3, 4};
	vector<int> arr = {2, 4, 1, 3};

	cout << canBeEqual(target, arr) << endl;
}