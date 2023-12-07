#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {

	int n, m;
	cin >> n >> m;

	vector<ll> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	vector<pll> ld(m);

	for (int i = 0; i < m; ++i) {
		cin >> ld[i].first;
	}

	for (int i = 0; i < m; ++i) {
		cin >> ld[i].second;
	}

	sort(ld.begin(), ld.end());

	ll ans = 0;
	multiset<ll> ms;

	for (int i = 0, j = 0; i < n; ++i) {

		while (j < m && ld[j].first <= p[i]) {
			ms.insert(ld[j++].second);
		}

		if (ms.size() > 0) {
			auto it = (--ms.end());
			ans += p[i] - *it;
			ms.erase(it);
		}
		else {
			ans += p[i];
		}
	}
	cout << ans << endl;
}