/*
https://atcoder.jp/contests/abc324/tasks/abc324_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	bool ok = true;
	for (int i = 1; i < n; ++i) {
		if (arr[i] == arr[i - 1]) continue;

		ok = false;
		break;
	}

	cout << (ok ? "Yes" : "No") << endl;
}
