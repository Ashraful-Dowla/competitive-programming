/*
https://atcoder.jp/contests/abc329/tasks/abc329_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 2e5 + 10;
int cnt[N];

struct cmp {
	bool operator()(pii const &a, pii const &b) const {
		if (a.first == b.first) {
			return !(a.second < b.second);
		}
		return !(a.first > b.first);
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	int arr[m];

	multiset<pii, cmp>s;

	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		s.insert({0, arr[i]});
	}

	for (int i = 0; i < m; ++i) {
		s.erase({cnt[arr[i]], arr[i]});
		s.insert({++cnt[arr[i]], arr[i]});

		auto res = *s.rbegin();
		cout << res.second << endl;
	}
}