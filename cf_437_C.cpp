/*
https://codeforces.com/contest/427/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1e10;
const ll MOD=1e9+7;
const int N=1e5+10;

ll cost[N],dfs_low[N],dfs_num[N],cnt,mx=1,sum=0;
bool visited[N];
vector<ll> graph[N],store;
map<ll,ll> mp;

void dfs(int v){
	dfs_num[v]=dfs_low[v]=cnt++;
	visited[v]=true;
	store.push_back(v);

	for(int child:graph[v]){
		if(dfs_num[child]==-1){
			dfs(child);
		}
		if(visited[child]){
			dfs_low[v] = min(dfs_low[v],dfs_low[child]);
		}
	}


	if(dfs_num[v]==dfs_low[v]){
		ll mn=MAX;
		while(true) {
		    ll u = store.back();
		    store.pop_back();
		    
		    mp[cost[u]]++;
		    mn = min(mn,cost[u]);

		    visited[u]=false;
		    if(v==u) break;
		}
		sum+=mn;
		mx = (mx*mp[mn])%MOD;
		mp.clear();
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>cost[i];
	}

	int m;
	cin>>m;
	for(int i=0;i<m;++i){
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	memset(dfs_num,-1,sizeof(dfs_num));
	
	for(int i=1;i<=n;++i){
		if(dfs_num[i]==-1){
			dfs(i);
		}
	}
	cout<<sum<<" "<<mx<<endl;
}