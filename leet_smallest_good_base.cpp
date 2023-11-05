#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll pw(ll p, int k) {

	ll res = 1;
	for (int i = 0; i < k; ++i) {
		res *= p;
	}

	return res;
}


string smallestGoodBase(string n) {

	ll nn = stoll(n), ans = 1e18;

	for (int i = 1; i < 64; ++i) {

		ll lo = 2, hi = nn - 1;

		while (lo <= hi) {
			ll mid = (lo + hi) / 2;

			ll p = (pw(mid, i) - 1) / (mid - 1);

			if (p == nn) {
				ans = min(ans, mid);
				hi = mid - 1;
			}
			else if (p > nn) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
	}

	return ans == 1e18 ? to_string(nn - 1) : to_string(ans);
}

int main() {

	// string n = "13";
	// string n = "4681";
	// string n = "1000000000000000000";
	string n = "2251799813685247";
	cout << smallestGoodBase(n) << endl;
}