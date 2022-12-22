/*
https://codeforces.com/contest/1740/problem/C
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
	    ll arr[n];

	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    }

	    sort(arr,arr+n);

	    ll ans=0;
	    for(int i=1;i<n-1;++i){
	    	ans = max(ans, arr[n-1]+arr[i]-2*arr[i-1]);
	    	ans = max(ans,2*arr[i+1]-arr[i]-arr[0]);
	    }
	    cout<<ans<<endl;
	}
}