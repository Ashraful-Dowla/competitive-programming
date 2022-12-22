/*
https://codeforces.com/contest/459/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF=1e6+10;
const int N=1e6+10;
ll tree[N],arr[N];

map<ll,int>mp,ms;

void add(int k,ll x){
	while(k<=INF){
		tree[k]+=x;
		k+=(k&-k);
	}
}

ll sum(int k){
	ll sum=0;
	while(k>=1) {
		sum+=tree[k];
		k-=(k&-k);
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	for(int i=1;i<=n;++i){
		cin>>arr[i];
		++mp[arr[i]];
		add(mp[arr[i]],1);
	}

	ll cnt=0;
	for(int i=n;i>=1;--i){
		add(mp[arr[i]],-1);
		mp[arr[i]]--;
		++ms[arr[i]];
		// cout<<sum(INF)<<" "<<sum(ms[arr[i]])<<endl;
		ll sm = sum(INF) - sum(ms[arr[i]]);
		cnt+=sm;
	}
	cout<<cnt<<endl;
}