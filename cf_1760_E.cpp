/*
https://codeforces.com/contest/1760/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
int arr[N],n;

ll compute(){
	ll ct=0,sum=0;
	for(int i=n-1;i>=0;--i){
		if(arr[i]==0) ct++;
		else sum+=ct;
	}
	return sum;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>n;

	    for(int i=0;i<n;++i){
	 		cin>>arr[i]; 	
	    }

	    ll mx = compute();
	    int idx=-1;
	    for(int i=n-1;i>=0;--i){
	    	if(arr[i]==1) {
	    		idx=i;
	    		arr[i]=0;
	    		break;
	    	} 
	    }

	    mx = max(mx,compute());
	    if(idx>=0) arr[idx]=1;

	    for(int i=0;i<n;++i){
	    	if(arr[i]==0){
	    		arr[i]=1;
	    		break;
	    	}
	    }

	    mx = max(mx,compute());
	    cout<<mx<<endl;

	}
}