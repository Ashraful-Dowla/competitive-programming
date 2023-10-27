#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;

vector<pci> vec, temp;

int solve(int i) {

	temp.push_back(vec[i]);
	solve(i + 1);
	temp.pop_back();

	solve(i + 1);
}

int findMinStep(string board, string hand) {

	for (int i = 0; i < board.size(); ++i) {
		if (vec.empty() || vec.back().first != board[i]) {
			vec.push_back({board[i], 1});
		}
		else {
			vec.back().second++;
		}
	}

}

int main() {

	string board = "WRRBBW", hand = "RB";

	cout << findMinStep(board, hand) << endl;
}