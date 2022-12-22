/*
https://codeforces.com/problemset/problem/1698/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    int arr[n];
	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    }
	    
	    for(int i=0;i<n;++i){
	    	int res=0;
	    	for(int j=0;j<n;++j){
	    		if(i==j) continue;
	    		res^=arr[j];
	    	}
	    	if(res==arr[i]) {
	    		cout<<res<<endl;
	    		break;
	    	}
	    }
	}
}	