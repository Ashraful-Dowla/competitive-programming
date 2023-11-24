/*
https://atcoder.jp/contests/abc314/tasks/abc314_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 102;
vector<int> c(N);
bool row[N][40];

vector<pii> vec;

bool cmp(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		for (int j = 0; j < c[i]; ++j) {
			int b;
			cin >> b;
			row[i][b] = true;
		}
	}

	int x;
	cin >> x;

	for (int i = 1; i <= n; ++i) {
		if (row[i][x]) {
			vec.push_back({i, c[i]});
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	vector<int> ans;
	if (vec.size()) {

		ans.push_back(vec[0].first);
		for (int i = 1; i < vec.size(); ++i) {
			if (vec[0].second == vec[i].second) {
				ans.push_back(vec[i].first);
			}
		}
	}

	cout << ans.size() << endl;

	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

}