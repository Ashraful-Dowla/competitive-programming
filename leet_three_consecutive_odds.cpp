/*
https://leetcode.com/problems/three-consecutive-odds/editorial/?envType=daily-question&envId=2024-07-01
*/
#include <bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {

	for (int i = 0; i + 2 < arr.size(); ++i) {
		if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
			return true;
		}
	}

	return false;
}

int main() {

	vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};

	cout << threeConsecutiveOdds(arr) << endl;
}