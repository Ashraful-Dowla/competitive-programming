/*
https://cses.fi/problemset/task/1090/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	multiset<int> ms;

	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		ms.insert(p);
	}

	int ans = 0;
	while (ms.size() > 0) {

		int val = *ms.begin();
		ms.erase(ms.begin());

		if (ms.size()) {

			auto it = ms.lower_bound(x - val);

			if (it == ms.end()) {
				--it;
				if (val + *it <= x) {
					ms.erase(it);
				}
				ans++;
			}
			else {
				if (val + *it <= x) {
					ms.erase(it);
				}
				else if (it != ms.begin()) {
					--it;
					if (val + *it <= x) {
						ms.erase(it);
					}
				}
				ans++;
			}
		}
		else {
			ans++;
		}
	}

	cout << ans << endl;
}