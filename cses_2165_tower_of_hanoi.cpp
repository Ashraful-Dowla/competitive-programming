/*
https://cses.fi/problemset/task/2165/
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void hanoi(int n, int st, int nd) {


	if (n == 1) {
		ans.push_back({st, nd});
		return ;
	}

	int other = 6 - (st + nd);
	hanoi(n - 1, st, other);
	ans.push_back({st, nd});
	hanoi(n - 1, other, nd);
}

int main() {

	int n;
	cin >> n;

	hanoi(n, 1, 3);

	cout << ans.size() << endl;

	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}