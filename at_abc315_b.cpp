/*
https://atcoder.jp/contests/abc315/tasks/abc315_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n + 1], tot = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		tot += arr[i];
	}

	int mid = (tot + 1) / 2, sum = 0;
	for (int i = 1; i <= n; ++i) {

		if (sum + arr[i] < mid) {
			sum += arr[i];
		}
		else {
			cout << i << " " << mid - sum << endl;
			break;
		}
	}
}