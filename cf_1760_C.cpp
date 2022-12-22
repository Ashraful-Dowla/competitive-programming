/*
https://codeforces.com/contest/1760/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    vector<long> vec,vec2;

	    for(int i=0;i<n;++i){	
	    	long x;
	    	cin>>x;
	    	vec.push_back(x);
	    	vec2.push_back(x);
	    }

	    sort(vec2.begin(),vec2.end());
	    long mx = vec2[n-1];
	    long mx2 = vec2[n-2];

	    for(int i=0;i<n;++i){
	    	if(vec[i]==mx) cout<<vec[i]-mx2<<" ";
	    	else cout<<vec[i]-mx<<" ";
	    }
	    cout<<endl;
	}
}