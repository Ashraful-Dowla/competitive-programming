#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>>v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	int mx = 0, ans = 1;
	for (int i = 0; i + 1 < n; ++i) {
		if (v[i].second >= v[i + 1].first) {
			mx++;
			v[i + 1].second = max(v[i + 1].second, v[i].second);
		}
		else {
			ans = max(ans, mx);
			mx = 0;
		}
	}

	ans = max(ans, mx);
	cout << ans << endl;
}