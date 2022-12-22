/*
https://codeforces.com/contest/1336/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+10;
ll n,k;
vector<ll> graph[N],ans;
bool visited[N];

bool cmp(ll a,ll b){
	return a>b;
}

ll dfs(ll u,ll p, ll d){
	ll sz=1;
	for(ll v:graph[u]){
		if(v!=p){
			sz+=dfs(v,u,d+1);
		}
	}

	ans.push_back(d-sz+1);
	return sz;
}

int main(){
	cin>>n>>k;

	for(int i=0;i<n-1;++i){
		ll u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0,0);
	sort(ans.begin(),ans.end(),cmp);
	cout<<accumulate(ans.begin(),ans.begin()+k,0LL)<<endl;
}