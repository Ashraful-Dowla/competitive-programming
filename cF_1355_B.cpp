/*
https://codeforces.com/contest/1355/problem/B
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

	    sort(vec.begin(),vec.end());

	    int cnt=0,ans=0;
	    for(int i=0;i<n;++i){
	    	cnt++;
	    	if(cnt==vec[i]){
	    		ans++;
	    		cnt=0;
	    	}
	    }

	    cout<<ans<<endl;

	}
}