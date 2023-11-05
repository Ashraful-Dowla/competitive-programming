/*
https://www.hackerearth.com/problem/algorithm/jiyas-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		long long sum = 1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum *= arr[i];
		}

		int least_significant = sum % 10;
		if (least_significant == 2 || least_significant == 3 || least_significant == 5) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}