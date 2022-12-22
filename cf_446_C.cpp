#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=1e9+9,N=3e5+10;
ll tree[4*N],arr[N],pf[N],lazy[4*N],fib[N];

void fib_generate(){
	fib[1]=fib[2]=1;
	pf[1]=1;
	pf[2]=2;
	for(int i=3;i<=N;++i){
		fib[i] = (fib[i-1]%MOD + fib[i-2]%MOD)%MOD;
		pf[i] = (pf[i-1]%MOD + fib[i]%MOD)%MOD;
	}
}

void build(int node,int st,int nd){
	if(st==nd){
		tree[node]=arr[st];
		return ;
	}

	int mid = (st+nd)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,nd);

	tree[node] = tree[2*node] + tree[2*node+1];
	tree[node]%=MOD;
}

void update(int node,int st,int nd,int l,int r){
	if(lazy[node]!=0){
		tree[node]+=(pf[nd-lazy[node]+1]-pf[st-lazy[node]]);
		tree[node]%=MOD;
		lazy[2*node]=lazy[node];
		lazy[2*node+1]=lazy[node];
	}
	lazy[node]=0;

	if(st>r || nd<l) return ;
	if(l<=st&&nd<=r) {
		tree[node]+=(pf[nd-l+1]-pf[st-l]);
		tree[node]%=MOD;
		if(st!=nd){
			lazy[2*node]=l;
			lazy[2*node+1]=l;
		}
		return ;
	}
	int mid = (st+nd)/2;
	update(2*node,st,mid,l,r);
	update(2*node+1,mid+1,nd,l,r);
	tree[node] = tree[2*node] + tree[2*node+1];
	tree[node]%=MOD;
}

ll query(int node,int st,int nd,int l,int r){
	if(lazy[node]!=0){
		tree[node]+=(pf[nd-lazy[node]+1]-pf[st-lazy[node]]);
		tree[node]%=MOD;
		lazy[2*node]=lazy[node];
		lazy[2*node+1]=lazy[node];
	}
	lazy[node]=0;

	if(st>r || nd<l) return 0;
	if(l<=st&&nd<=r) return tree[node]%MOD;

	int mid = (st+nd)/2;
	ll q1 = query(2*node,st,mid,l,r);
	ll q2 = query(2*node+1,mid+1,nd,l,r);

	return (q1+q2)%MOD;

}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	fib_generate();
	build(1,1,n);
	while(m--) {
	    int t,l,r;
	    cin>>t>>l>>r;

	    if(t==1) update(1,1,n,l,r);
	    else cout<<query(1,1,n,l,r)<<endl;
	}

	for(int i=1;i<=10;++i){
		cout<<tree[i]<<" ";
	}
}