/*
https://codeforces.com/contest/1747/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    cout<<(n+1)/2<<endl;
	    for(int i=0;i<(n+1)/2;++i){
	    	cout<<3*i+1<<" ";
	    	cout<<3*(n-i)<<endl;
	    }
	}
}