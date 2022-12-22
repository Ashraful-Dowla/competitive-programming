/*
https://codeforces.com/contest/339/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=(1<<17)+5;
long tree[4*N],arr[N];
 
void build(int node,int st,int nd,int i){
	if(st==nd){
		tree[node]=arr[st];
		return ;
	}

	int mid=(st+nd)/2;
	build(2*node,st,mid,i+1);
	build(2*node+1,mid+1,nd,i+1);

	if(i%2==0) tree[node]=tree[2*node]^tree[2*node+1];
	else tree[node]=tree[2*node]|tree[2*node+1];
}

void update(int node,int st,int nd,int idx,long val, int i){
	if(st==nd){
		arr[st]=val;
		tree[node]=val;
		return ;
	}

	int mid = (st+nd)/2;
	if(idx<=mid) update(2*node,st,mid,idx,val,i+1);
	else update(2*node+1,mid+1,nd,idx,val,i+1);

	if(i%2==0) tree[node]=tree[2*node]^tree[2*node+1];
	else tree[node]=tree[2*node]|tree[2*node+1];
}

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<(1<<n);++i){
		cin>>arr[i];
	}
	
	build(1,0,(1<<n)-1,n%2);
	while(m--) {
	    int p;
	    long b;
	    cin>>p>>b;
	    update(1,0,(1<<n)-1,p-1,b,n%2);
	    cout<<tree[1]<<endl;
	}
}