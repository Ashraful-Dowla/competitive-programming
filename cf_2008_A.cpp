//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/2008/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int sum;
bool ans;

void resolve(vector<int> &v, int i) {

	if (i >= v.size()) {
		if (sum == 0) {
			ans = true;
		}
		return ;
	}


	sum += v[i];
	resolve(v, i + 1);

	sum -= 2 * v[i];
	resolve(v, i + 1);
	sum += v[i];

}

void solve() {

	int a, b;
	cin >> a >> b;

	vector<int> v;

	for (int i = 0; i < a; ++i) {
		v.push_back(1);
	}

	for (int i = 0; i < b; ++i) {
		v.push_back(2);
	}

	sum = 0;
	ans = false;
	resolve(v, 0);

	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}