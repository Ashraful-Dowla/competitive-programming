#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {

	int pivot = a[r];
	int i = l - 1;

	for (int j = l; j < r; ++j) {
		if (a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[r]);
	return i + 1;
}

// time complexity best -> O(nlogn)
// time complexity worst -> O(n^2)

void quick_sort(vector<int> &a, int l, int r) {

	if (l < r) {
		int pi = partition(a, l, r);
		quick_sort(a, l, pi - 1);
		quick_sort(a, pi + 1, r);
	}
}

int main() {

	// vector<int> a = {6, 3, 9, 5, 2, 8, 7};
	vector<int> a = {5, 4, 3, 2, 1};

	quick_sort(a, 0, a.size() - 1);

	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}