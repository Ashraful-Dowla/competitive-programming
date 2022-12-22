#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
bool visited[N];

// time complexity -> O(V+E)

void dfs(int vertex){
	visited[vertex]=true;
	cout<<vertex<<endl;
	for(int child: graph[vertex]){
		cout<<"par "<<vertex<<" child "<<child<<endl;
		if(!visited[child]){
			// cout<<"par "<<vertex<<" child "<<child<<endl;
			dfs(child);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
}