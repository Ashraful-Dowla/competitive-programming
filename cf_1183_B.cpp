/*
https://codeforces.com/contest/1183/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int n,k,arr[N];

bool calcB(int b){
	for(int i=0;i<n;++i){
		if(abs(arr[i]-b)>k) return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>n>>k;
	    int mn=INT_MAX,mx=0;
	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    	mx = max(mx,abs(arr[i]-k));
	    	mn = min(mn,abs(arr[i]+k));
	    }

	    bool chkmx=calcB(mx);
	    bool chkmn=calcB(mn);
	  	
	  	if(chkmx&&chkmn) cout<<max(mx,mn)<<endl;
	  	else if(chkmx) cout<<mx<<endl;
	  	else if(chkmn) cout<<mn<<endl;
	  	else cout<<-1<<endl;
	}
}