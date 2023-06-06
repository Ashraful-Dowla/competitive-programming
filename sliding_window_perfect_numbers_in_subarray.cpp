#include <bits/stdc++.h>
using namespace std;

// 8 4
// 28 2 3 6 496 99 8128 24

//time complexity -> O(n*sqrt(n))
bool isPerfectNumber(int num) {
	int sum = 1;

	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			if (i == num / i) sum += i;
			else sum += i + num / i;
		}
	}

	return num == sum && num != 1;
}

int main() {
	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = isPerfectNumber(arr[i]);
	}

	if (n < k) {
		cout << -1 << endl;
		return 0;
	}

	int res = 0;
	for (int i = 0; i < k; ++i) {
		res += arr[i];
	}

	int sum = res;
	for (int i = k; i < n; ++i) {
		sum += (arr[i] - arr[i - k]);
		res = max(res, sum);
	}

	cout << res << endl;
}