/*
https://codeforces.com/problemset/problem/1311/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=105;
int visited[N+2];
vector<int>graph[N],pm;

void dfs(int v, int val){
	visited[v]=val;

	for(auto child:graph[v]){
		if(visited[child]!=-1) continue;
		dfs(child,val);
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n,m;
	    cin>>n>>m;

	    vector<int>vec(n);
	    for(int i=0;i<n;++i){
	    	cin>>vec[i];
	    }

	    memset(visited,-1,sizeof(visited));

	    for(int i=0;i<m;++i){
	    	int x;
	    	cin>>x;
	    	pm.push_back(x);
	    }

	    sort(pm.begin(),pm.end());

	    for(int i=0;i<m;++i){
			graph[pm[i]-1].push_back(pm[i]);
	    }

	    for(int i=0;i<m;++i){
	    	if(visited[pm[i]-1]==-1){
	    		dfs(pm[i]-1,pm[i]-1);
	    		int j=pm[i]-1;
	    		while(j<n && visited[j]==pm[i]-1){
	    			j++;
	    		}
	    		sort(vec.begin()+pm[i]-1,vec.begin()+j);
	    	}
	    }

	    bool chk=true;
	    for(int i=1;i<n;++i){
	    	if(vec[i]<vec[i-1]) {
	    		chk=false;
	    		break;
	    	}
	    }

	    cout<<(chk ? "YES":"NO")<<endl;

	    for(int i=0;i<n;++i){
	    	graph[i].clear();
	    }

	    pm.clear();

	}
}