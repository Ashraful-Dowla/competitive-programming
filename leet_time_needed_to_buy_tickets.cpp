/*
https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1227444175/?envType=daily-question&envId=2024-04-09
*/
#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {

	int n = tickets.size();

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		q.push(i);
	}

	vector<int> ans(n, 0);
	vector<bool> chk(n, false);
	int line = 0;

	while (!q.empty()) {

		int idx = q.front();
		q.pop();

		if (tickets[idx] > 0) {
			if (!chk[idx]) {
				line++;
				chk[idx] = true;
			}
			ans[idx] += line;
			tickets[idx]--;

			if (tickets[idx] >= 0) {
				q.push(idx);
			}
		}
		else {
			line--;
		}
	}

	return ans[k];
}

int main() {

	vector<int> tickets = {2, 3, 2};
	int k = 2;

	// vector<int> tickets = {5, 1, 1, 1};
	// int k = 0;

	cout << timeRequiredToBuy(tickets, k) << endl;
}