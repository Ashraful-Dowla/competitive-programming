/*
https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/?envType=daily-question&envId=2024-09-25
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int cnt;
	node* next[27];
	node() {
		cnt = 0;
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
		}
	}
}* root;

void insert(string s) {

	node* curr = root;

	for (char ch : s) {
		int idx = ch - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
		curr->cnt++;
	}
}

int search(string s) {

	node* curr = root;

	int sum = 0;
	for (char ch : s) {
		int idx = ch - 'a';
		curr = curr->next[idx];
		sum += curr->cnt;
	}

	return sum;
}

vector<int> sumPrefixScores(vector<string>& words) {

	root = new node();
	for (string s : words) {
		insert(s);
	}

	vector<int> ans;
	for (string s : words) {
		int res = search(s);
		ans.push_back(res);
	}

	return ans;
}

int main() {

	vector<string> words = {"abc", "ab", "bc", "b"};

	auto res = sumPrefixScores(words);

	for (int x : res) {
		cout << x << " ";
	}
}