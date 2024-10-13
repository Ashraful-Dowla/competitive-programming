/*
https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	bool endmark;
	node* next[10];
	node() {
		endmark = false;
		for (int i = 0; i < 10; ++i) {
			next[i] = NULL;
		}
	}
}* root;

void insert(string s) {

	node* curr = root;
	for (char ch : s) {
		int idx = ch - '0';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
	}
	curr->endmark = true;
}

int search(string s) {

	node* curr = root;
	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - '0';
		if (curr->next[idx] == NULL) {
			return i;
		}
		curr = curr->next[idx];
	}

	return s.size();
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

	root = new node();

	for (int x : arr2) {
		insert(to_string(x));
	}

	int mxlen = 0;
	for (int x : arr1) {
		int len = search(to_string(x));
		// cout << x << " " << len << endl;
		mxlen  = max(mxlen, len);
	}

	return mxlen;
}

int main() {

	vector<int> arr1 = {1, 10, 100};
	vector<int> arr2 = {1000};

	cout << longestCommonPrefix(arr1, arr2) << endl;
}