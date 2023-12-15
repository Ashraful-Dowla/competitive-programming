/*
https://atcoder.jp/contests/abc332/tasks/abc332_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int k, G, M;
	cin >> k >> G >> M;

	int g = 0, m = 0;

	for (int i = 0; i < k; ++i) {

		if (g == G) {
			g = 0;
		}
		else if (m == 0) {
			m = M;
		}
		else {
			if (g + m >= G) {
				m = m - (G - g);
				g = G;
			}
			else {
				g = g + m;
				m = 0;
			}
		}
	}

	cout << g << " " << m << endl;
}