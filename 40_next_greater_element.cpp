#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>v) {
	vector<int>nge(v.size());
	stack<int>stk;
	for (int i = 0; i < v.size(); i++) {
		while (!stk.empty() && v[i] > v[stk.top()]) {
			nge[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}

	while (!stk.empty()) {
		nge[stk.top()] = -1;
		stk.pop();
	}

	return nge;
}

int main() {
	int n;
	cin >> n;
	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int>nge = NGE(vec);

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " " << (nge[i] == -1 ? nge[i] : vec[nge[i]]) << endl;
	}
}