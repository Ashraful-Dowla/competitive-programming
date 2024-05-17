/*
https://atcoder.jp/contests/abc353/tasks/abc353_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;

struct node {

	node* next[26];
	int cnt[26];
	node() {
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
			cnt[i] = 0;
		}
	}
}* root;

void insert(string s) {

	node* curr = root;
	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr->cnt[idx]++;
		curr = curr->next[idx];
	}
}

void rec(node* curr) {

	for (int i = 0; i < 26; ++i) {
		if (curr->next[i] != NULL) {
			ll n = curr->cnt[i];
			ans += (n * (n - 1)) / 2;
			rec(curr->next[i]);
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
		insert(s);
	}

	rec(root);

	cout << ans << endl;
}