/*
https://codeforces.com/contest/1381/problem/A1
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s,t;
	    cin>>s;
	    cin>>t;

	    vector<int>ans;

	    for(int i=0;i<n;++i){
	    	if(s[i]!=t[i]){
	    		if(i>0) ans.push_back(i+1);
	    		ans.push_back(1);
	    		if(i>0) ans.push_back(i+1);
	    	}
	    }

	    cout<<ans.size()<<" ";
	    for(int val:ans){
	    	cout<<val<<" ";
	    }
	    cout<<endl;
	}
}