/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

struct node{

	node* next[2];
	node() {
		next[0] = next[1] = NULL;
	}
}* root;

void insert(int num) {

	node* curr = root;
	for (int i = 31; i >= 0; --i) {
		int bit = (num >> i) & 1;

		if (curr->next[bit] == NULL) {
			curr->next[bit] = new node();
		}
		curr = curr->next[bit];
	}
}

int search(int num) {

	node* curr = root;

	int res = 0;
	for (int i = 31; i >= 0; --i) {
		int bit = (num >> i) & 1;

		if (bit == 0) {
			if (curr->next[0] == NULL) {
				curr = curr->next[1];
				res |= (1 << i);
			}
			else {
				curr = curr->next[0];
			}
		}
		else {
			if (curr->next[1] == NULL) {
				curr = curr->next[0];
			}
			else {
				curr = curr->next[1];
				res |= (1 << i);
			}
		}
	}

	return res;
}

void del(node* curr) {

	for (int i = 0; i < 2; ++i) {
		if (curr->next[i]) {
			del(curr->next[i]);
		}
	}

	delete(curr);
}


int findMaximumXOR(vector<int>& nums) {

	root = new node();
	for (int x : nums) {
		insert(x);
	}

	int ans = 0;
	for (int a : nums) {
		int find = INT_MAX ^ a;
		int b = search(find);
		ans = max(ans, a ^ b);
	}

	del(root);

	return ans;
}

int main() {

	// vector<int> nums = {3, 10, 5, 25, 2, 8};
	vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
	cout << findMaximumXOR(nums);
}