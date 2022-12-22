/*
https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
bool visited[N];

vector<vector<int>> cc;
vector<int>current_cc;

void dfs(int vertex){
	visited[vertex]=true;
	current_cc.push_back(vertex);
	for(int child: graph[vertex]){
		if(!visited[child]){
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

	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			current_cc.clear();
			dfs(i);
			cc.push_back(current_cc);
			cnt++;
		}
	}
	cout<<cnt<<endl;

	for(auto c_cc: cc){
		for(int vertex: c_cc ){
			cout<<vertex<<" ";
		}
		cout<<endl;
	}
}