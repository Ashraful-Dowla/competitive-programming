/*
https://codeforces.com/problemset/problem/1433/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5005;
vector<int> graph[N],vec;
int n;
bool visited[N],chk;

void dfs(int idx){

	visited[idx]=true;

	for(int i=0;i<n;++i){
		if(vec[idx]==vec[i] || visited[i]) continue;

		chk=true;
		graph[idx+1].push_back(i+1);
		dfs(i);
	}
}

void clr(){
	vec.clear();
	for(int i=1;i<=n;++i){
		graph[i].clear();
	}
	memset(visited,false,sizeof(visited));
	chk=false;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>n;

	    for(int i=0;i<n;++i){
	    	int x;
	    	cin>>x;
	    	vec.push_back(x);
	    }

	    visited[0]=true;
	    for(int i=0;i<n;++i){
	    	if(visited[i]){
	    		dfs(i);
	    	}
	    }

	    cout<<(chk? "YES":"NO")<<endl;
	    for(int i=1;i<=n;++i){
	    	if(graph[i].size()){
	    		for(auto val:graph[i]){
	    			cout<<i<<" "<<val<<endl;
	    		}
	    	}
	    }
	    clr();
	}
}