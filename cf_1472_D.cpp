/*
https://codeforces.com/contest/1472/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;

	    vector<int> vec(n);

	    for(int i=0;i<n;++i){
	    	cin>>vec[i];
	    }

	    sort(vec.rbegin(), vec.rend());
	    long long ans=0;
	    for(int i=0;i<n;++i){
	    	if(i&1){
	    		if(vec[i]%2) ans-=vec[i];
	    	}
	    	else {
	    		if(vec[i]%2==0) ans+=vec[i];
	    	}
	    }

	    if(ans==0) cout<<"Tie"<<endl;
	    else if(ans>0) cout<<"Alice"<<endl;
	    else cout<<"Bob"<<endl;
	}
}