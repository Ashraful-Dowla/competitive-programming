#include <bits/stdc++.h>
using namespace std;

// 6 3 20
// 7 5 4 6 8 9

// time complexity -> O(n)
int main() {
	int n, k, x;
	cin >> n >> k >> x;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int sum = 0, ans = 0;
	sum = accumulate(arr, arr + k, sum);

	if (sum < x) ans = sum;

	for (int i = k; i < n; ++i) {
		sum += (arr[i] - arr[i - k]);
		if (sum < x) {
			ans = max(ans, sum);
		}
	}

	cout << ans << endl;
}