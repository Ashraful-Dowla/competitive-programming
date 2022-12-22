/*
https://codeforces.com/problemset/problem/522/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=500;

int depth[N];
bool visited[N];
map<string,int> mp;
vector<int> graph[N];

void dfs(int vertex){
	visited[vertex]=true;

	for(auto &child: graph[vertex]){
		if(visited[child]) continue;

		dfs(child);
		depth[vertex] = max(depth[vertex],depth[child]+1);
	}
}

int main(){
	int n;
	cin>>n;

	int t=0,idx;
	for(int i=0;i<n;++i){
		string x,r,y;
		cin>>x>>r>>y;

		transform(x.begin(),x.end(),x.begin(),::tolower);
		transform(y.begin(),y.end(),y.begin(),::tolower);

		if(mp[x]==0) mp[x]=++t;
		if(mp[y]==0) mp[y]=++t;

		graph[mp[x]].push_back(mp[y]);
		graph[mp[y]].push_back(mp[x]);

		if(x=="polycarp") idx=mp[x];
		else if(y=="polycarp") idx=mp[y];
	}
		
	dfs(idx);

	cout<<depth[idx]+1<<endl;
}