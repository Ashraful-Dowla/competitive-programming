/*
https://codeforces.com/problemset/problem/1364/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n,x;
	    cin>>n>>x;
	    int arr[n+2];

	    int total=0,pf=0,sf=0,ans=-1;
	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    }

	    for(int i=0;i<n;++i){
	    	pf+=arr[i];
	    	sf+=arr[n-i-1];
	    	if(pf%x!=0 || sf%x!=0) ans=i+1;
	    }
	    cout<<ans<<endl;
	}
}