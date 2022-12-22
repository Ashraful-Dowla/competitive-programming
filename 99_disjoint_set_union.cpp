#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
int size[N];

// time complexity -> O(alpha(n))

//new node
void make(int v){
	parent[v]=v;
	size[v]=1;
}

// parent of group
int find(int v){
	if(v==parent[v]) return v;
	//path compression
	return parent[v] = find(parent[v]);
}

// union of two set
void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		//Union by size
		if(size[a]<size[b]) swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}


int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		make(i);
	}
	while(k--) {
	   int u,v;
	   cin>>u>>v;
	   Union(u,v);
	}

	int connect_components = 0;
	for(int i=1;i<=n;++i){
		if(find(i) == i) connect_components++;
	}
	cout<<connect_components<<endl;
}