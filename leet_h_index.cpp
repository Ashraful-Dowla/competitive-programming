/*
https://leetcode.com/problems/h-index/description/
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

	sort(citations.begin(), citations.end());

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
	// vector<int> citations = {1, 3, 1};
	vector<int> citations = {1, 0};

	cout << hIndex(citations);
}