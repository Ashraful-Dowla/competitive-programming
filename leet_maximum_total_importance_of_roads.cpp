/*
https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
*/
#include <bits/stdc++.h>
using namespace std;

long long maximumImportance(int n, vector<vector<int>>& roads) {

	vector<int> deg(n, 0), vis(n, 0);

	for (auto p : roads) {
		deg[p[0]]++;
		deg[p[1]]++;
	}

	multiset<pair<int, int>> ms;
	for (int i = 0; i < n; ++i) {
		ms.insert({ -deg[i], i});
	}

	int ct = n;

	while (ms.size() > 0) {
		auto it = ms.begin();
		int u = it->second;

		ms.erase(it);

		if (vis[u]) continue;
		vis[u] = ct--;
	}

	long long ans = 0;
	for (auto road : roads) {
		ans += vis[road[0]] + vis[road[1]];
	}

	return ans;
}

int main() {

	// vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
	// int n = 5;

	vector<vector<int>> roads = {{0, 3}, {2, 4}, {1, 3}};
	int n = 5;


	cout << maximumImportance(n, roads) << endl;
}