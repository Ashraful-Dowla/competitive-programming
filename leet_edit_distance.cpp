/*
https://leetcode.com/problems/edit-distance/
*/
#include <bits/stdc++.h>
using namespace std;

string w1, w2;
int dp[505][505];

int solve(int i, int j) {

	if (i < 0 && j < 0) return 0;
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;

	if (dp[i][j] != -1) return dp[i][j];

	int cnt = INT_MAX;

	if (w1[i] == w2[j]) {
		cnt = min(cnt, solve(i - 1, j - 1));
	}
	else {
		//insert
		cnt = min(cnt, solve(i, j - 1) + 1);
		//remove
		cnt = min(cnt, solve(i - 1, j) + 1);
		//replace
		cnt = min(cnt, solve(i - 1, j - 1) + 1);
	}

	return dp[i][j] = cnt;
}

void clr() {
	for (int i = 0; i < 505; ++i) {
		for (int j = 0; j < 505; ++j) {
			dp[i][j] = -1;
		}
	}
}

int minDistance(string word1, string word2) {
	w1 = word1, w2 = word2;
	clr();
	return solve(w1.size() - 1, w2.size() - 1);
}

int main() {
	// string word1 = "horse", word2 = "ros";
	// string word1 = "intention", word2 = "execution";
	// string word1 = "", word2 = "execution";
	string word1 = "intention", word2 = "";

	cout << minDistance(word1, word2);
}