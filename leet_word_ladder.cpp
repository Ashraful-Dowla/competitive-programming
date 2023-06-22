/*
https://leetcode.com/problems/word-ladder/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int>mp;
vector<int> graph[5005];
bool visited[5005];
int level[5005];

int wordDifference(string& w1, string& w2) {

	int d = 0;
	for (int i = 0; i < w1.size(); ++i) {
		if (w1[i] == w2[i]) continue;
		d++;
	}

	return d;
}

void bfs(int s) {

	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (auto child : graph[v]) {
			if (visited[child]) continue;

			visited[child] = true;
			q.push(child);
			level[child] = level[v] + 1;
		}
	}
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	int n = wordList.size();

	mp[beginWord] = 1;
	mp[endWord] = 2;

	int k = 3;
	for (int i = 0; i < n; ++i) {
		if (!mp[wordList[i]]) {
			mp[wordList[i]] = k++;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (wordDifference(beginWord, wordList[i]) == 1) {
			graph[mp[beginWord]].push_back(mp[wordList[i]]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (wordDifference(wordList[i], wordList[j]) == 1) {
				graph[mp[wordList[i]]].push_back(mp[wordList[j]]);
				graph[mp[wordList[j]]].push_back(mp[wordList[i]]);
			}
		}
	}

	bfs(1);

	return level[2] == 0 ? level[2] : level[2] + 1;
}

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

	// string beginWord = "hit", endWord = "cog";
	// vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};

	// string beginWord = "a", endWord = "c";
	// vector<string> wordList = {"a", "b", "c"};

	cout << ladderLength(beginWord, endWord, wordList);
}