/*
https://codeforces.com/problemset/problem/1420/B
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

	    int bits[32];
	    memset(bits,0,sizeof(bits));

	    for(int i=0;i<n;++i){
	    	int x;
	    	cin>>x;
	    	int idx = log2(x);
	    	bits[idx]++;
	    }

	    ll cnt=0;
	    for(int i=0;i<32;++i){
	   		ll sum = bits[i]*1LL*(bits[i]-1);
	   		sum/=2;
	   		cnt+=sum;
	    }
	    cout<<cnt<<endl;

	}
}