#include <bits/stdc++.h>
using namespace std;

//time complexity->O(n^2)
bool isPalindrome(int num) {
	int temp = num, number = 0;

	while (temp > 0) {
		number = number * 10 + temp % 10;
		temp /= 10;
	}

	return num == number;
}

int main() {
	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int num = 0;
	for (int i = 0; i < k; ++i) {
		num = num * 10 + arr[i];
	}

	if (isPalindrome(num)) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = k; i < n; ++i) {
		num = (num % (int)pow(10, k - 1)) * 10 + arr[i];

		if (isPalindrome(num)) {
			cout << i - k + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}