#include <bits/stdc++.h>
using namespace std;


int minimax(vector<int>&score, int node, int depth, bool isMax, int h) {

	if (depth == h) {
		return score[node];
	}

	if (isMax) {
		return max(minimax(score, 2 * node, depth + 1, false, h),
		           minimax(score, 2 * node + 1, depth + 1, false, h));
	}
	else {
		return min(minimax(score, 2 * node, depth + 1, true, h),
		           minimax(score, 2 * node + 1, depth + 1, true, h));
	}
}

int main() {

	vector<int> score = {3, 5, 2, 9, 12, 5, 23, 23};
	int h = log2(score.size());

	cout << minimax(score, 0, 0, true, h) << endl;
}