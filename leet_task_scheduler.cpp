/*
https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19
*/
#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

	int fq[26] = {0};
	for (char ch : tasks) {
		fq[ch - 'A']++;
	}

	multiset<int> ms;
	for (int i = 0; i < 26; ++i) {
		if (fq[i] > 0) {
			ms.insert(fq[i]);
		}
	}

	int ans = 0;
	while (!ms.empty()) {

		int cyc = n + 1;
		int cnt = 0;
		vector<int> v;

		while (cyc-- && !ms.empty()) {
			auto p = (--ms.end());
			if (*p > 1) {
				v.push_back(*p - 1);
			}
			ms.erase(p);
			cnt++;
		}

		for (int x : v) {
			ms.insert(x);
		}

		if (ms.empty()) ans += cnt;
		else ans += n + 1;
	}

	return ans;
}

int main() {

	vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
	int n = 2;
	// vector<char> tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
	// int n = 1;
	// vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
	// int n = 3;
	// vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
	// int n = 2;
	cout << leastInterval(tasks, n) << endl;
}