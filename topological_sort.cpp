#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
bool visited[N];
vector<int> graph[N];
stack<int> stk;

void topological_sort(int v) {

	visited[v] = true;

	for (int child : graph[v]) {
		if (visited[child]) continue;
		topological_sort(child);
	}

	stk.push(v);
}

int main() {

	int n = 6;
	vector<vector<int>> vec = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

	for (auto v : vec) {
		graph[v[0]].push_back(v[1]);
	}

	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;
		topological_sort(i);
	}

	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
}