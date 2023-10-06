/*
https://leetcode.com/problems/minimum-genetic-mutation/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<int> graph[100];
bool visited[100];
int level[100];

int diff(string a, string b) {

	int d = 0;
	for (int i = 0; i < 8; ++i) {
		if (a[i] == b[i]) continue;
		d++;
	}

	return d;
}

void bfs(int s) {

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int child : graph[v]) {
			if (visited[child]) continue;
			visited[child] = true;
			level[child] = level[v] + 1;
			q.push(child);
		}
	}
}

int minMutation(string startGene, string endGene, vector<string>& bank) {

	mp[startGene] = 1, mp[endGene] = 2;

	int cnt = 3;
	for (string s : bank) {
		if (mp[s] == 0) {
			mp[s] = cnt++;
		}
	}

	for (int i = 0; i < bank.size(); ++i) {
		for (int j = i + 1; j < bank.size(); ++j) {
			if (diff(bank[i], bank[j]) == 1) {
				int u = mp[bank[i]], v = mp[bank[j]];
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
	}

	for (int j = 0; j < bank.size(); ++j) {
		if (diff(startGene, bank[j]) == 1) {
			int u = mp[startGene], v = mp[bank[j]];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}

	bfs(1);

	if (visited[2]) return level[2];
	else return -1;

}

int main() {

	string startGene = "AACCGGTT", endGene = "AACCGGTA";
	vector<string>bank = {"AACCGGTA"};

	// string startGene = "AACCGGTT", endGene = "AAACGGTA";
	// vector<string>bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

	cout << minMutation(startGene, endGene, bank) << endl;
}