/*
https://leetcode.com/problems/word-ladder-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[605], parent[605];
int level[605];

vector<vector<string>> ans;
vector<vector<int>> res;
vector<int> temp;

bool wordDifference(string& w1, string& w2) {

	int d = 0;
	for (int i = 0; i < w1.size(); ++i) {
		if (w1[i] == w2[i]) continue;
		d++;
		if (d > 1) return false;
	}

	return true;
}

void bfs(int s) {

	queue<int> q;
	q.push(s);

	parent[s] = { -1};
	level[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (auto child : graph[v]) {
			if (level[child] > level[v] + 1) {
				level[child] = level[v] + 1;

				q.push(child);

				parent[child].clear();
				parent[child].push_back(v);
			}
			else if (level[child] == level[v] + 1) {
				parent[child].push_back(v);
			}
		}
	}
}

void dfs(int v) {

	if (v == -1) {
		res.push_back(temp);
		return;
	}

	for (auto child : parent[v]) {
		temp.push_back(child);
		dfs(child);
		temp.pop_back();
	}
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

	int n = wordList.size();

	int st = -1, nd = -1;

	for (int i = 0; i < n; ++i) {
		if (beginWord == wordList[i]) {
			st = i;
		}
		else if (endWord == wordList[i]) {
			nd = i;
		}
	}

	if (nd == -1) return ans;

	if (st == -1) {
		wordList.emplace(wordList.begin(), beginWord);
		st++;
		nd++;
		n++;
	}


	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (wordDifference(wordList[i], wordList[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}


	for (int i = 0; i < n; ++i) {
		level[i] = 100005;
	}

	bfs(st);

	temp.push_back(nd);
	dfs(nd);

	for (auto r : res) {
		reverse(r.begin(), r.end());

		vector<string> tt;
		for (int i = 1; i < r.size(); ++i) {
			tt.push_back(wordList[r[i]]);
		}

		ans.push_back(tt);
	}

	return ans;

}

int main() {
	// string beginWord = "hit", endWord = "cog";
	// vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

	// string beginWord = "hit", endWord = "cog";
	// vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};

	string beginWord = "a", endWord = "c";
	vector<string> wordList = {"a", "b", "c"};


	auto res = findLadders(beginWord, endWord, wordList);

	for (auto word : res) {
		for (string w : word) {
			cout << w << " ";
		}
		cout << endl;
	}
}