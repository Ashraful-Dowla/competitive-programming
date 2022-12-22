/*
https://codeforces.com/problemset/problem/1543/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    ll a,b;
	    cin>>a>>b;

	    ll gcd = abs(a-b);

	    if(gcd==0) cout<<"0 0"<<endl;
	    else {
	    	if(a%gcd==0) cout<<gcd<<" "<<0<<endl;
	    	else {
	    		ll rm_1 = a/gcd +1;
	    		rm_1 = rm_1*gcd;

	    		ll rm_2 = a/gcd;
	    		rm_2 = rm_2*gcd;
	    		cout<<gcd<<" "<<min(rm_1-a,a-rm_2)<<endl;
 	    	}
	    }
	}
}