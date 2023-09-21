#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(n^2)
void insertion_sort(vector<int>& vec) {

	int n = vec.size();
	for (int i = 1; i < n; ++i) {
		int key = vec[i];
		int j = i - 1;

		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

int main() {

	vector<int> vec = {12, 11, 13, 5, 6};

	insertion_sort(vec);

	for (int x : vec) {
		cout << x << " ";
	}
	cout << endl;
}+