/*
https://leetcode.com/problems/find-center-of-star-graph/submissions/1301500476/?envType=daily-question&envId=2024-06-27
*/
#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges) {

	map<int, int> mp;
	for (auto v : edges) {
		mp[v[0]]++;
		mp[v[1]]++;
	}

	for (auto p : mp) {
		if (p.second == edges.size()) {
			return p.first;
		}
	}
}

int main() {

	vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}};
	cout << findCenter(edges);
}