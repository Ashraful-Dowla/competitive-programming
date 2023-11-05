/*
https://atcoder.jp/contests/abc321/tasks/abc321_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	multiset<int> ms;

	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		int v;
		cin >> v;
		sum += v;
		ms.insert(v);
	}

	int ans = -1;
	for (int i = 0; i <= 100; ++i) {
		int nwsum = sum + i;

		ms.insert(i);

		int mn = *ms.begin();
		int mx = *(--ms.end());

		int obtain = nwsum - mn - mx;

		if (obtain >= x) {
			ans = i;
			break;
		}

		ms.erase(ms.find(i));
	}

	cout << ans << endl;
}