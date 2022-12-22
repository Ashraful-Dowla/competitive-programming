/*
https://codeforces.com/problemset/problem/1183/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k,n,a,b;

bool maxPossible(ll mid){
	ll valA = mid*a;
	ll valB = (n-mid)*b;

	return (valA+valB)<k;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>k>>n>>a>>b;
		ll lo=0,hi=n,mx=-1;
		while(hi-lo>0){
			ll mid = (hi+lo)/2;
			if(maxPossible(mid)) {
				lo=mid+1;
				mx = max(mx,mid);
			}
			else hi=mid;
		}

		ll mid = (hi+lo)/2;
		if(maxPossible(mid)){
			mx = max(mx,mid);
		}
		cout<<mx<<endl;
	}
}