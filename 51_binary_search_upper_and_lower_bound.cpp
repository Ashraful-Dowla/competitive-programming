#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&v, int element) {
	int lo = 0, hi = v.size() - 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (v[mid] < element) lo = mid + 1;
		else hi = mid;
	}
	if (v[lo] >= element) return lo;
	else if (v[hi] >= element) return hi;
	return -1;
}

int upper_bound(vector<int>&v, int element) {
	int lo = 0, hi = v.size() - 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (v[mid] <= element) lo = mid + 1;
		else hi = mid;
	}
	if (v[lo] > element) return lo;
	else if (v[hi] > element) return hi;
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int element;
	cin >> element;

	int lb = lower_bound(vec, element);
	cout << lb << " " << (lb != -1 ? vec[lb] : -1) << endl;


	int ub = upper_bound(vec, element);
	cout << ub << " " << (ub != -1 ? vec[ub] : -1) << endl;

}