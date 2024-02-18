/*
https://atcoder.jp/contests/abc292/tasks/abc292_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
vector<int> divisors[N];

void solve(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			divisors[j].push_back(i);
		}
	}
}

int main() {

	int n;
	cin >> n;

	solve(n);

	ll ans = 0;
	for (int ab = 1; ab < n; ++ab) {
		int cd = n - ab;
		ans += divisors[cd].size() * 1LL * divisors[ab].size();
	}
	cout << ans << endl;
}