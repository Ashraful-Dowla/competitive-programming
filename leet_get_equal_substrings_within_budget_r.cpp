/*
https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28
*/
#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {

	int n = s.size();
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		q.push(abs(s[i] - t[i]));
	}

	deque<int> dq;
	int ans = 0, curr = 0;
	while (!q.empty()) {

		while (!q.empty()) {
			dq.push_back(q.front());
			curr += q.front();
			q.pop();

			if (curr > maxCost) {
				break;
			}
			int sz = dq.size();
			ans = max(ans, sz);
		}

		while (!dq.empty()) {
			curr -= dq.front();
			dq.pop_front();

			if (curr <= maxCost) {
				break;
			}
		}
	}

	return ans;
}

int main() {


	// string s = "abcd";
	// string t = "bcdf";
	// int maxCost = 3;

	string s = "abcd";
	string t = "cdef";
	int maxCost = 3;

	cout << equalSubstring(s, t, maxCost) << endl;
}