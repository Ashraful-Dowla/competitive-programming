/*
https://codeforces.com/contest/1354/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;

	    vector<pair<char,int>>vec;
	    int ans=1e9;

	    for(int i=0;i<s.size();++i){
	    	if(vec.empty() || vec.back().first!=s[i]){
	    		vec.push_back({s[i],1});
	    	}
	    	else {
	    		vec.back().second++;
	    	}
	    }

	    for(int i=1;i<vec.size()-1;++i){
	    	if(vec[i-1].first!=vec[i+1].first){
	    		ans = min(ans,vec[i].second+2);
	    	}
	    }

	    if(ans>s.size()) ans=0;
	    cout<<ans<<endl;
	}
}