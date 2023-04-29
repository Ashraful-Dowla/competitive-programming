//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1805/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vll vector<ll> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

vi graph[N];
bool visited[N];
int parent[N], sz[N];

void dfs(int vertex, vi &depth){
	visited[vertex]=true;
	for(int child: graph[vertex]){
		if(visited[child]) continue;

		depth[child] = depth[vertex] + 1;
		dfs(child, depth);
	}
}

int depth_node(int n,vi &depth){
	int v, mx=-1;
	for(int i=1;i<=n;++i){
		if(mx<depth[i]){
			mx=depth[i];
			v=i;
		}
		depth[i]=0;
		visited[i]=false;
	}

	return v;
}

void make(int n){
	for(int i=1;i<=n;++i){
		parent[i]=i;
		sz[i]=1;
	}
}

int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool same(int u,int v){
	return find(u)==find(v);
}

void Union(int a,int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}

void solve(){
	int n;
	cin>>n;

	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;

		graph[u].pb(v);
		graph[v].pb(u);
	}
	
	vi depth(n+1,0);
	dfs(1, depth);
	int x = depth_node(n, depth);

	dfs(x, depth);
	int y = depth_node(n, depth);

	vi depth_x(n+1,0), depth_y(n+1,0);
	dfs(x, depth_x);

	for(int i=1;i<=n;++i) visited[i]=false;
	dfs(y, depth_y);

	vi dis_x[n+2], dis_y[n+2];

	for(int i=1;i<=n;++i){
		dis_x[depth_x[i]].pb(i);
		dis_y[depth_y[i]].pb(i);
	}

	make(n);

	int cnt=n;
	vi ans(n+2);

	// prnt2(x,y);

	for(int i=n;i>=1;--i){

		for(int v: dis_x[i]){
			if(!same(x,v)){
				Union(x,v);
				cnt--;
			}
		}

		for(int v: dis_y[i]){
			if(!same(y,v)){
				Union(y,v);
				cnt--;
			}
		}

		ans[i]=cnt;
	}

	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;	

}

int main(){
	Faster;

	solve();
}