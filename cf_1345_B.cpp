/*
https://codeforces.com/contest/1345/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5;
ll arr[N],pf[N];

void precompute(){
	arr[1]=2;
	pf[1]=2;
	for(int i=2;i<=N;++i){
		arr[i]+=arr[i-1]+3;
		pf[i]+=pf[i-1]+arr[i];
	}
}

ll compute(int n){
	ll cnt=0;
	while(n>1){
		auto it = lower_bound(pf+1,pf+N,n);
		if(*it>n) it--;
		ll val = *it;
		ll res = n/val;
		cnt+=res;
		n-=(res*val);
	}
	return cnt;
}

int main(){	
	precompute();
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    cout<<compute(n)<<endl;
	}
}