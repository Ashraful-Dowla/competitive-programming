/*
https://atcoder.jp/contests/abc306/tasks/abc306_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
ll arr[N];

int main() {

	int n, k, q;
	cin >> n >> k >> q;

	multiset<pair<ll, int>> ms, ms2;

	for (int i = 1; i <= k; ++i) {
		ms.insert({0LL, i});
	}

	for (int i = k + 1; i <= n; ++i) {
		ms2.insert({0LL, i});
	}

	ll sum = 0;
	while (q--) {
		int x;
		ll y;

		cin >> x >> y;

		if (ms.find({arr[x], x}) != ms.end()) {

			ms.erase({arr[x], x});
			sum -= arr[x];

			if (ms2.size() == 0) {
				ms.insert({y, x});
				sum += y;
			}
			else {
				auto last = *(--ms2.end());

				if (y >= last.first) {
					ms.insert({y, x});
					sum += y;
				}
				else {
					ms.insert(last);
					sum += last.first;

					ms2.erase(last);
					ms2.insert({y, x});
				}
			}

			arr[x] = y;

		}
		else {

			ms2.erase({arr[x], x});

			arr[x] = y;
			ms.insert({arr[x], x});

			sum += y;
			sum -= ms.begin()->first;

			ms2.insert(*ms.begin());
			ms.erase(ms.begin());
		}


		cout << sum << endl;
	}
}