#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10, MOD=1e9+7;
ll arr[N],tree[4*N];

void build(int node,int st,int nd){
	if(st==nd){
		tree[node]=arr[st];
		return ;
	}

	int mid=(st+nd)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,nd);

	tree[node] = max(tree[2*node],tree[2*node+1]);
}

void update(int node,int st,int nd,int idx,int val){
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

ll query(int node,int st,int nd,int l,int r){
	if(st>r || nd<l) return -MOD;
	if(l<=st&&nd<=r) return tree[node];

	int mid=(st+nd)/2;
	ll q1 = query(2*node,st,mid,l,r);
	ll q2 = query(2*node+1,mid+1,nd,l,r);

	return max(q1,q2);
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	build(1,0,n-1);
	while(m--) {
	   int type;
	   cin>>type;
	   if(type==1){
	   	int idx,val;
	   	cin>>idx>>val;
	   	update(1,0,n-1,idx,val);	
	   }
	   else {
	   	 int x,l;
	   	 cin>>x>>l;
	   	 int lo=l,hi=n-1;
	   	 int ans=n;
	   	 while(hi>=lo){
	   	 	int mid = (hi+lo)/2;
	   	 	if(query(1,0,n-1,lo,mid)<x){
	   	 		lo=mid+1;
	   	 	}
	   	 	else {
	   	 		hi=mid-1;
	   	 		ans = min(ans,mid);
	   	 	}
	   	 }
	   	 cout<<(ans==n ? -1: ans)<<endl;
	   }
	}
}