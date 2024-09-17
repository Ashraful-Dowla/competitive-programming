#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> divisors[N], graph[N], order, grundy(N);
vector<bool> vis(N);
int n, a[N];

void precompute() {

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
		}
	}
}

void top_sort(int u) {

	vis[u] = true;
	for (int v : graph[u]) {
		if (vis[v]) continue;
		top_sort(v);
	}

	order.push_back(u);
}

int mex(set<int> &s) {

	int res = 0;
	while (s.count(res)) {
		res++;
	}

	return res;
}



int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	precompute();

	for (int i = 0; i < n; ++i) {
		for (int x : divisors[a[i]]) {
			graph[a[i]].push_back(x);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (vis[a[i]]) continue;
		top_sort(a[i]);
	}

	for (int v : order) {
		set<int> s;
		for (int u : graph[v]) {
			if (v == u) continue;
			s.insert(grundy[u]);
		}
		grundy[v] = mex(s);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans ^= grundy[a[i]];
	}

	cout << (ans ? "Anna" : "Bruno") << endl;
}