/*
https://codeforces.com/contest/1740/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    ll sum=0,mx=0;
	    for(int i=0;i<n;++i){
	    	ll x,y;
	    	cin>>x>>y;
	    	sum+=min(x,y);
	    	mx = max(mx,max(x,y));
	    }

	    cout<<2*(sum+mx)<<endl;	
	}
}