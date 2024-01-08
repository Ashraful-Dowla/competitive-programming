#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int up[N][20], depth[N], lg;

// time complexity -> O(N*log(N))
void preprocess(int n, vector<int>& parent) {

	lg = log2(n) + 1;

	parent[0] = 0;
	for (int v = 0; v < n; ++v) {
		up[v][0] = parent[v];

		if (v != 0) {
			depth[v] = depth[parent[v]] + 1;
		}
		for (int j = 1; j < lg; ++j) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}
	}
}

// time complexity -> O(log(N))
int get_kth_ancenstor(int node, int k) {

	if (depth[node] < k) {
		return -1;
	}

	for (int j = 0; j < lg; ++j) {
		if (k & (1 << j)) {
			node = up[node][j];
		}
	}

	return node;
}

int main() {

	// int n = 7;
	// vector<int> parent = { -1, 0, 0, 1, 1, 2, 2};

	int n = 15;
	vector<int> parent = { -1, 0, 1, 0, 1, 0, 5, 4, 7, 8, 9, 7, 10, 12, 13};

	preprocess(n, parent);

	// cout << get_kth_ancenstor(3, 1) << endl;
	// cout << get_kth_ancenstor(5, 2) << endl;
	// cout << get_kth_ancenstor(6, 3) << endl;


	for (int v = 0; v < n; ++v) {
		cout << v << "->";
		for (int j = 0; j < lg; ++j) {
			cout << up[v][j] << " ";
		}
		cout << endl;
	}


	cout << get_kth_ancenstor(10, 5) << endl;
	cout << get_kth_ancenstor(10, 6) << endl;
	cout << get_kth_ancenstor(6, 3) << endl;
}