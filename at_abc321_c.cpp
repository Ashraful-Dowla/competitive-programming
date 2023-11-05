/*
https://atcoder.jp/contests/abc321/tasks/abc321_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;

	vector<ll> vec;
	for (int i = 1; i < (1 << 10); ++i) {

		ll num = 0;

		for (int j = 9; j >= 0; --j) {

			if (i & (1 << j)) {
				num = num * 10 + j * 1LL;
			}
		}

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	cout << vec[n] << endl;
}