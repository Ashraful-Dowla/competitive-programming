/*
https://codeforces.com/problemset/problem/1461/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll arr[N],pf[N];
map<ll,bool>mp;

void generate(int l,int r){
	ll val = pf[r]-pf[l-1];
	mp[val]=true;

	ll mid = (arr[l]+arr[r])/2;
	auto it = upper_bound(arr+l,arr+r+1,mid);
	int idx = --it-arr;
	if(idx==r) return ;

	//left
	generate(l,idx);
	//right
	generate(idx+1,r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--) {
	   int n,q;
	   cin>>n>>q;
	   for(int i=1;i<=n;++i){
	   	  cin>>arr[i];
	   }

	   sort(arr+1,arr+n+1);
	   pf[0]=0;
	   for(int i=1;i<=n;++i){
	   	 pf[i]=(arr[i]+pf[i-1]);
	   }

	   generate(1,n);

	   for(int i=0;i<q;++i){
	   	  ll x;
	   	  cin>>x;
	   	  cout<<(mp[x] ? "Yes":"No")<<endl;
	   }
	   mp.clear();
	}
}