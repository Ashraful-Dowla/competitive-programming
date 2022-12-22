#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];

int height[N],depth[N];

void dfs(int vertex, int par=0){
	for(int child: graph[vertex]){
		if(child == par) continue ;
		depth[child] = depth[vertex]+1;
		dfs(child,vertex);
		height[vertex] = max(height[vertex], height[child]+1);
	}
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

	for(int i=1;i<=n;++i){
		cout<<depth[i]<<" "<<height[i]<<endl;
	}
}