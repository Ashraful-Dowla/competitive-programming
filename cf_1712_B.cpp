/*
https://codeforces.com/contest/1712/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;

	    vector<int>res;
	    for(int i=1;i<=n;++i){
	    	res.push_back(i);
	    }

	    int idx = n%2==0 ? 0:1;

	    for(int i=idx;i<n;i+=2){
	    	swap(res[i],res[i+1]);
	    }

	    for(auto val:res){
	    	cout<<val<<" ";
	    }
	    cout<<endl;
	}
}