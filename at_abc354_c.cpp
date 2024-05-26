/*
https://atcoder.jp/contests/abc354/tasks/abc354_c
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int idx, a, c;
};

bool cmp(node x, node y) {
	return x.c < y.c;
}

int main() {

	int n;
	cin >> n;
	vector<node> v(n);

	for (int i = 0; i < n; ++i) {
		int a, c;
		cin >> a >> c;
		v[i] = {i + 1, a, c};
	}

	sort(v.begin(), v.end(), cmp);

	int p = 0;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (v[i].a > p) {
			p = v[i].a;
			ans.push_back(v[i].idx);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}