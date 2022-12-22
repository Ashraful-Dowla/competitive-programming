#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int arr[N],tree[4*N];

void build(int node,int st,int nd){
	if(st==nd){
		tree[node]=arr[st];
		return;
	}

	int mid = (st+nd)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,nd);

	tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node, int st,int nd,int l, int r){
	if(st>r || nd<l) return INT_MIN;
	if(l<=st && nd<=r) return tree[node];

	int mid = (st+nd)/2;
	int q1 = query(2*node,st,mid,l,r);
	int q2 = query(2*node+1,mid+1,nd,l,r);

	return max(q1,q2);
}

void update(int node, int st, int nd, int idx,int val){
	if(st==nd){
		arr[st]=val;
		tree[node]=val;
		return ;
	}

	int mid = (st+nd)/2;
	if(idx<=mid) update(2*node,st,mid,idx,val);
	else update(2*node+1,mid+1,nd,idx,val);

	tree[node] = max(tree[2*node],tree[2*node+1]);
}

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	build(1,0,n-1);
	while(1) {
	   int type;
	   cin>>type;
	   if(type==-1) break;
	   
	   if(type==1){
	   	 int l,r;
	   	 cin>>l>>r;
	   	 int ans=query(1,0,n-1,l,r);
	   	 cout<<ans<<endl;
	   }
	   else {
	   	int idx,val;
	   	cin>>idx>>val;
	   	update(1,0,n-1,idx,val);
	   	cout<<query(1,0,n-1,0,n-1)<<endl;
	   }
	}
}