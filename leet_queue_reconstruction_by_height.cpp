/*
https://leetcode.com/problems/queue-reconstruction-by-height/
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

	sort(people.begin(), people.end(), cmp);

	int n = people.size();
	vector<vector<int>> ans(n);

	multiset<int> ms;
	ms.insert(people[0][0]);

	ans[0] = people[0];

	for (int i = 1; i < n; ++i) {

		auto it = ms.lower_bound(people[i][0]);
		int sz = ms.size() - distance(ms.begin(), it);
		int d = sz - people[i][1];

		int j = i - 1;
		while (d > 0) {
			ans[j + 1] = ans[j];
			d--, j--;
		}
		ans[j + 1] = people[i];
		ms.insert(people[i][0]);
	}

	return ans;
}

int main() {

	vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	// vector<vector<int>> people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};

	auto res = reconstructQueue(people);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << endl;
	}
}