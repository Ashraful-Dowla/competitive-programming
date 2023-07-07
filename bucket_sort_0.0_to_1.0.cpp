#include <bits/stdc++.h>
using namespace std;


//worst time complexity -> O(n^2)
//best/average time complexity -> O(n)

void bucket_sort(vector<float>& vec) {

	int n = vec.size();
	vector<float> list[n];

	for (int i = 0; i < n; ++i) {
		int b = n * vec[i];
		list[b].push_back(vec[i]);
	}

	for (int i = 0; i < n; ++i) {
		sort(list[i].begin(), list[i].end());
	}

	int idx = 0;
	for (int i = 0; i < n; ++i) {
		for (auto val : list[i]) {
			vec[idx++] = val;
		}
	}
}

int main() {
	vector<float> vec = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

	bucket_sort(vec);

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}