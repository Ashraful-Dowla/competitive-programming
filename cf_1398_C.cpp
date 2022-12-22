/*
https://codeforces.com/contest/1398/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;

	    int pf[n+2];
	    pf[0]=0;
	    s='x'+s;

	    for(int i=1;i<=n;++i){
	    	pf[i]=pf[i-1] + (s[i]-'0');
	    }

	    long long cnt=0;
	    map<int,int>mp;
	    for(int i=0;i<=n;++i){
	    	int val = pf[i]-i;
	    	cnt+=mp[val];
	    	mp[val]++;	    	
	    }
	    cout<<cnt<<endl;
	}
}