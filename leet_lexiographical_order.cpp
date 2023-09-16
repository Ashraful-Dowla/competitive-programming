/*
https://leetcode.com/problems/lexicographical-numbers/description/
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	bool endmark;
	node* next[10];
	node() {
		endmark = false;
		for (int i = 0; i < 10; ++i) {
			next[i] = NULL;
		}
	}
}* root;

vector<int> ans;
string res;

void insert(string s) {
	node* curr = root;
	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - '0';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
	}
	curr->endmark = true;
}

void del(node * curr) {
	for (int i = 0; i < 10; ++i) {
		if (curr->next[i]) {
			del(curr->next[i]);
		}
	}
	delete(curr);
}

void lexical_sort(node* curr) {

	if (curr->endmark) {
		ans.push_back(stoi(res));
	}

	for (char ch = '0'; ch <= '9'; ++ch) {
		int idx = ch - '0';
		if (curr->next[idx]) {
			res.push_back(ch);
			lexical_sort(curr->next[idx]);
			res.pop_back();
		}
	}
}


vector<int> lexicalOrder(int n) {

	root = new node();

	for (int i = 1; i <= n; ++i) {
		insert(to_string(i));
	}

	lexical_sort(root);
	del(root);

	return ans;
}

int main() {

	// int n = 13;
	// int n = 2;
	int n = 100;
	auto v = lexicalOrder(n);

	for (int x : v) {
		cout << x << endl;
	}
}