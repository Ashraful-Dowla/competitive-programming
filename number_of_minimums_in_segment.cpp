#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int N=1e5+10,MOD=1e9+7;
pr tree[4*N];
int arr[N];

void build(int node, int st, int nd){
	if(st==nd){
		tree[node].first=arr[st];
		tree[node].second=1;
		return ;
	}

	int mid = (st+nd)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,nd);

	pr p1 = tree[2*node];
	pr p2 = tree[2*node+1];

	if(p1.first<p2.first){
		tree[node].first=p1.first;
		tree[node].second=p1.second;
	}
	else if(p1.first>p2.first){
		tree[node].first=p2.first;
		tree[node].second=p2.second;
	}
	else {
		tree[node].first = p1.first;
		tree[node].second = p1.second + p2.second;
	}
}

pr query(int node,int st,int nd,int l,int r){
	if(st>r || nd<l) {
		pr p;
		p.first = MOD;
		p.second = -1;
		return p;
	}
	if(l<=st && nd<=r) return tree[node];

	int mid = (st+nd)/2;
	pr p1 = query(2*node,st,mid,l,r);
	pr p2 = query(2*node+1,mid+1,nd,l,r);

	pr ans;
	if(p1.first<p2.first) ans = p1;
	else if(p2.first<p2.first) ans = p2;
	else {
		ans.first = p2.first;
		ans.second = p1.first + p2.second;
	}

	return ans;
}

void update(int node,int st,int nd,int idx,int val){
	if(st==nd){
		arr[st]=val;
		tree[node].first = val;
		tree[node].second = 1;
		return ; 
	}

	int mid = (st+nd)/2;
	if(idx<=mid) update(2*node,st,mid,idx,val);
	else update(2*node+1,mid+1,nd,idx,val);

	pr p1 = tree[2*node];
	pr p2 = tree[2*node+1];

	if(p1.first<p2.first){
		tree[node].first=p1.first;
		tree[node].second=p1.second;
	}
	else if(p1.first>p2.first){
		tree[node].first=p2.first;
		tree[node].second=p2.second;
	}
	else {
		tree[node].first = p1.first;
		tree[node].second = p1.second + p2.second;
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	build(1,0,n-1);

	while(q--) {
	   int type;
	   cin>>type;
	   if(type==1){
	   	 int idx,val;
	   	 cin>>idx>>val;
	   	 update(1,0,n-1,idx,val);
	   }
	   else {
	   	 int l,r;
	   	 cin>>l>>r;
	   	 pr ans = query(1,0,n-1,l,r-1);
	   	 cout<<ans.first<<" "<<ans.second<<endl;
	   }
	}
}