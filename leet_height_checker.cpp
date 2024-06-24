/*
https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
*/
#include <bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {

	vector<int> expected = heights;

	sort(expected.begin(), expected.end());

	int ans = 0;
	for (int i = 0; i < heights.size(); ++i) {
		if (expected[i] != heights[i]) {
			ans++;
		}
	}

	return ans;
}

int main() {

	vector<int> heights = {1, 1, 4, 2, 1, 3};
	cout << heightChecker(heights) << endl;
}