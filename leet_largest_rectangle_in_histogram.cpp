/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/
#include <bits/stdc++.h>
using namespace std;

//time complexity-> O(N)
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();

	stack<int> stk;

	vector<int> left(n, 0), right(n, 0);

	for (int i = 0; i < n; ++i) {

		while (!stk.empty() && heights[i] <= heights[stk.top()]) {
			stk.pop();
		}

		if (stk.empty()) left[i] = 0;
		else left[i] = stk.top() + 1;

		stk.push(i);
	}

	while (!stk.empty()) {
		stk.pop();
	}

	for (int i = n - 1; i >= 0; --i) {

		while (!stk.empty() && heights[i] <= heights[stk.top()]) {
			stk.pop();
		}

		if (stk.empty()) right[i] = n - 1;
		else right[i] = stk.top() - 1;

		stk.push(i);
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, (right[i] - left[i] + 1) * heights[i]);
	}

	return mx;
}

int main() {

	// vector<int> heights = {2, 1, 5, 6, 2, 3};
	// vector<int> heights = {4, 3, 1, 5, 0, 5};
	// vector<int> heights = {1, 5, 3, 5, 6};
	vector<int> heights = {5, 1, 4, 4, 5};
	cout << largestRectangleArea(heights);
}