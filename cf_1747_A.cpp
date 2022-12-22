/*
https://codeforces.com/contest/1747/problem/A
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


	    ll sum_p=0LL,sum_n=0LL;
	    for(int i=0;i<n;++i){
	    	ll x;
	    	cin>>x;
	    	if(x>=0) sum_p+=x;
	    	else sum_n+=abs(x);
	    }

	    cout<<max(sum_p-sum_n,sum_n-sum_p)<<endl;
	}
}