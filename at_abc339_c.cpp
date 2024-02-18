/*
https://atcoder.jp/contests/abc339/tasks/abc339_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<ll> cs(n + 1);

	for (int i = 1; i <= n; ++i) {
		cs[i] = cs[i - 1] + v[i];
	}

	cout << cs.back() - *min_element(cs.begin(), cs.end()) << endl;
}