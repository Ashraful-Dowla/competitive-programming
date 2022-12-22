/*
https://codeforces.com/contest/1760/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    vector<ll> vec;

	    ll MAX=1e10;

	    vec.push_back(MAX);
	    for(int i=0;i<n;++i){
	    	ll x;
	    	cin>>x;
	    	if(vec.back()!=x) vec.push_back(x);
	    }
	    vec.push_back(MAX);
 
	    int cnt=0;
	    for(int i=1;i<vec.size()-1;++i){
	    	if(vec[i-1]>vec[i] && vec[i]<vec[i+1]){
	    		cnt++;
	    		i++;
	    	}
	    }
	    
	    cout<<(cnt==1 ? "YES":"NO")<<endl;
	}
}