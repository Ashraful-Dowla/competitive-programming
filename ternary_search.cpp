#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(2*log3(n))
int main() {

	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int lo = 0, hi = v.size() - 1;
	int key = 3;

	while (lo <= hi) {

		int mid1 = lo + (hi - lo) / 3;
		int mid2 = hi - (hi - lo) / 3;

		if (key == v[mid1]) {
			cout << mid1 << endl;
			return 0;
		}
		if (key == v[mid2]) {
			cout << mid2 << endl;
			return 0;
		}

		if (key < v[mid1]) {
			hi = mid1 - 1;
		}
		else if (key > v[mid2]) {
			lo = mid2 + 1;
		}
		else {
			lo = mid1 + 1;
			hi = mid2 - 1;
		}
	}

	cout << -1 << endl;
}