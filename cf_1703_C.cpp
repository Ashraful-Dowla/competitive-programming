/*
https://codeforces.com/problemset/problem/1703/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int>vec(n);
	    for(int i=0;i<n;++i){
	    	cin>>vec[i];
	    }

	    vector<int>ans;
	    for(int i=0;i<n;++i){
	    	int b;
	    	string s;
	    	cin>>b>>s;

	    	int x=vec[i];

	    	for(int j=0;j<s.size();++j){
	    		if(s[j]=='D') x++;
	    		else x--;

	    		if(x<0) x=9;
	    		if(x>9) x=0;
	    	}

	    	ans.push_back(x);
	    }

	    for(int val:ans){
	    	cout<<val<<" ";
	    }
	    cout<<endl;
	}
}