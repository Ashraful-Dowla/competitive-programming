#include <bits/stdc++.h>
using namespace std;


// time complexity -> O(N^2)
void selection_sort(vector<int>& v) {

	for (int i = 0; i < v.size(); ++i) {

		int min_idx = i;
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min_idx]) {
				min_idx = j;
			}
		}

		if (min_idx != i) {
			swap(v[i], v[min_idx]);
		}
	}

	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {

	vector<int> v = { 64, 34, 25, 12, 22, 11, 90 };

	selection_sort(v);
}