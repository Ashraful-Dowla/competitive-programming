/*
https://leetcode.com/problems/reveal-cards-in-increasing-order/submissions/1228287197/?envType=daily-question&envId=2024-04-10
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {

	sort(deck.rbegin(), deck.rend());
	deque<int> dq;

	for (int x : deck) {

		if (dq.empty()) {
			dq.push_back(x);
		}
		else {
			int num = dq.front();
			dq.pop_front();
			dq.push_back(num);
			dq.push_back(x);
		}
	}

	vector<int> ans;
	while (!dq.empty()) {
		ans.push_back(dq.back());
		dq.pop_back();
	}

	return ans;
}

int main() {

	// vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
	// vector<int> deck = {1, 100};
	vector<int> deck = {1, 2, 3, 4, 5};


	auto res = deckRevealedIncreasing(deck);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}