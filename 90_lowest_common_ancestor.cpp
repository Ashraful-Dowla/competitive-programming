#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
int parent[N];

// complexity -> O(N)

void dfs(int vertex, int par=0){
	parent[vertex] = par;
	for(int child: graph[vertex]){
		if(child == par) continue;
		dfs(child,vertex);
	}
}

vector<int> path(int v){
	vector<int> ans;
	while(v!=0){
		ans.push_back(v);
		v=parent[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	int x,y;
	cin>>x>>y;
	vector<int>path_x = path(x);
	vector<int>path_y = path(y);

	int mn_ln = min(path_x.size(),path_y.size());

	int lca=-1;
	for(int i=0;i<mn_ln;++i){
		if(path_x[i]==path_y[i]) {
			lca = path_x[i];
		}
		else break;
	}
	cout<<lca<<endl;
}