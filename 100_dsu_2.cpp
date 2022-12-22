/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N],size[N];
multiset<int>sz;

void make(int v){
	parent[v]=v;
	size[v]=1;
	sz.insert(1);
}

int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void merge(int a,int b){
	sz.erase(sz.find(size[a]));
	sz.erase(sz.find(size[b]));

	sz.insert(size[a] + size[b]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(size[a]<size[b]) swap(a,b);
		parent[b]=a;
		merge(a,b);
		size[a]+=size[b];
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		make(i);
	}

	while(q--){
		int u,v;
		cin>>u>>v;
		Union(u,v);
		if(sz.size()==1) cout<<0<<endl;
		else {
			int mn = *(sz.begin());
			int mx = *(--sz.end());
			cout<<mx-mn<<endl;
		}
	}
}