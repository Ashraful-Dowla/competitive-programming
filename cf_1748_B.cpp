/*
https://codeforces.com/contest/1748/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;

	    int ans=0;
	    for(int i=0;i<n;++i){
	    	int mx=0;
	    	map<char,int> mp;
	    	for(int j=i;j<i+100 && j<n;++j){
	    		mx = max(mx, ++mp[s[j]]);
	    		if(mx<=mp.size()) ans++;
	    	}
	    }
	    cout<<ans<<endl;
	}
}