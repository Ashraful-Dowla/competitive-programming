/*
https://leetcode.com/problems/construct-the-rectangle/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> constructRectangle(int area) {

	int d = INT_MAX;
	vector<int> ans(2);
	for (int i = 1; i * i <= area; ++i) {
		if (area % i == 0) {
			int l = i, w = area / i;

			if (abs(l - w) < d) {
				d = abs(l - w);
				ans[0] = l;
				ans[1] = w;
			}
		}
	}

	if (ans[0] < ans[1]) {
		swap(ans[0], ans[1]);
	}

	return ans;
}

int main() {

	// int area = 4;
	// int area = 37;
	int area = 122122;
	auto res = constructRectangle(area);

	cout << res[0] << " " << res[1] << endl;
}