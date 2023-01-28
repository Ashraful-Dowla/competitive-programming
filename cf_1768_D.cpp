/*
https://codeforces.com/contest/1768/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int> graph[N];
int visited[N];

void clr(int n){
	for(int i=1;i<=n;++i){
		graph[i].clear();
	}
	memset(visited,0,sizeof(visited));
}

void dfs(int vertex, int c){
	visited[vertex]=c;

	for(auto child:graph[vertex]){
		if(visited[child]>0) continue;
		dfs(child,c);
	}
}

void solve(){
	int n;
	cin>>n;

	for(int i=1;i<=n;++i){
		int v;
		cin>>v;
		graph[i].push_back(v);
	}

	int cnt=0;
	for(int i=1;i<=n;++i){
		if(visited[i]==0){
			dfs(i,++cnt);
		}
	}

	int res = n-cnt+1;
	for(int i=2;i<=n;++i){
		if(visited[i]==visited[i-1]){
			res-=2;
			break;
		}
	}
	cout<<res<<endl;

	clr(n);
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}