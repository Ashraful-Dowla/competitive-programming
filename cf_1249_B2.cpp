/*
https://codeforces.com/contest/1249/problem/B2
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int> graph[N];
bool visited[N];
int ct=0,cnt[N];

void dfs(int v){
	visited[v]=true;
	ct++;

	for(int child:graph[v]){
		if(visited[child]) continue;
		dfs(child);
		cnt[child]=ct;
	}
}

void clr(int n){
	for(int i=1;i<=n;++i){
		graph[i].clear();
	}
	memset(visited,false,sizeof(visited));
	memset(cnt,0,sizeof(cnt));
	ct=0;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    for(int i=1;i<=n;++i){
	    	int v;
	    	cin>>v;
	    	graph[i].push_back(v);
	    }

	    for(int i=1;i<=n;++i){
	    	if(!visited[i]){
	    		dfs(i);
	    		cnt[i]=ct;
	    	}
	    	ct=0;
	    }

	    for(int i=1;i<=n;++i){
	    	cout<<cnt[i]<<" ";
	    }
	    cout<<endl;
	    clr(n);
	}
}