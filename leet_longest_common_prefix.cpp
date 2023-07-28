/*
https://leetcode.com/problems/longest-common-prefix/description/
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	bool endmark;
	node* next[27];
	node() {
		endmark = false;
		for (int i = 0; i < 27; ++i) {
			next[i] = NULL;
		}
	}
}* root;


void insert(string str) {

	node* curr = root;

	for (int i = 0; i < str.size(); ++i) {
		int idx = str[i] - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
	}

	curr->endmark = true;
}


int traverse(node* curr, int &idx) {

	int cnt = 0;
	for (int i = 0; i < 26; ++i) {
		if (curr->next[i] != NULL) {
			cnt++;
			idx = i;
		}
	}

	return cnt;
}

void del(node *curr) {

	for (int i = 0; i < 26; ++i) {
		if (curr->next[i]) {
			del(curr->next[i]);
		}
	}

	delete(curr);
}


string longestCommonPrefix(vector<string>& strs) {

	root = new node();

	for (string s : strs) {
		insert(s);
	}

	node* curr = root;
	int idx, sz = 0;
	while (traverse(curr, idx) == 1 && !curr->endmark) {
		curr = curr->next[idx];
		sz++;
	}

	del(root);

	return strs[0].substr(0, sz);
}

int main() {

	vector<string> strs = {"flower", "flow", "flight"};
	// vector<string> strs = {"dog", "racecar", "car"};
	// vector<string> strs = {"reflower", "flow", "flight"};
	// vector<string> strs = {"a"};
	// vector<string> strs = {"a", "b"};

	cout << longestCommonPrefix(strs) << endl;
	cout << "x" << endl;
}