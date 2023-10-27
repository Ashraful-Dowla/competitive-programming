/*
https://www.hackerearth.com/problem/algorithm/borrow-robo/
--incomplete
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int hsh[N];

int main() {
	int n;
	cin >> n;
	int arr[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		hsh[arr[i]]++;
	}
	int q;
	cin >> q;
	while (q--) {
		int indx, p;
		cin >> indx >> p;

		int cnt = 0;
		hsh[arr[indx]]--;
		if (p > arr[indx]) {
			cnt += (hsh[p] + hsh[p - arr[indx]]);
			if (cnt == 0) cnt = -1;
		}
		else if (p < arr[indx]) {
			cnt += (hsh[p] + hsh[arr[indx] - p]);
			if (cnt == 0) cnt = -1;
		}

		cout << cnt << endl;

	}
}