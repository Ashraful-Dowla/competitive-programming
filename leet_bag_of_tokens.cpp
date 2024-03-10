/*
https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04
*/
#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {

	sort(tokens.begin(), tokens.end());

	int lo = 0, hi = tokens.size() - 1, score = 0, ans = 0;

	while (lo <= hi) {
		if (power >= tokens[lo]) {
			power -= tokens[lo];
			lo++, score++;
		}
		else if (score > 0) {
			power += tokens[hi];
			hi--, score--;
		}
		else {
			break;
		}
		ans = max(ans, score);
	}

	return ans;
}

int main() {

	// vector<int> tokens = {100, 200, 300, 400};
	// int power = 200;

	// vector<int> tokens = {200, 100};
	// int power = 150;

	vector<int> tokens = {100};
	int power = 50;

	cout << bagOfTokensScore(tokens, power);
}