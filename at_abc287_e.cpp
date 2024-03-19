/*
https://atcoder.jp/contests/abc287/tasks/abc287_e
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	node* next[26];
	vector<int> v;
	node() {
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
		}
	}
}* root;

const int N = 5e5 + 10;
int lcp[N];

void insert(string s, int i) {

	node* curr = root;

	for (char ch : s) {
		int idx = ch - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
		curr->v.push_back(i);
	}
}

void solve(node* curr, int len) {
	for (int i = 0; i < 26; ++i) {
		if (curr->next[i] != NULL && curr->next[i]->v.size() > 1) {
			for (int x : curr->next[i]->v) {
				lcp[x] = max(lcp[x], len + 1);
			}
			solve(curr->next[i], len + 1);
		}
	}
}

int main() {

	int n;
	cin >> n;

	root = new node();

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		insert(s, i);
	}


	solve(root, 0);

	for (int i = 0; i < n; ++i) {
		cout << lcp[i] << endl;
	}
}