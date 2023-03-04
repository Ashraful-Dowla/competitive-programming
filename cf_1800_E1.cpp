/*
https://codeforces.com/contest/1800/problem/E1
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=2e5+10;
const int MOD=1e9+7;

int parent[N],sz[N];

void make(int v){
	parent[v]=v;
	sz[v]=1;
}

int find(int v){
	if(parent[v]==v) return v;
	return parent[v] = find(parent[v]);
}

void Union(int u,int v){
	int a = find(u);
	int b = find(v);

	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}

void solve(){
	int n,k;
	cin>>n>>k;

	string s,t;
	cin>>s>>t;

	s = "_"+s;
	t = "_"+t;

	for(int i=1;i<=n;++i){
		make(i);
	}

	for(int i=1;i<=n;++i){
		if(i+k<=n) Union(i,i+k);
		if(i+k+1<=n) Union(i,i+k+1);
	}

	string str_s[n+2], str_t[n+2];
	set<int> roots;

	for(int i=1;i<=n;++i){
		int r = find(i);
		roots.insert(r);

		str_s[r].push_back(s[i]);
		str_t[r].push_back(t[i]);
	}

	bool chk=true;
	for(auto r: roots){
		sort(str_s[r].begin(),str_s[r].end());
		sort(str_t[r].begin(),str_t[r].end());

		if(str_s[r]==str_t[r]) continue;

		chk=false;
		break;
	}

	cout<<(chk ? "YES": "NO")<<endl;

}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}