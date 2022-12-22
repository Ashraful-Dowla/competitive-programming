/*
https://codeforces.com/contest/1559/problem/D1
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pr;

const int N=1e3+10;
vi parentM(N),szM(N),parentD(N),szD(N);

void make(int v, vi &parent, vi &sz){
	parent[v]=v;
	sz[v]=1;
}

int find(int v, vi &parent){
	if(parent[v]==v) return v;
	return parent[v] = find(parent[v],parent);
}

void Union(int a,int b, vi &parent, vi &sz){
	a = find(a, parent);
	b = find(b, parent);
	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}

int main(){
	int n,m1,m2;
	cin>>n>>m1>>m2;

	for(int i=1;i<=n;++i){
		make(i,parentM,szM);
		make(i,parentD,szD);
	}

	for(int i=0;i<m1;++i){
		int u,v;
		cin>>u>>v;
		Union(u,v,parentM,szM);
	}

	for(int i=0;i<m2;++i){
		int u,v;
		cin>>u>>v;
		Union(u,v,parentD,szD);
	}

	vector<pr> vec;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int m_a = find(i,parentM);
			int m_b = find(j,parentM);
			if(m_a==m_b) continue;

			int d_a = find(i,parentD);
			int d_b = find(j,parentD);
			if(d_a==d_b) continue;

			Union(i,j,parentM,szM);
			Union(i,j,parentD,szD);
			vec.push_back({i,j});
		}
	}
	cout<<vec.size()<<endl;

	for(pr &val: vec){
		cout<<val.first<<" "<<val.second<<endl;
	}
}