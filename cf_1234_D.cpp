/*
https://codeforces.com/contest/1234/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int tree[4*N];
string str;

void build(int node,int st,int nd){
	if(st==nd){
		tree[node]|=1<<(str[nd]-'a'+1);
		return ;
	}

	int mid = (st+nd)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,nd);

	tree[node]=tree[2*node]|tree[2*node+1];
}

int query(int node,int st,int nd,int l,int r){
	if(st>r || nd<l) return 0;
	if(l<=st&&nd<=r) return tree[node];

	int mid = (st+nd)/2;

	int q1 = query(2*node,st,mid,l,r);
	int q2 = query(2*node+1,mid+1,nd,l,r);

	return q1|q2;
}

void update(int node,int st,int nd,int idx,char val){
	if(st==nd){
		tree[node]^=1<<(str[nd]-'a'+1);
		str[st]=val;
		tree[node]|=1<<(val-'a'+1);
		return ;
	}

	int mid = (st+nd)/2;
	if(idx<=mid) update(2*node,st,mid,idx,val);
	else update(2*node+1,mid+1,nd,idx,val);

	tree[node] = tree[2*node]|tree[2*node+1];
}


int main(){
	cin>>str;
	build(1,0,str.size()-1);
	int q;
	cin>>q;
	while(q--) {
	    int type;
	    cin>>type;
	    if(type==1){
	    	int idx;
	    	char val;
	    	cin>>idx>>val;
	    	update(1,0,str.size()-1,idx-1,val);
	    }
	    else {
	    	int l,r;
	    	cin>>l>>r;
	    	int ans = query(1,0,str.size()-1,l-1,r-1);
	    	cout<<__builtin_popcount(ans)<<endl;
	    }

	}
}