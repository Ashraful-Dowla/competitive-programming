/*
https://leetcode.com/problems/open-the-lock/submissions/1239624126/?envType=daily-question&envId=2024-04-22
*/
#include <bits/stdc++.h>
using namespace std;

map<string, bool> vis;

int bfs(string s, string target) {

	if (vis[s]) {
		return -1;
	}

	queue<pair<string, int>> q;
	q.push({s, 0});
	vis[s] = true;

	while (!q.empty()) {
		string p = q.front().first;
		int turn = q.front().second;
		q.pop();

		if (p == target) {
			return turn;
		}

		vector<string> graph;
		string k = p;
		for (int i = 0; i < 4; ++i) {
			k[i] = ((p[i] - '0' + 1) % 10) + '0';
			graph.push_back(k);
			k[i] = ((p[i] - '0' + 9) % 10) + '0';
			graph.push_back(k);
			k = p;
		}

		for (string x : graph) {
			if (!vis[x]) {
				q.push({x, turn + 1});
				vis[x] = true;
			}
		}
	}

	return -1;
}

int openLock(vector<string>& deadends, string target) {

	for (string s : deadends) {
		vis[s] = true;
	}

	return bfs("0000", target);
}

int main() {

	vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
	string target = "0202";

	cout << openLock(deadends, target) << endl;
}