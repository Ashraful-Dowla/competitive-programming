/*
https://atcoder.jp/contests/abc298/tasks/abc298_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int main() {

	int n;
	cin >> n;

	int q;
	cin >> q;

	vector<multiset<int>> boxes(N);
	vector<set<int>> cards(N);

	while (q--) {
		int t, i;
		cin >> t >> i;

		if (t == 1) {
			int j;
			cin >> j;

			boxes[j].insert(i);
			cards[i].insert(j);
		}
		else if (t == 2) {
			for (int x : boxes[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
		else {
			for (int x : cards[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
}