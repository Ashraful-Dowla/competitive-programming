#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(N^2)
void bubble_sort(vector<int> &v) {

	int n = v.size();

	for (int i = 0; i < n - 1; ++i) {
		bool isSwapped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped) {
			break;
		}
	}

	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {

	vector<int> v = { 64, 34, 25, 12, 22, 11, 90 };

	bubble_sort(v);
}