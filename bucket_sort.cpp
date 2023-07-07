#include <bits/stdc++.h>
using namespace std;


//worst time complexity -> O(n^2)
//best/average time complexity -> O(n)

void bucket_sort(vector<int>& vec) {

	int n = vec.size();
	int bucket = n - 1;
	vector<int> list[bucket];

	int mx = *max_element(vec.begin(), vec.end());
	int mn = *min_element(vec.begin(), vec.end());

	int range = ceil((mx - mn) * 1.0 / bucket * 1.0);

	for (int i = 0; i < n; ++i) {
		int idx = (vec[i] - mn) / range;
		list[idx].push_back(vec[i]);
	}

	for (int i = 0; i < bucket; ++i) {
		sort(list[i].begin(), list[i].end());
	}

	int idx = 0;
	for (int i = 0; i < bucket; ++i) {
		for (int val : list[i]) {
			vec[idx++] = val;
		}
	}
}

int main() {
	vector<int> vec = {22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14};

	bucket_sort(vec);

	for (auto x : vec) {
		cout << x << " ";
	}
	cout << endl;
}