/*
https://atcoder.jp/contests/abc338/tasks/abc338_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int v[N];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;

		if (a > b) swap(a, b);

		v[a] = i;
		v[b] = -i;
	}

	stack<int> stk;

	for (int i = 1; i <= 2 * n; ++i) {

		if (v[i] > 0) {
			stk.push(v[i]);
		}
		else {

			if (stk.top() + v[i] == 0) {
				stk.pop();
			}
			else {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}