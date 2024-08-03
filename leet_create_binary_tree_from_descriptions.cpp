/*
https://leetcode.com/problems/create-binary-tree-from-descriptions/submissions/1321425574/?envType=daily-question&envId=2024-07-15
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* root;
typedef pair<int, bool> pbi;
vector<pbi> g[100005];

void build(int val, TreeNode* curr) {

	curr->val = val;

	for (auto p : g[val]) {
		if (p.second) {
			if (curr->left == NULL) {
				curr->left = new TreeNode();
			}
			build(p.first, curr->left);
		} else {
			if (curr->right == NULL) {
				curr->right = new TreeNode();
			}
			build(p.first, curr->right);
		}
	}
}

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

	set<int> par, child;
	for (auto p : descriptions) {
		g[p[0]].push_back({p[1], p[2]});
		par.insert(p[0]);
		child.insert(p[1]);
	}

	int rt;
	for (auto p : par) {
		if (child.find(p) == child.end()) {
			rt = p;
			break;
		}
	}

	root = new TreeNode();
	build(rt, root);

	return root;
}

int main() {

	vector<vector<int>> descriptions = {
		{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}
	};

	createBinaryTree(descriptions);
}