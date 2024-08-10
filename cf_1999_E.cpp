//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1999/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 2e5 + 10;
int sum[N];

void solve() {

	int l, r;
	cin >> l >> r;
	cout << sum[r] + sum[l] - 2 * sum[l - 1] << endl;

}

int main() {
	Faster;

	int t;
	cin >> t;

	for (int i = 1; i < N; ++i) {
		int x = i;
		while (x) {
			sum[i]++;
			x /= 3;
		}
	}

	for (int i = 1; i < N; ++i) {
		sum[i] += sum[i - 1];
	}

	while (t--) {
		solve();
	}
}