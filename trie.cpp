#include <bits/stdc++.h>
using namespace std;

struct node
{
	bool endmark;
	node* next[27];
	node() {
		endmark = false;
		for (int i = 0; i < 26; ++i) {
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

bool search(string str) {
	node* curr = root;

	for (int i = 0; i < str.size(); ++i) {
		int idx = str[i] - 'a';
		if (curr->next[idx] == NULL) return false;
		curr = curr->next[idx];
	}
	return curr->endmark;
}

void del(node *curr) {
	for (int i = 0; i < 26; ++i) {
		if (curr->next[i]) {
			del(curr);
		}
	}
	delete(curr);
}

int main() {
	root = new node();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		insert(s);
	}

	int q;
	cin >> q;

	while (q--) {
		string s;
		cin >> s;
		cout << ( search(s) ? "YES" : "NO" ) << endl;
	}

	del(root);
}