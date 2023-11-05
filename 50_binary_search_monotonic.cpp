#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int to_find;
	cin >> to_find;
	int lo = 0, hi = n - 1;
	int mid;

	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (vec[mid] < to_find) lo = mid + 1;
		else hi = mid;
	}

	if (vec[lo] == to_find) cout << lo << endl;
	else if (vec[hi] == to_find) cout << hi << endl;
	else cout << "Not Found" << endl;
}