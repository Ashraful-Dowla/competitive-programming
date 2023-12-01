#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(n)
// space complexity -> O(n)

int subarray(vector<int>& v, int k) {

	int res = 0, curr_sum = 0;
	unordered_map<int, int> prev_sum;

	for (int i = 0; i < v.size(); ++i) {

		curr_sum += v[i];

		if (curr_sum == k) {
			res++;
		}

		if (prev_sum[curr_sum - k] > 0) {
			res += prev_sum[curr_sum - k];
		}

		prev_sum[curr_sum]++;
	}

	return res;
}

int main() {

	vector<int> v = { 10, 2, -2, -20, 10 };
	int k = -10;

	cout << subarray(v, k);
}