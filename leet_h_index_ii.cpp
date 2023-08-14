/*
https://leetcode.com/problems/h-index-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& citations, int h) {

	int cnt = 0;
	for (int x : citations) {
		if (x >= h) cnt++;
	}

	return cnt;
}


int hIndex(vector<int>& citations) {

	int n = citations.size();
	int lo = 1, hi = citations[n - 1];

	int h = 0;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;

		if (solve(citations, mid) >= mid) {
			lo = mid + 1;
			h = mid;
		}
		else {
			hi = mid - 1;
		}
	}

	return h;
}

int main() {

	// vector<int> citations = {0, 1, 3, 5, 6};
	// vector<int> citations = {1, 2, 100};
	// vector<int> citations = {1, 2, 3, 5, 8, 9};
	// vector<int> citations = {1, 2};
	// vector<int> citations = {100};
	// vector<int> citations = {11, 15};
	vector<int> citations = {1, 3, 1};

	cout << hIndex(citations);

}