/*
https://www.codechef.com/problems/MINEAT
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
ll arr[N], n, h;

ll calculateHours(ll k) {
	ll hr = 0;
	for (int i = 1; i <= n; ++i) {
		hr += (arr[i] / k);
		if (arr[i] % k != 0) hr++;
	}
	return hr;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> h;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}

		int lo = 1, hi = 1e9, mid, ans;


		while (lo <= hi) {
			mid = (hi + lo) / 2;
			if (calculateHours(mid) <= h) {
				hi = mid - 1;
				ans = mid;
			}
			else lo = mid + 1;
		}

		cout << ans << endl;
	}
}