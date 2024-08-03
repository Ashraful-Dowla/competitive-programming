/*
https://leetcode.com/problems/filling-bookcase-shelves/description/?envType=daily-question&envId=2024-07-31
*/
#include <bits/stdc++.h>
using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

	int n = books.size();
	vector<int> width(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		width[i] = width[i - 1] + books[i - 1][0];
	}

	vector<int> dp(n + 1, 1e8);

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int height = 0;
		for (int j = i; j <= n; ++j) {

			height = max(height, books[j - 1][1]);
			int wd = width[j] - width[i - 1];

			if (wd <= shelfWidth) {
				dp[j] = min(dp[j], dp[i - 1] + height);
			}
		}
	}

	return dp[n];
}

int main() {

	vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
	int shelfWidth = 4;

	cout << minHeightShelves(books, shelfWidth);
}