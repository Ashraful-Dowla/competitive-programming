#include <bits/stdc++.h>
using namespace std;

// 6 51
// 1 4 45 6 10 19

// time complexity -> O(n)
int main() {
	int n, x;
	cin >> n >> x;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int sum = 0, minLength = n + 1, st = 0, nd = 0;

	while (nd < n) {
		while (sum <= x && nd < n) {
			sum += arr[nd++];
		}
		while (sum > x && st < n) {
			minLength = min(nd - st, minLength);
			sum -= arr[st++];
		}
	}

	cout << (minLength == n + 1 ? -1 : minLength) << endl;
}