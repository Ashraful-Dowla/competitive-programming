/*
https://codeforces.com/contest/1758/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    if(n%2==1){
	    	for(int i=0;i<n;++i){
	    		cout<<1<<" ";
	    	}
	    	cout<<endl;
	    }
	    else {	
	    	cout<<1<<" ";
	    	for(int i=0;i<n-2;++i){
	    		cout<<2<<" ";
	    	}
	    	cout<<3<<endl;
	    }
	}
}