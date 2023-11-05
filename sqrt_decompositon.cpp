#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(Q*sqrt(n))
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int len = sqrtl(n) + 1;
	int pre[len];

	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; ++i) {
		pre[i / len] += arr[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int sum = 0;
		for (int i = l; i <= r;) {
			if (i % len == 0 && i + len - 1 <= r) {
				sum += pre[i / len];
				i += len;
			}
			else {
				sum += arr[i];
				i++;
			}
		}
		cout << sum << endl;
	}
}