#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int subtree_sum[N];
int even_count[N];

vector<int>graph[N];

void dfs(int vertex, int par = 0) {
	if (vertex % 2 == 0) even_count[vertex]++;
	subtree_sum[vertex] += vertex;
	for (int child : graph[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
		even_count[vertex] += even_count[child];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		cout << subtree_sum[i] << " " << even_count[i] << endl;
	}
	// int q;
	// cin>>q;
	// while(q--){
	// 	int v;
	// 	cin>>v;
	// 	cout<<subtree_sum[v]<<" "<<even_count[v]<<endl;
	// }
}