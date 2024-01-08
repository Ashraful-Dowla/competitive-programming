#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N], sparse[N][17];

//time complexity -> O(nlogn)
void preprocess(int n) {
	for (int i = 0; i < n; ++i) {
		sparse[i][0] = i;
	}

	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++i) {
			int idx1 = sparse[i][j - 1];
			int idx2 = sparse[i + 1 << (j - 1)][j - 1];
			if (arr[idx1] < arr[idx2]) sparse[i][j] = idx1;
			else sparse[i][j] = idx2;
		}
	}
}

//time complexity -> O(1)
int query(int i, int j) {
	int len = j - i + 1;
	int k = (int)floor(log2((double)len));

	int idx1 = sparse[i][k];
	int idx2 = sparse[i + len - (1 << k)][k];

	return arr[idx1] <= arr[idx2] ? idx1 : idx2;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	preprocess(n);

	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << arr[query(l, r)] << endl;
	}
}